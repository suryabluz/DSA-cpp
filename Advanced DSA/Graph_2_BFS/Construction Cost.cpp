struct Pair{
    int v;
    int w;
    Pair(int x, int y){
        v=x;
        w=y;
    }
};

struct comp{
    bool operator()(Pair a, Pair b){
        return a.w>b.w; // min heap based on w
    }
};
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<Pair>> graph(A+1);    //SC: O(E)
    vector<bool> visited(A+1, false);   //SC: O(A)
    priority_queue<Pair, vector<Pair>, comp> pq; //SC: O(E)
    int mod = 1000000007;
    long ans=0;
    for(int i=0; i<B.size(); i++){      //O(n)
        int idx = B[i][0];
        int v = B[i][1];
        int w = B[i][2];
        graph[idx].push_back(Pair(v,w));
        idx = B[i][1];
        v = B[i][0];
        graph[idx].push_back(Pair(v,w));
    }
    visited[1]=true;
    for(Pair el: graph[1]){ //TC: O(E)
        pq.push(el);
    }
    while(!pq.empty()){ //TC: O(E)
        Pair p = pq.top();
        pq.pop();               //TC:O(logE) one push/pop logE
        if(visited[p.v]==true){
            continue;
        }
        visited[p.v]=true;
        ans = (ans+(long)p.w)%mod;
        for(Pair nbr: graph[p.v]){
            if(visited[nbr.v]==false){
                pq.push(nbr); //TC:O(logE)
            }
        }
    }
    return (int)ans%mod;
}

//TC:O(ElogE)
//SC:O(A+E)