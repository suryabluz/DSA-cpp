int Solution::seats(string A) {
    vector<int> B;
    int n=A.size();
    for(int i=0; i<n; i++){
        if(A[i]=='x' || A[i]=='X'){
            B.push_back(i);
        }
    }
    int mid = B.size()/2;
    int left = mid-1;
    int right = mid+1;
    int k=1;
    long res=0;
    int mod = 10000003;
    while(left>=0){
        long move = B[mid]-B[left]-k;
        res = (res+move)%mod;
        k++;
        left--; 
    }
    k=1;
    while(right<B.size()){
        long move = B[right]-B[mid]-k;
        res = (res+move)%mod;
        k++;
        right++;
    }
    return (int)res%mod;
}

//TC: O(n)
//SC: O(n)
