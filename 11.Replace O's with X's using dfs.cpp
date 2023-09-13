void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&mat,int rowar[],int colar[]){
    vis[r][c]=1;
    int row = mat.size();
    int col = mat[0].size();
    for(int i=0;i<4;++i){
        int nrow = r+rowar[i];
        int ncol = c+colar[i];
        if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && vis[nrow][ncol]==0
        && mat[nrow][ncol]=='O'){
           dfs(nrow,ncol,vis,mat,rowar,colar);
        }
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<int>>vis(n,vector<int>(m,0));
       int rowar[]={-1,0,1,0};
    int colar[]={0,1,0,-1};
       for(int i=0;i<m;++i){
           //first row
           if(mat[0][i]=='O' && vis[0][i]==0){
               dfs(0,i,vis,mat,rowar,colar);
           }
           //last row
           if(mat[n-1][i]=='O' && vis[n-1][i]==0){
               dfs(n-1,i,vis,mat,rowar,colar);
           }
       }
       for(int i=0;i<n;++i){
           // first column
           if(mat[i][0]=='O' && vis[i][0]==0){
               dfs(i,0,vis,mat,rowar,colar);
           }
           //last column
           if(mat[i][m-1]=='O' && vis[i][m-1]==0){
               dfs(i,m-1,vis,mat,rowar,colar);
           }
       }
       for(int i=0;i<n;++i){
           for(int j=0;j<m;++j){
               if(!vis[i][j])
               mat[i][j]='X';
           }
       }
       return mat;
       
       
    }