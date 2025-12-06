void swap(vector<int> &A, int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}
void upHeapify(vector<int> &A){
    int i = A.size()-1;
    while(i>=0){
        int pi = (i-1)/2;
        if(A[pi]>A[i]){
            swap(A, i, pi);
            i=pi;
        }
        else{
            break;
        }
    }
}
void downHeapify(vector<int> &A, int i){
    while(true){
        int lc = 2*i+1;
        int rc = 2*i+2;
        int smallest = i;
        int n = A.size();
        //check outofbound using lc<n
        //check lc lesser than parent(i)
        if(lc<n && A[smallest]>A[lc]){
            smallest = lc;
        }
        if(rc<n && A[smallest]>A[rc]){
            smallest = rc;
        }
        if(smallest==i){
            break;
        }
        swap(A, i, smallest);
        i = smallest;
    }
}

void buildMinHeap(vector<int> &A){
    int n = A.size();
    //for loop from last non loop
    for(int i=n/2-1; i>=0; i--){
        downHeapify(A, i);
    }
}
int deleteMinHeap(vector<int> &A){
    int min = A[0];
    swap(A, 0, A.size()-1);
    A.pop_back();
    downHeapify(A, 0);
    return min;
}
void insertHeap(vector<int> &A, int el){
    A.push_back(el);
    upHeapify(A);
}
int Solution::solve(vector<int> &A) {
    buildMinHeap(A);//O(n)
    int sum=0;
    while(A.size()>1){
        int firstSmallest = deleteMinHeap(A);//O(logn)
        int secondSmallest =  deleteMinHeap(A);//O(logn)
        int el = firstSmallest+secondSmallest;
        sum += el;
        insertHeap(A, el);//O(logn)
    }
    return sum;
}

//TC: n*3logn = nlogn
//SC: O(1)