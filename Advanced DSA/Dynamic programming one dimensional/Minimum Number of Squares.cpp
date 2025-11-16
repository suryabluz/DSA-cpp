#include<limits>
#include<algorithm>
using namespace std;
int minSq(int A, vector<int>& db){
    int ans = numeric_limits<int>::max();
    if(A<=0){
        return 0;
    }
    if(db[A]!=0){
        return db[A];
    }
    for(int i=1; i*i<=A; i++){
        ans = min(ans, minSq(A-i*i, db));
    }
    db[A] = ans+1;
    return db[A];
}

int Solution::countMinSquares(int A) {
    vector<int> db(A+1);
    db[A] = minSq(A, db);
    return db[A];
}

//TC: O(N*Sqrt(N))
//SC: N

