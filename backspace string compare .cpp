class Solution {
public:
stack<char> st;
stack<char> st1;
    bool backspaceCompare(string s, string t) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!st1.empty()) st1.pop();
            } 
            else st1.push(t[i]);
        }
        return st==st1;
    }
};