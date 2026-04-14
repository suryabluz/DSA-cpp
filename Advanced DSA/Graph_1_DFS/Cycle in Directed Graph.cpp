int dfs(vector<vector<int>> &graph, int i, vector<bool> &visited, vector<bool> &path){
    visited[i] = true;
    path[i] = true;
    for(auto nbr: graph[i]){
        if(path[nbr] == true){
            return 1;
        }
        if(visited[nbr]==false){
            if(dfs(graph, nbr, visited, path)==1){
                return 1;
            }
        }
    }
    path[i]=false;
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1);
    for(int i=0; i<B.size(); i++){
        graph[B[i][0]].push_back(B[i][1]); 
    }
    vector<bool> visited(A+1, false);
    vector<bool> path(A+1, false);
    for(int i=1; i<=A; i++){
        if(visited[i]==false){
            if(dfs(graph, i, visited, path)==1){
                return 1;
            }
        }
    }
    return 0;
}

//TC: O(A+B)
//SC: O(A+B)