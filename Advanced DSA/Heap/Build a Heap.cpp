class Solution {
    private: void swap(vector<int> &A, int x, int y){
        int temp = A[x];
        A[x] = A[y];
        A[y] = temp;
    }
    private: void downHeapify(vector<int> &A, int i){
        int n = A.size();
        while(true){
            int lc=2*i+1;
            int rc=2*i+2;
            int smallest = i;
            if(lc<n && A[smallest]>A[lc]){
                smallest=lc;
            }
            if(rc<n && A[smallest]>A[rc]){
                smallest=rc;
            }
            if(smallest==i){
                return;
            }
            swap(A, i, smallest);
            i=smallest;
        }
    }
   public:
    vector<int> buildHeap(vector<int> &A) {
        int n = A.size();
        for(int i=n/2-1; i>=0; i--){
            downHeapify(A, i);//O(log n)
        }
        return A;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(1)