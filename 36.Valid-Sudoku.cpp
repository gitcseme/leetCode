class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows
        for (int i = 0; i < 9; ++i) {
            set<char> s;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    if (!s.count(c)) {
                        s.insert(c);
                    }
                    else {
                        return false;
                    }
                }
            }

        }
        
        // colums
        for (int i = 0; i < 9; ++i) {
            set<char> s;
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (c != '.') {
                    if (!s.count(c)) {
                        s.insert(c);
                    }
                    else {
                        return false;
                    }
                }
            }

        }
        
        // cubes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> s;
                
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        char c = board[k+i][l+j];
                        if (c != '.') {
                            if (!s.count(c)) {
                                s.insert(c);
                            }
                            else {
                                return false;
                            }
                        }
                    }
                }

            }
        }
        
        return true;
    }
};
