class Solution {
public:
    vector<int> previousSmallestElement(vector<int>& heights) {
        int n = heights.size();
        stack<int> s; // Stores INDICES
        vector<int> pse(n, -1); // Default to -1

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (!s.empty()) {
                pse[i] = s.top();
            }

            s.push(i);
        }

        return pse;
    }

    vector<int> nextSmallestElement(vector<int>& heights) {
        int n = heights.size();
        stack<int> s; // Stores INDICES
        vector<int> nse(n, n); // Default to n

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> PSE = previousSmallestElement(heights);
        vector<int> NSE = nextSmallestElement(heights);
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int width = NSE[i] - PSE[i] - 1;
            int area = heights[i] * width;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};