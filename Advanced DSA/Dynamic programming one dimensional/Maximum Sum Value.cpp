int Solution::solve(vector<int> &A, int B, int C, int D) {
    int n = A.size();
    int total =0;
    vector<int> dp1(n);                         //SC:O(n)
    vector<int> dp2(n);                         //SC:O(n)
    vector<int> dp3(n);                         //SC:O(n)
    dp1[0] = A[0]*B;
    dp2[0] = dp1[0]+A[0]*C;
    dp3[0] = dp2[0]+A[0]*D;
    for(int i=1; i<n; i++){                     //TC:O(n)
        dp1[i] = max(dp1[i-1], A[i]*B);
        dp2[i] = max(dp2[i-1], dp1[i]+A[i]*C);
        dp3[i] = max(dp3[i-1], dp2[i]+A[i]*D);
    }
    return dp3[n-1];
}

//TC:O(n)
//SC:O(n)