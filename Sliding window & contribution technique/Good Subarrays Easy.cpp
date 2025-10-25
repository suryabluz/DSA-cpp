void prefixSum(vector<int> &A){
    int n = A.size();
    for(int i=1; i<n; i++){
        A[i] = A[i]+A[i-1];
    }
}

int Solution::solve(vector<int> &A, int B) {
    prefixSum(A);
    int n = A.size();
    int count=0;
    int sum=0;
    for(int s=0; s<n; s++){
        for(int e=s; e<n; e++){
            if(sum==0){
                sum = A[e];
            }
            else{
                sum = A[e]-A[s-1];
            }
            if((e-s+1)%2==0 && (sum<B)){
                count++;
            }
            if((e-s+1)%2!=0 && (sum>B)) {
                count++;
            }
        }
    }
    return count;
}
