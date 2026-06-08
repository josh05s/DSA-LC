class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int q = tokens.size();
        stack<int> updated = {};
        int a, b = 0;

        for (int i = 0; i < q; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                a = updated.top(); updated.pop();
                b = updated.top(); updated.pop();
                
                if (tokens[i] == "+") {
                    a = a + b;
                    updated.push(a);
                }

                if (tokens[i] == "-") {
                    a = b - a;
                    updated.push(a);
                }

                if (tokens[i] == "*") {
                    a = a * b;
                    updated.push(a);
                }

                if (tokens[i] == "/") {
                    a = b / a;
                    updated.push(a);
                }

            } else {
                updated.push(stoi(tokens[i]));
            }
        }
        return updated.top();
    }
};