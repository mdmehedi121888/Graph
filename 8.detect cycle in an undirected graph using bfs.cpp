//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool bfs(int node,vector<int>&vis,vector<int>adj[]){
      vis[node]=1;
      queue<pair<int,int>>q;
      q.push({node,-1});
      while(!q.empty()){
          int node1 = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto i:adj[node1]){
              if(!vis[i]){
                  q.push({i,node1});
                  vis[i]=1;
              }
              else{
                  if(parent != i)
                  {
                      return true;
                  }
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<int>vis(v);
        for(int i=0;i<v;++i){
            if(!vis[i]){
               if( bfs(i,vis,adj))
               return true;
            }
        }
        return false;
    }
};
