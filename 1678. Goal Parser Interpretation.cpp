class Solution {
public:
    string interpret(string command) {
        string s = "";
        for (int i = 0, len = command.length(); i < len; ++i) {
            if (command[i] == 'G') {
                s += 'G';
            }
            else if (command[i] == '(') {
                ++i;
                if (command[i] == ')') {
                    s += 'o';
                }
                else {
                    s += "al";
                    i += 2;
                }
            }
        }
        return s;
    }
};
