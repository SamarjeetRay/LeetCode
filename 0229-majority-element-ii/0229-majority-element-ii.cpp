class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int ele1 = 0, ele2 = 0;

        // Step 1: Find possible candidates
        for (int i = 0; i < nums.size(); i++) {

            if (count1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                count2 = 1;
            }
            else if (nums[i] == ele1) {
                count1++;
            }
            else if (nums[i] == ele2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == ele1) count1++;
            else if (num == ele2) count2++;
        }

        vector<int> ans;

        if (count1 > nums.size() / 3)
            ans.push_back(ele1);

        if (count2 > nums.size() / 3)
            ans.push_back(ele2);

        return ans;
    }
};