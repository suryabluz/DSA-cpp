int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int n=B.size();
    vector<int> dp(A+1);                                        //SC:O(A)
    for(int i=0; i<n; i++){ //forward for unbound knapsack      //TC:O(n)
        for(int w=C[i]; w<=A; w++){                             //TC:O(A)
            dp[w] = max(dp[w], B[i]+dp[w-C[i]]);
        }
    }
    return dp[A];
}

//TC:O(n*A)
//TC:O(A)