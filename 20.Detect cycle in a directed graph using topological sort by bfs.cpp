// Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
       vector<int>indegree(v);
       for(int i=0;i<v;++i){
           for(auto j:adj[i])++indegree[j];
       }
       queue<int>q;
       // using queue because fifo ..sob theke boro ta 1st a thakbe..
       // 5 4 3 2 1 0 its a topological sort.
       // u always appear v 
       // DAG directed acyclic graph
       for(int i=0;i<v;++i){
           if(indegree[i]==0)
           q.push(i);
       }
      
       vector<int>ans;
       while(!q.empty()){
           int node = q.front();
           ans.push_back(node);
           q.pop();
           for(auto i:adj[node]){
               --indegree[i];
               if(indegree[i]==0)
               q.push(i);
           }
       }
       if(ans.size()==v) // jodi same size hoy tar mani kono cycle nai so false
       return false;
       return true;
    }