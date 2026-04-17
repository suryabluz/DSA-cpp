#include <queue>
class Pair{
    public:
    int v;
    int w;
};
struct cmp{
    bool operator()(Pair a, Pair b){
        return a.w > b.w;//min heap based on value w
    }
};
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<Pair>> graph(A+1);
    vector<bool> visited(A+1, false);
    int ans=0;
    for(auto el: B){
        Pair p;
        p.v = el[1];
        p.w = el[2];
        graph[el[0]].push_back(p);
        //setting value for undirected graph
        p.v = el[0];
        graph[el[1]].push_back(p);
    }
    priority_queue<Pair, vector<Pair>, cmp> pq;
    visited[1] = true;
    for(Pair p: graph[1]){
        pq.push(p);
    }
    while(!pq.empty()){
        Pair p = pq.top();
        pq.pop();
        if(visited[p.v]==true){
            continue;
        }
        ans+=p.w;
        visited[p.v] = true;
        for(Pair p: graph[p.v]){
            if(visited[p.v]==false){
                pq.push(p);
            }
        }
    }
//check all nodes are connected
for(int i=1; i<=A; i++){
    if(visited[i]==false){
        return -1;
    }
}
return ans;
}
