struct Pair{
    int s;
    int e;
    Pair(int a, int b){
        e=a;
        s=b;
    }
};
struct cmp{
    bool operator()(const Pair &a, const Pair &b)const {
        return a.e>b.e;
    }
};
int Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<Pair, vector<Pair>, cmp> pq; //SC: O(n)
    for(int i=0; i<A.size(); i++){  //TC: O(n)
        pq.push(Pair(B[i], A[i]));  //TC: O(logn)
    } 
    Pair top = pq.top();
    pq.pop();                       //TC: O(logn)
    int count=1;
    while(!pq.empty()){             //TC: O(n)
        Pair second = pq.top();     
        pq.pop();                   //TC: O(logn)
        if(second.s>=top.e){
            count++;
            top = second;
        }
    }
    return count;
}

//TC: O(nlogn)
//SC: O(n)
