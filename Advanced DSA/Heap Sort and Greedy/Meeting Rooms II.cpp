int Solution::solve(int A, vector<vector<int> > &B) {
    priority_queue<int, vector<int>, greater<int>> pq;              //SC:O(A)
    sort(B.begin(), B.end(), [](vector<int> &a, vector<int> &b){    //TC:O(AlogA)
        return a[0]<b[0];
    });
    pq.push(B[0][1]);               //TC:O(logA)
    for(int i=1; i<A; i++){         //TC:O(A)  
        int top = pq.top();
        if(top<=B[i][0]){
            pq.pop();               //TC:O(logA)
        }
            pq.push(B[i][1]);           //TC:O(logA)
    }
    return pq.size();
}
//TC:O(AlogA)
//TC:O(K)