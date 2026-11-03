class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        int longest = 0;

        for(unordered_set<int>::iterator it = st.begin(); it != st.end(); it++){

            int currNum = *it;

            if(!st.count(currNum - 1)){

                int currLen = 1;

                while(st.count(currNum + 1)){
                    currLen++;
                    currNum++;
                }

                longest = max(currLen, longest);
            }
        }

        return longest;
    }
};