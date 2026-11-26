class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& currentSubset, int idx,
                       vector<vector<int>>& result) {

        if (idx == nums.size()) {
            result.push_back(currentSubset);
            return;
        }

        // Pick
        currentSubset.push_back(nums[idx]);
        getAllSubsets(nums, currentSubset, idx + 1, result);

        currentSubset.pop_back();

        // Skip duplicates
        int nextIdx = idx + 1;

        while (nextIdx < nums.size() && nums[nextIdx] == nums[nextIdx - 1]) {
            nextIdx++;
        }

        // Not Pick
        getAllSubsets(nums, currentSubset, nextIdx, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> currentSubset;

        getAllSubsets(nums, currentSubset, 0, result);

        return result;
    }
};