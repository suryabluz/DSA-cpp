void swap(vector<int> &heap, int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}
void downHeapify(vector<int> &heap, int i){
    int n=heap.size();
    while(true){
        int lc=2*i+1;
        int rc=2*i+2;
        int smallest = i;
        if(lc<n && heap[smallest]>heap[lc]){
            smallest = lc;
        }
        if(rc<n && heap[smallest]>heap[rc]){
            smallest = rc;
        }
        if(smallest==i){
            break;
        }
        swap(heap, i, smallest);
        i = smallest;
    }
}

void upHeapify(vector<int> &heap){
    int i = heap.size()-1;
    while(i>0){
        int pi=(i-1)/2;
        if(heap[pi]>heap[i]){
            swap(heap, i, pi);
            i=pi;
        }
        else{
            break;
        }
    }
}

int extractMinHeap(vector<int> &heap){
    if(heap.empty()){
        return -1;
    }
    int min = heap[0];
    swap(heap, 0, heap.size()-1);
    heap.pop_back();
    if(heap.empty()){
        return min;
    }
    downHeapify(heap, 0);
    return min;
}
void insertHeap(vector<int> &heap, int el){
    heap.push_back(el);
    upHeapify(heap);
}

vector<int> Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> heap;
    vector<int> res;
    for(int i=0; i<n; i++){
        if(A[i][0]==1){
            res.push_back(extractMinHeap(heap));
        }
        else if(A[i][0]==2){
            insertHeap(heap, A[i][1]);
        }
    }
    return res;
}
