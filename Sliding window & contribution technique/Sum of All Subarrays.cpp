long Solution::subarraySum(vector<int> &A) {
    long total;
    int n = A.size();
    long occ;
    for(int i=0; i<n; i++){
        occ = (long)(i+1)*(n-i);
        total += (long)A[i]*occ;
    }
    return total;
}
//T.C = O(n)
//S.C = O(1)