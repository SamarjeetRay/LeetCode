class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st;
        vector<int> ans;

        // nums1 ke elements set me daalo
        for(int i = 0; i < nums1.size(); i++) {
            st.insert(nums1[i]);
        }

        // nums2 ke elements check karo
        for(int i = 0; i < nums2.size(); i++) {

            if(st.find(nums2[i]) != st.end()) {

                ans.push_back(nums2[i]);

                st.erase(nums2[i]);
            }
        }

        return ans;
    }
};