int Solution::mice(vector<int> &A, vector<int> &B) {
    int n = A.size();
    sort(A.begin(), A.end());               //TC:O(nlogn)
    sort(B.begin(), B.end());               //TC:O(nlogn)
    int ans=0;
    for(int i=0; i<n; i++){                 //TC:O(n)
        int diff = abs(A[i] - B[i]);
        ans = max(ans, diff);
    }
    return ans;
}
//TC:O(nlogn)
//SC:O(1)