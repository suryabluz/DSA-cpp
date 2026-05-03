int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<int> dp(C+1);                            //SC:O(C)
    for(int i=0; i<n; i++){                         //TC:O(n)
        for(int w=C; w>=B[i]; w--){                 //TC:O(C)
            dp[w] = max(dp[w], A[i]+dp[w-B[i]]);    
        }
    }
    return dp[C];
}
//TC:O(n*C)
//SC:O(C)