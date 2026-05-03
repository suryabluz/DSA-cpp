int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n+2);                            //SC:O(n)
    for(int i=0; i<n; i++){                         //TC:O(n)
        for(int w=i+1; w<=n; w++){                  //TC:O(n)    
            dp[w] = max(dp[w], A[i]+dp[w-(i+1)]);
        }
    }
    return dp[n];
}
//TC:O(n*n)
//SC:O(n)