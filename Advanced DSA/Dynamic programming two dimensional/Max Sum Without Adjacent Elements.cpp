int sumAdj(vector<int> &A, int end, vector<int> &dp){
    if(end==0){
        dp[end] = A[end];
        return dp[end];
    }
    if(dp[end]!=-1){
        return dp[end];
    }
    int pick = A[end] + sumAdj(A, end-2, dp);
    int dontPick = sumAdj(A, end-1, dp);
    dp[end] = max(pick, dontPick);
    return dp[end];
}
int Solution::adjacent(vector<vector<int> > &A) {
    int ans = 0;
        int n=A[0].size();
        vector<int> dp(n+1, -1);                //TC:O(A) //SC:O(A)
        vector<int> arr(n);
        for(int i=0; i<n; i++){                 //TC:O(n)
            arr[i] = max(A[0][i], A[1][i]); 
        }
        return sumAdj(arr, n-1, dp);
}
//TC:O(n)
//SC:O(n)