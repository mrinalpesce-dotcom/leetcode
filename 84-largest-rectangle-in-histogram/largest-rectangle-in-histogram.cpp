
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        vector<int> left(n);
        vector<int> right(n);

        // Find Next Smaller Element on Right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear stack before finding left boundaries
        while (!st.empty()) {
            st.pop();
        }

        // Find Previous Smaller Element on Left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int maxArea = 0;

        // Calculate the maximum rectangle area
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
