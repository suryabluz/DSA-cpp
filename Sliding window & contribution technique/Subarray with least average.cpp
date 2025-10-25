#include <algorithm>
using namespace std;
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int sum;
    for(int i=0; i<B; i++){
        sum += A[i];
    }
    int minSum = sum;
    int idx = 0;
    int s=1;
    int e=B;
    while(e<n){
        sum = sum + A[e] - A[s-1];
        if(minSum>sum){
            minSum = sum;
            idx = s; 
        }
        s++;
        e++;
    }
    return idx;
}
