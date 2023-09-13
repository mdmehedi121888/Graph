 bool dfs(int node,vector<int>&vis,vector<int>&pathvisit,vector<int> adj[])
    {
        vis[node]=1;
        pathvisit[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,pathvisit,adj))
                return true;
            }
            else if(pathvisit[i]){
                return true;
            }
        }
        pathvisit[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
       vector<int>vis(v),pathvisit(v);
       for(int i=0;i<v;++i){
           if(!vis[i]){
               dfs(i,vis,pathvisit,adj);
           }
       }
       vector<int>ans;
       for(int i=0;i<v;++i)if(pathvisit[i]==0)ans.push_back(i);
       return ans;
    }