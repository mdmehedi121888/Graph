//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        int mx=0;
        int rowar[]={-1,0,1,0};
        int colar[]={0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            mx = max(mx,time);
            q.pop();
            for(int i=0;i<4;++i){
                int nrow = row + rowar[i];
                int ncol = col + colar[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 
                && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1)return -1;
            }
        }
        return mx;
    }
};
