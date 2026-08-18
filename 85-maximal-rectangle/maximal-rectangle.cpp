class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size(), best = 0;
        vector<int> heights(n, 0);

        for (const auto& row : matrix) {
            for (int j = 0; j < n; ++j)
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            best = max(best, largestRectangleArea(heights));
        }
        return best;
    }

private:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), best = 0;
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            int cur = (i == n) ? 0 : h[i];
            while (!st.empty() && h[st.top()] >= cur) {
                int height = h[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                best = max(best, height * (i - left - 1));
            }
            st.push(i);
        }
        return best;
    }
};