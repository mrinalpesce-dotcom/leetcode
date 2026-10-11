
class Solution {
public:
    // Next Smaller Element on Left
    vector<int> NSL(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // Next Smaller Element on Right
    vector<int> NSR(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] > a[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    // Next Greater Element on Left
    vector<int> NGL(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] <= a[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // Next Greater Element on Right
    vector<int> NGR(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] < a[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nsl = NSL(nums);
        vector<int> nsr = NSR(nums);
        vector<int> ngl = NGL(nums);
        vector<int> ngr = NGR(nums);

        long long mini = 0, maxi = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;
            mini += 1LL * nums[i] * left * right;

            left = i - ngl[i];
            right = ngr[i] - i;
            maxi += 1LL * nums[i] * left * right;
        }

        return maxi - mini;
    }
};
