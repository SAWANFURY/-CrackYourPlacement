//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 bool fun(string &a,string &b,int r){
        while(r>=0){
            if(a[r]!=b[r])
                return false;
            r--;
            
        }
        return true;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        sort(contact,contact+n);
        
        
        vector<vector<string>> ans;
        
        unordered_map<string,bool> chlega;
        
        for(int i=s.size()-1;i>=0;i--){
            unordered_map<string,bool> visited;
            vector<string> temp;
            for(int j=0;j<n;j++){
                if(chlega[contact[j]]==true){
                    if(!visited[contact[j]])
                        temp.push_back(contact[j]);
                    visited[contact[j]]=true;
                }
                else if(contact[j].size()>i){
                    if(fun(s,contact[j],i)){
                        if(!visited[contact[j]])
                            temp.push_back(contact[j]);
                        chlega[contact[j]]=true;
                        visited[contact[j]]=true;
                    }
                        
                }
            }
            if(temp.size()==0)
                temp.push_back("0");
            ans.push_back(temp);
            
        }
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends