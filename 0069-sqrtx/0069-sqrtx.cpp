class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long square = 1LL * mid * mid;

            if (square == x) return mid;

            if (square > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return high;
    }
};