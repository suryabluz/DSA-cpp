long Solution::solve(string A) {
    int n = A.size();
    long countG = 0;
    long res;
    for(int i=n-1; i>=0; i--){
        if(A[i]=='G'){
            countG++;
        }
        if(A[i]=='A'){
            res+=countG;
        }
    }
    return res;
}
