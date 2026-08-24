class Solution {

    public int uniquePaths(int m, int n) {

        int[][] dp = new int[m][n];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(m - 1, n - 1, dp);
    }

    public int solve(int i, int j, int[][] dp) {

        // first row / first column
        if (i == 0 || j == 0) {
            return 1;
        }

        // already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // calculate + store
        return dp[i][j] =
            solve(i - 1, j, dp) +
            solve(i, j - 1, dp);
    }
}