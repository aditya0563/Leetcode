class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                k = 0;
                currentString = "";
            } else if (c == ']') {
                int currentK = countStack.top();
                countStack.pop();
                
                string decodedString = stringStack.top();
                stringStack.pop();
                
                for (int i = 0; i < currentK; ++i) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            } else {
                currentString += c;
            }
        }
        
        return currentString;
    }
};