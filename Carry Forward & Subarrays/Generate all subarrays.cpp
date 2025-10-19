vector<vector<int> > Solution::solve(vector<int> &A) {
    vector<vector<int>> res;
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            vector<int> row;
            for(int k=i; k<=j; k++){
                row.push_back(A[k]);
            }
            res.emplace_back(row);
        }
    }
    return res;
}
//T.C = n^3
//S.C = n^3