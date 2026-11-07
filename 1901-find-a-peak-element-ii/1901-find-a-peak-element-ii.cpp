class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0;
        int right = cols - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // Find maximum element in middle column
            int maxRow = 0;

            for(int i = 0; i < rows; i++) {
                if(mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Check left and right neighbours
            int current = mat[maxRow][mid];

            int leftValue = -1;
            int rightValue = -1;

            if(mid > 0) {
                leftValue = mat[maxRow][mid - 1];
            }

            if(mid < cols - 1) {
                rightValue = mat[maxRow][mid + 1];
            }

            // Peak found
            if(current > leftValue && current > rightValue) {
                return {maxRow, mid};
            }

            // Move left
            else if(leftValue > current) {
                right = mid - 1;
            }

            // Move right
            else {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};