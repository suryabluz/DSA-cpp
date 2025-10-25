#include <algorithm>
#include <climits>
using namespace std;

void prefixSum(int A, vector<int> &C){
    for(int i=1; i<A; i++){
        C[i] = C[i]+C[i-1];
    }
}
int Solution::maxSubarray(int A, int B, vector<int> &C) {
    prefixSum(A, C);
    int s=0;
    int e=0;
    int sum = 0;
    int maxSum = 0;
    for(int i=0; i<A; i++){
        for(int j=i; j<A; j++){
            s=i;
            e=j;
            if(s==0){
                sum = C[e];
            }
            else{
                sum = C[e] - C[s-1];
            }
            if(sum<=B){
                maxSum = max(sum, maxSum);
            }
        }
    }
    return maxSum;
}
