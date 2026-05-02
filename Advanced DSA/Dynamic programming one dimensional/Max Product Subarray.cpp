int Solution::maxProduct(const vector<int> &A) {
    vector<int> dp(A);
    int n=A.size();
    int minProd = A[0];
    int maxProd = A[0];
    int ans = A[0];
    for(int i=1; i<n; i++){                             //TC:O(n)
        int el = A[i];
        int tempMin = min({el, el*minProd, el*maxProd});
        int tempMax = max({el, el*minProd, el*maxProd});
        minProd = tempMin;
        maxProd = tempMax;
        ans = max(ans, maxProd);
    }
    return ans;
}

//TC:O(n)
//SC:O(1)