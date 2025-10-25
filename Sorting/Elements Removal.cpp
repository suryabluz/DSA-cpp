#include <algorithm>

using namespace std;
int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end(), greater<int>());
    int n = A.size();
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + A[i]*(i+1);
    }
    return sum;
}
