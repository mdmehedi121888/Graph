bool dfs(int node,int val,vector<int>&vis,vector<int>adj[]){
        vis[node]=val;
        
        for(auto i:adj[node]){
            if(vis[i]==-1){
               if(dfs(i,!val,vis,adj)==false) return false;
            }
            else if(vis[i]==val)
            return false;
        }
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	  vector<int>vis(v,-1);
	  for(int i=0;i<v;++i){
	      if(vis[i]==-1){
	          if(dfs(i,0,vis,adj)==false)
	           return false;
	      }
	      
	  }
	  return true;
	}
