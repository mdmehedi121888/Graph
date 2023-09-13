bool bfs(int j,vector<int>&vis,vector<int>adj[]){
     queue<int>q;
	    q.push(j);
	    vis[j]=0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        for(auto i:adj[node]){
	            if(vis[i]==-1){
	            vis[i] = !vis[node];
	            q.push(i);
	        }
	        else if(vis[i]==vis[node])
	        return false;
	        }
	        
	    }
	    return true;
}
	bool isBipartite(int v, vector<int>adj[]){
	    vector<int>vis(v,-1);

        // connected components
	   for(int i=0;i<v;++i){
	       if(vis[i]==-1){
	            if(bfs(i,vis,adj)==false) 
	            return false;
	       }
	      
	   }
	   return true;
	}
