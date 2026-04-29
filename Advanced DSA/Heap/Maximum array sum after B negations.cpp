int Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq; //SC: O(n)
    int n=A.size();
    for(int i=0; i<n; i++){     //O(n)
        pq.push(A[i]);          //O(logn)
    }
    while(B--){                 //O(B)
        int top = pq.top();     
        pq.pop();               //O(logn)
        top = -1*top;
        pq.push(top);           //O(logn)
    }
    int total=0;
    while(!pq.empty()){         //O(n)
        total += pq.top();      
        pq.pop();               //O(logn)
    }
    return total;
}

//TC: O(nlogn + Blogn )
//SC: O(n)
