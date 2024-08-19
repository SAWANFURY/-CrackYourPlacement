class Solution {
public:
   void dfs(vector<vector<int>>&image,int sr,int sc,int color,int newColor){
    int n = image.size();
    int m = image[0].size();
    if(sr<0 || sr>=n || sc<0 || sc>=m || image[sr][sc]!=newColor){
        return;
    }
    image[sr][sc] = color;
    dfs(image,sr+1,sc,color,newColor);
    dfs(image,sr-1,sc,color,newColor);
    dfs(image,sr,sc+1,color,newColor);
    dfs(image,sr,sc-1,color,newColor);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int newcolor = image[sr][sc];
        if(newcolor != color){
        dfs(image,sr,sc,color,newcolor);}
        return image;
    }
};