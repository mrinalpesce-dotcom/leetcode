class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {

            bool alive = true;

            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                if(st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                else if(st.top() == abs(asteroids[i])) {
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }

            if(alive) {
                st.push(asteroids[i]);
            }
        }

        vector<int> ans(st.size());

        int i = st.size() - 1;

        while(!st.empty()) {
            ans[i] = st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};