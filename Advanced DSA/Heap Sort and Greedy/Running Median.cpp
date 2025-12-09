vector<int> Solution::solve(vector<int> &A) {
    //max heap - default in c++
    priority_queue<int> p1;
    //min heap - use greater<int> for comparison
    priority_queue<int, vector<int>, greater<int>> p2;
    vector<int> res;
    int n=A.size();
    int cur = 0;
    p1.push(A[cur]);
    res.push_back(A[cur]);
    cur++;
    while(cur<n){
        //insert the element
        if(p1.top()>A[cur]){
            p1.push(A[cur]);
        }
        else{
            p2.push(A[cur]);
        }
        //balancing 
        if(p1.size()>p2.size()+1){
            p2.push(p1.top());
            p1.pop();
        }
        else if(p1.size()<p2.size()){
            p1.push(p2.top());
            p2.pop();
        }
        //median
        res.push_back(p1.top());
        cur++;
    }
    return res;
}

//TC: O(nlogn)
//SC: O(n)
