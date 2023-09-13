 bool dfs(int node,vector<int>&vis,vector<int>&pathvisit,vector<int>adj[]){
        vis[node]=1;
        pathvisit[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,pathvisit,adj)==true) return true;
            }
            else if(pathvisit[i]) return true;
        }
        pathvisit[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int>vis(v,0),pathvisit(v,0);
        // multiple component
        for(int i=0;i<v;++i){
            if(!vis[i])
            if(dfs(i,vis,pathvisit,adj)==true) return true;
        }
        return false;
    }