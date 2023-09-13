 void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>& grid,int row,
  int col, vector<pair<int,int>>&v){
      vis[r][c]=1;
      v.push_back({r-row,c-col});
      int n = grid.size();
      int m = grid[0].size();
      int rowar[]={-1,0,1,0};
      int colar[]={0,-1,0,1};
      for(int i=0;i<4;++i){
          int nrow = r + rowar[i];
          int ncol = c + colar[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
          grid[nrow][ncol]==1){
              dfs(nrow,ncol,vis,grid,row,col,v);
          }
      }
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                vector<pair<int,int>>v;
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,vis,grid,i,j,v);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }