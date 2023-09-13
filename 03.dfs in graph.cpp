
class Solution {
  public:
  void dfs(int node,vector<int>&ans,vector<int>&visited,vector<int> adj[]){
      visited[node]=1;
      ans.push_back(node);
      for(auto i:adj[node]){
          if(!visited[i])
          dfs(i,ans,visited,adj);
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int>visited(v),ans;
        dfs(0,ans,visited,adj);
        return ans;
    }
};