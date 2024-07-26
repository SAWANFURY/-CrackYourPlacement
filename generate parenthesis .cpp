class Solution {
public:
    void generate(int n,int i,int j,string s,vector<string>&ans){
        if(s.length()==n*2){
         ans.push_back(s);
         return ;
        }
        if(i<n){
            generate(n,i+1,j,s+"(",ans);
        }
        if(j<i){
            generate(n,i,j+1,s+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n,0,0,"",result);
        return result;
    }
};