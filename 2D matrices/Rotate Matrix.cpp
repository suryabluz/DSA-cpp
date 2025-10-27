void swap2D(vector<vector<int>> &A, int i, int j){
    int temp = A[i][j];
    A[i][j] = A[j][i];
    A[j][i] = temp;
}
void swap1D(vector<int> &A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
void reverse(vector<int> &A, int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap1D(A, s, e);
        s++;
        e--;
    } 
}

void Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    //transpose
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap2D(A, i, j);
        }
    }
    //reverse
    for(int i=0; i<n; i++){
        reverse(A[i], n);
    }
}
