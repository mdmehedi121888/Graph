	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	   int n = grid.size();
	   int m = grid[0].size();
	   vector<vector<int>>vis(n,vector<int>(m,0));
	   vector<vector<int>>dis(n,vector<int>(m,0));
	   queue<pair<pair<int,int>,int>>q;
	   for(int i=0;i<n;++i){
	       for(int j=0;j<m;++j){
	           if(grid[i][j]==1)
	           {
	               q.push({{i,j},0});
	               vis[i][j]=1;

	           }
	       }
	   }
	   
	   int rowar[]={-1,0,1,0};
	   int colar[]={0,1,0,-1};
	   while(!q.empty()){
	       int row = q.front().first.first;
	       int col = q.front().first.second;
	       int steps = q.front().second;
	        dis[row][col]=steps;
	        vis[row][col]=1;
	        q.pop();
	        for(int i=0;i<4;++i){
	            int nrow = row + rowar[i];
	            int ncol = col + colar[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
	            {
	                q.push({{nrow,ncol},steps+1});
	                vis[nrow][ncol]=1;
	              
	            }
	        }
	   }
	   return dis;
	}