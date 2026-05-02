int Solution::numTrees(int A) {
    //catalan numbers
    vector<int> dp(A+1);                //TC:O(A)
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=A; i++){            //TC:O(A)
        for(int j=0; j<i; j++){         //TC:O(A)    
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[A];
}
//TC:O(A*A)
//SC:O(A)

