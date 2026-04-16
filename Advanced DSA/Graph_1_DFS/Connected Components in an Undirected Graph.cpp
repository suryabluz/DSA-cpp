void dfs(vector<vector<int>> &graph, int i, vector<bool> &visited, vector<int> &comp){
    visited[i] = true;
    comp.push_back(i);
    for(int nbr: graph[i]){
        if(visited[nbr]==false){
            dfs(graph, nbr, visited, comp);
        }
    }
}
vector<vector<int> > Solution::getComponents(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A);
    vector<bool> visited(A, false);
    vector<vector<int>> result;
    for(vector<int> el: B){
        graph[el[0]].push_back(el[1]);
        graph[el[1]].push_back(el[0]);//required for undirected
    }
    for(int i=0; i<A; i++){
        if(visited[i]==false){
            vector<int> comp;
            dfs(graph, i, visited, comp);
            std::sort(comp.begin(), comp.end());
            result.push_back(comp);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}
//TC:O(A + E + A log A) //AlogA for worst case.
//SC:O(A + E)