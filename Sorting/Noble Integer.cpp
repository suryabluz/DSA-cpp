#include <algorithm>
using namespace std;

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end(), greater<int>());
    int n = A.size();
    int cnt = 0;
    if(A[0]==0){
        return 1;
    }
    for(int i=1; i<n; i++){
        if(A[i]!=A[i-1]){
            cnt = i;
        }
        if(cnt==A[i]){
           return 1;
        }
    }
    return -1;
}
