void dfs(vector<vector<int>> &graph, int i, vector<bool> &visited){
    visited[i]=true;
    for(auto nbr: graph[i]){
        if(visited[nbr]==false){
            dfs(graph, nbr, visited);
        }
    }
}
int Solution::solve(vector<int> &A, const int B, const int C) {
    int n = A.size();
    vector<vector<int>> graph(n+1); //SC:O(A+E)
    vector<bool> visited(n+1, false); //SC:O(A)
    for(int i=1; i<n; i++){ //O(n)
        graph[A[i]].push_back(i+1);
    }
    dfs(graph, C, visited); //O(E)
    if(visited[C]==true && visited[B]==true){
        return 1;
    }
    return 0;
}

// TC: O(A+E)
// SC: O(A+E)