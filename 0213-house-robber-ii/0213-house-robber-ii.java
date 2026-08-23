class Solution {
    public int rob(int[] arr) {
        int n = arr.length;

        if(n == 1) return arr[0];
        if(n == 2) return Math.max(arr[0], arr[1]);

        int[] dp1 = new int[n];
        int[] dp2 = new int[n];

        // First included, last excluded
        dp1[0] = arr[0];
        dp1[1] = Math.max(arr[0], arr[1]);

        for(int i = 2; i < n - 1; i++) {
            dp1[i] = Math.max(arr[i] + dp1[i - 2], dp1[i - 1]);
        }

        // First excluded, last included
        dp2[1] = arr[1];
        dp2[2] = Math.max(arr[1], arr[2]);

        for(int i = 3; i < n; i++) {
            dp2[i] = Math.max(arr[i] + dp2[i - 2], dp2[i - 1]);
        }

        return Math.max(dp1[n - 2], dp2[n - 1]);
    }
}