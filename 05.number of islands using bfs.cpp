
  void bfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>grid){
      queue<pair<int,int>>q;
      vis[r][c]=1;
      int n = grid.size();
      int m = grid[0].size();
      q.push({r,c});
      while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
          for(int i=-1;i<=1;++i){
              for(int j=-1;j<=1;++j){
                  int nrow = row + i;
                  int ncol = col + j;
                  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && 
                  !vis[nrow][ncol]){
                      vis[nrow][ncol]=1;
                      q.push({nrow,ncol});
                  }
              }
          }
      }
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        int cnt=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ++cnt;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
