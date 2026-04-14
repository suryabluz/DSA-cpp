void dfs(vector<vector<int>> &graph, int i, vector<bool> &visted){
    visted[i] = true;
    for(int nbr: graph[i]){
        if(visted[nbr]==false){
            dfs(graph, nbr, visted);
        }
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1);
    vector<bool> visted(A+1, false);
    int comp=0;
    for(int i=0; i<B.size(); i++){
        graph[B[i][0]].push_back(B[i][1]);
    }

    dfs(graph, 1, visted);
    return visted[A]?1:0;
}

//TC: O(A+B)
//SC: O(A+B)