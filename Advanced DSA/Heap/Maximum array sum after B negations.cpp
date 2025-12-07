int Solution::solve(vector<int> &A, int B) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    int n = A.size();
    for(int i=0; i<n; i++){
        pq.push({A[i], i});
    }
    while(B>0){
        pair<int, int> minEl = pq.top();
        pq.pop();
        int val = -1*minEl.first;
        A[minEl.second] = val;
        pq.push({val, minEl.second});
        B--;
    }
    int sum=0;
    for(int x:A){
        sum+=x;
    }
    return sum;
}
