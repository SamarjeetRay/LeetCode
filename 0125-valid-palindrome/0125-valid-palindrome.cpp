class Solution {
public:
    bool isPalindrome(string s) {

        string clean = "";

        // Remove unwanted characters
        for (int i = 0; i < s.length(); i++) {

            if (isalnum(s[i])) {
                clean += tolower(s[i]);
            }
        }

        // Create reverse
        string reversed = clean;
        reverse(reversed.begin(), reversed.end());

        // Compare
        return clean == reversed;
    }
};