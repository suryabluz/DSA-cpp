vector<int> Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<int> res;
    int sum=0;
    for(int j=0; j<m; j++){
        sum=0;
        for(int i=0; i<n; i++){
            sum += A[i][j];
        }
        res.push_back(sum);
    }
    return res;
}
