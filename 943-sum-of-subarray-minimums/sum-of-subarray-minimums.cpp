
class Solution {
public:
    // Next Smaller Element on Left
    vector<int> NSL(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }

            st.push(i);
        }

        return left;
    }

    // Next Smaller Element on Right
    vector<int> RSL(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }

            st.push(i);
        }

        return right;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = NSL(arr);
        vector<int> right = RSL(arr);

        long long sum = 0;
        long long MOD = 1000000007;

        for (int i = 0; i < n; i++) {
            long long l = i - left[i];
            long long r = right[i] - i;

            long long contribution =
                (l * r % MOD) * arr[i] % MOD;

            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};
