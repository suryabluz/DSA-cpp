int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A[0].size();
    int n = A.size();
    vector<vector<int>> dp(2, vector<int>(m,0));                       //SC:O(m)
    dp[0][0] = (A[0][0]==1) ? 0 : 1;
    //first row
    for(int i=1; i<m; i++){
        if(A[0][i]==1){
            dp[0][i] = 0;
        }else{
            dp[0][i] = dp[0][i-1];
        }
    }
    for(int i=1; i<n; i++){                     //TC:O(n)
        //first column
        dp[1][0] = (A[i][0]==1) ? 0 : dp[0][0];

        for(int j=1; j<m; j++){                 //TC:O(m)
            if(A[i][j]==1){
                dp[1][j] = 0;
            }else{
                dp[1][j] = dp[0][j]+dp[1][j-1];
            }
        }
        dp[0] = dp[1];
    }
    return dp[0][m-1];
}
//TC:O(n*m)
//SC:O(m)