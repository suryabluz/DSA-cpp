int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum=0;
    for(int x:A){
        pq.push(x);
    }
    while(!pq.empty()){
        int firstTop = pq.top();
        pq.pop();
        if(firstTop>B){
            return sum;
        }
        int candy = firstTop/2;
        int rem = firstTop - candy;
        sum+=candy;
        if(pq.empty()){
            return sum;
        }
        int next = pq.top();
        pq.pop();
        next+=rem;
        pq.push(next);
    }
    return sum;
}
