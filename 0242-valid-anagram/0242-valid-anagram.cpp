class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);

        // s ke characters count karo
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        // t ke characters subtract karo
        for (int i = 0; i < t.length(); i++) {
            count[t[i] - 'a']--;
        }

        // Check karo sab 0 hain
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};