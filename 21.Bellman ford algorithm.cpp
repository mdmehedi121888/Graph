vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int>dis(N,100000000);
        dis[0]=0;
        for(int i=0;i<N-1;++i){
            for(int j=0;j<M;++j){
                if(dis[edges[j][0]]+edges[j][2] < dis[edges[j][1]])
                dis[edges[j][1]] = dis[edges[j][0]]+edges[j][2];
            }
        }
        
        for(int i=0;i<N;++i){
            if(dis[i]==100000000)
            dis[i]=-1;
        }
        return dis;