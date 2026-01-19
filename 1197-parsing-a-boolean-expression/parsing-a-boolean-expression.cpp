class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> st;

        for (char c : e) {
            if (c == ',' || c == '(') continue;

            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st.push(c);
            }
            else if (c == ')') {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    if (st.top() == 't') hasTrue = true;
                    if (st.top() == 'f') hasFalse = true;
                    st.pop();
                }

                char op = st.top();
                st.pop();

                bool res;
                if (op == '!') res = !hasTrue;
                else if (op == '&') res = !hasFalse;
                else res = hasTrue;

                st.push(res ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};
