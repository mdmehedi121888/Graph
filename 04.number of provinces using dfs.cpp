void dfs(int node,vector<int>&visited,vector<int>adj[]){
    visited[node]=1;
    for(auto i:adj[node]){
             if(!visited[i])
        dfs(i,visited,adj);
       
    }
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<int>adj[n];
    vector<int>visited(n);
    for(int i=0;i<roads.size();++i){
        for(int j=0;j<roads[i].size();++j){
            if(roads[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            ++ans;
            dfs(i,visited,adj);
        }
        
    }
    return ans;
}