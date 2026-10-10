
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        int MOD = 1000000007;

        stack<int> st;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || arr[st.top()] > arr[i])) {

                int mid = st.top();
                st.pop();

                int left;

                if (st.empty()) {
                    left = -1;
                } else {
                    left = st.top();
                }

                int right = i;

                long long L = mid - left;
                long long R = right - mid;

                ans = (ans + arr[mid] * L % MOD * R % MOD) % MOD;
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};
  