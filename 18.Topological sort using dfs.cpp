void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&s){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(!vis[i])
	        {
	            dfs(i,vis,adj,s);
	        }
	    }
	    s.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int>vis(v);
	    stack<int>s;
		// using stack because lifo .
		// dfs use kora hoise so last pojonto jabe then backtracing er somoy
		//value store korbe
       // 5 4 3 2 1 0 its a topological sort.
       // u always appear v 
       // DAG directed acyclic graph
	    for(int i=0;i<v;++i){
	        if(!vis[i]){
	            dfs(i,vis,adj,s);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}