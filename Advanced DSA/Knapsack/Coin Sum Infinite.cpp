int Solution::coinchange2(vector<int> &A, int B) {
    int n=A.size();
    vector<long long> dp(B+1);                    //SC:O(B)
    int mod = 1000007;
    dp[0] = 1;
    for(int i=0; i<n; i++){                 //TC:O(n)
        for(int j=A[i]; j<=B; j++){         //TC:O(B)
            dp[j] = (dp[j] + dp[j-A[i]])%mod;       
        }
    }
    return (int)dp[B];
}
//TC:O(n*B)
//TC:O(B)
