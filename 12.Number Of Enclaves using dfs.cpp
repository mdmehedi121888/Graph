void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>> &grid){
      vis[r][c]=1;
      int n = grid.size();
      int m = grid[0].size();
     int rowar[]={-1,0,1,0};
     int colar[]={0,1,0,-1};
     for(int i=0;i<4;++i){
         int nrow = r+rowar[i];
         int ncol = c+colar[i];
         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 &&
         grid[nrow][ncol]==1)
         dfs(nrow,ncol,vis,grid);
     }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;++i){
            // first row
            if(grid[0][i]==1 && vis[0][i]==0)
            dfs(0,i,vis,grid);
            //last row
            if(grid[n-1][i]==1 && vis[n-1][i]==0)
            dfs(n-1,i,vis,grid);
        }
        for(int i=0;i<n;++i){
            // first column
            if(grid[i][0]==1 && vis[i][0]==0)
            dfs(i,0,vis,grid);
            // last coulumn
            if(grid[i][m-1]==1 && vis[i][m-1]==0)
            dfs(i,m-1,vis,grid);
        }
        
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0 && grid[i][j]==1)++ans;
            }
        }
        return ans;
    }