
class Solution {
public:
    bool findWord(vector<vector<char>>& board, string word, int i, int j, int idx) {
        
        // Word found
        if(idx == word.size()) {
            return true;
        }

        // Boundary and character check
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
           board[i][j] != word[idx]) {
            return false;
        }

        // Store current character
        char ch = board[i][j];

        // Mark visited
        board[i][j] = '#';

        // Explore all four directions
        bool found = findWord(board, word, i+1, j, idx+1) ||
                     findWord(board, word, i-1, j, idx+1) ||
                     findWord(board, word, i, j+1, idx+1) ||
                     findWord(board, word, i, j-1, idx+1);

        // Backtrack
        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(board[i][j] == word[0]) {
                    if(findWord(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
