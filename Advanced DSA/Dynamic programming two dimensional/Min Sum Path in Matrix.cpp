int Solution::minPathSum(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));          //SC:O(n*m)
    //first row
    dp[0][0] = A[0][0];
    for(int j=1; j<m; j++){                                 //TC:O(m)
        dp[0][j] = dp[0][j-1]+A[0][j];
    }   
    for(int i=1; i<n; i++){                                 //TC:O(n)
        for(int j=0; j<m; j++){                             //TC:O(m)
            if(j==0){
                dp[i][0] = dp[i-1][0]+A[i][0];
            }else{
                int minVal = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = minVal+A[i][j];
            }
        }
    }
    return dp[n-1][m-1];
}

//TC:O(n*m)
//SC:O(n*m)
