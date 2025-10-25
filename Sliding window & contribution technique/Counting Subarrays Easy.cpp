void prefixSum(vector<int> &A, int n){
    for(int i=1; i<n; i++){
        A[i] = A[i]+A[i-1];
    }
}

int Solution::solve(vector<int> &A, int B) {
    int n =A.size();
    prefixSum(A, n);
    int sum=0;
    int count=0;
    for(int s=0; s<n; s++){
        for(int e=s; e<n; e++){
            if(s==0){
                sum = A[e];
            }
            else{
                sum = A[e] - A[s-1];
            }
            if(sum<B){
                count++;
            }
        }
    }
    return count;
}
