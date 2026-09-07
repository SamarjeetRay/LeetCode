class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];

            if(prefixSum == k){
                count++;
            }

            if(mp.find(prefixSum - k) != mp.end()){
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};