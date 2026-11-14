class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int sum = 0;
        int count = 0;
        int leadingZeros = 0;

        for(int j = 0; j < n; j++) {

            // Odd = 1, Even = 0
            sum += nums[j] % 2;

            while(i <= j && sum > k) {
                sum -= nums[i] % 2;
                i++;
                leadingZeros = 0;
            }

            // Count removable leading even numbers
            while(i < j && nums[i] % 2 == 0) {
                leadingZeros++;
                i++;
            }

            // Exactly k odd numbers
            if(i <= j && sum == k) {
                count += leadingZeros + 1;
            }
        }

        return count;
    }
};