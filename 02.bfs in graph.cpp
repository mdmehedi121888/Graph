vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int>ans,visited(n+1);
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        if(visited[node]==0){
            ans.push_back(node);
            for(auto i:adj[node])
            q.push(i);
            visited[node]=1;
        }
        q.pop();
    }
    return ans;
}