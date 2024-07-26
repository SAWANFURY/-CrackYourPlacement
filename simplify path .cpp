class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        stack<string> st;
        string ans = "";
        
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (ans == "..") {
                    if (!st.empty()) st.pop();
                } else if (!ans.empty() && ans != ".") {
                    st.push(ans);
                }
                ans = "";
            } else {
                ans.push_back(path[i]);
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        
        return result.empty() ? "/" : result;
    }
};
