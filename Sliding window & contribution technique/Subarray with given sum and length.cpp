int Solution::solve(vector<int> &A, int B, int C) {
    int sum=0;
    for(int i=0; i<B; i++){
        sum += A[i];
    }
    int s=1;
    int e=B;
    int n = A.size();
    if(sum==C){
        return 1;
        }
    while(e<n){
        sum = sum - A[s-1] + A[e];
        if(sum == C){
            return 1;
        }
        s++;
        e++;
    }
    return 0;
}
