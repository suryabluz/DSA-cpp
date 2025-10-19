#include <limits>//numeric_limits<int>::max()
#include <cmath>//abs()
#include <algorithm>//min()
using namespace std;

int findMin(vector<int> &A, int n){
    int min = numeric_limits<int>::max();
    for(int i=0; i<n; i++){
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}
int findMax(vector<int> &A, int n){
    int max = numeric_limits<int>::min();
    for(int i=0; i<n; i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    int min = findMin(A, n);
    int max = findMax(A, n);

    int ans = numeric_limits<int>::max();
    int length = 0;
    int minIdx = -1;
    int maxIdx = -1;
    for(int i=n-1; i>=0; i--){
        if(A[i]==min){
            minIdx = i;
        }
        if(A[i]==max){
            maxIdx = i;
        }
        if((maxIdx!=-1) && (minIdx!=-1)){
            length = abs(maxIdx-minIdx)+1;
            ans = std::min(length,ans);
        }
    }
    return ans;
}
