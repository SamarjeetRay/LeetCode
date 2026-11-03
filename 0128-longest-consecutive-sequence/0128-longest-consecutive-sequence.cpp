class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int longest = 0;

        for (auto it = st.begin(); it != st.end(); it++) {

            int num = *it;

            // Check starting point
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int count = 1;

                for (; st.find(current + 1) != st.end(); ) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};