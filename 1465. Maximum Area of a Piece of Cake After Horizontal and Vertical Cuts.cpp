class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int rows = horizontalCuts.size();
        int cols = verticalCuts.size();
        long maxHeight = max((int)horizontalCuts[0], h - horizontalCuts[rows - 1]);
        for(int i = 1; i < rows; ++i) {
            maxHeight = max((int)maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        long maxWidth = max((int)verticalCuts[0], w - verticalCuts[cols - 1]);
        for(int i = 1; i < cols; ++i) {
            maxWidth = max((int)maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        }
        int result = (int)((maxHeight*maxWidth)%1000000007);
        return result;
    }
};
