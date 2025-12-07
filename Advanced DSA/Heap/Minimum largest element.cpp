using namespace std;
int Solution::solve(vector < int > & A, int B) {
    priority_queue < pair < int, int > , vector < pair < int, int > > , greater < pair < int, int > > > pq;
    int s = A.size();

    //Let's keep a state array to keep track of the value of every element in the array after K operations.
    //Initially state array will be the same as the inital array.
    vector < int > state = A;

    //Consider a min heap. And initially push the next state of every element in the heap.
    //Note that you need to keep track of the indices of every element in the heap, present in the initial array.

    for (int i = 0; i < s; i++) {
        pq.push(make_pair(2 * A[i], i));
    }

    while (B--) {
        pair < int, int > top = pq.top();
        state[top.second] = top.first;
        pq.pop();
        pq.push(make_pair(A[top.second] + top.first, top.second));
    }
    int mx = state[0];
    for (int i = 0; i < s; i++) {
        mx = max(mx, state[i]);
    }
    return mx;
}