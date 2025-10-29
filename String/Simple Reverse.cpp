string Solution::solve(string A) {
    int s = 0;
    int e = A.size()-1;
    while(s<e){
        char temp = A[s];
        A[s] = A[e];
        A[e] = temp;
        s++;
        e--;
    }
    return A;
}
