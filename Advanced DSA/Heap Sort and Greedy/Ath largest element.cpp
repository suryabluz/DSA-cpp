vector<int> Solution::solve(int A, vector<int> &B) {
    priority_queue<int, vector<int>, greater<int>> pq; //SC:O(A)
    int n = B.size();
    if(A>n){
        return vector<int>(n, -1);
    }
    for(int i=0; i<A; i++){             //TC:O(A)
        pq.push(B[i]);
    }
    for(int i=0; i<A-1; i++){           //TC:O(A)
        B[i] = -1;
    }
    B[A-1] = pq.top();
    for(int i=A; i<n; i++){             //TC:O(n-A)
        int top = pq.top();             
        if(top<B[i]){
            pq.pop();                   //TC:O(logA)
            pq.push(B[i]);              //TC:O(logA)
        }
        B[i] = pq.top();
    }
    return B;
}

//TC:O(nlogA)
//SC:O(A)