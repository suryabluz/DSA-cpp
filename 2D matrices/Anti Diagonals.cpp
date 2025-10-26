vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> res(2*n-1, vector<int>(n,0));
    for(int k=0; k<n; k++){
        int i=0;
        int j=k;
        while(i<=k && j>=0){
            res[k][i] = A[i][j];
            i++;
            j--;
        }
    }
    for(int k=1; k<n; k++){
        int lowCol=0;
        int i=k;
        int j=n-1;
        while(i<n && j>0){
            res[i+j][lowCol] = A[i][j];
            i++;
            j--;
            lowCol++;
        }
    }
    return res;
}
