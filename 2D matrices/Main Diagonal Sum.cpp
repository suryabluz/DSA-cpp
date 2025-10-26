int Solution::solve(const vector<vector<int> > &A) {
    int i=0;
    int n = A.size();
    int sum =0;
    while(i<n){
        sum+=A[i][i];
        i++;
    }
    return sum;
}
