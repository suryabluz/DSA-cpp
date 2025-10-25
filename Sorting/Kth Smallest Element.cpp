void swapElement(vector<int> &arr, int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int Solution::kthsmallest(const vector<int> &A, int B) {
    int n=A.size();
    int min_Idx=0;
    vector<int> arr = A;
    for(int i=0; i<B; i++){
        min_Idx = i;
        for(int j=i; j<n; j++){
            if(arr[min_Idx]>arr[j]){
                min_Idx = j;
            }
        }
        swapElement(arr, i, min_Idx);
    }
    return arr[B-1];
}
