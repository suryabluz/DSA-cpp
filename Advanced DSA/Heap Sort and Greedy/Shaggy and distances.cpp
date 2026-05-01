#include <unordered_map>
#include <climits>
int Solution::solve(vector<int> &A) {
    unordered_map<int, int> map;        //SC:O(n)
    int n = A.size();
    int ans = INT_MAX;
    bool pair=false;
    for(int i=0; i<n; i++){             //TC:O(n)
        int val = A[i];
        if(map.find(val)!=map.end()){
            int diff = i-map[val];
            ans = min(diff, ans);
        }
        map[val] = i;
    }
    return (ans==INT_MAX)?-1:ans;
}
//TC:O(n)
//SC:O(n)
