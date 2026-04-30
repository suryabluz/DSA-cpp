int Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<int, vector<int>, greater<int>> minHeap; //SC:O(n)
    vector<pair<int, int>> arr;                             //SC:O(n)
    int mod = 1e9+7;
    int n = A.size();
    for(int i=0; i<n; i++){                                 //TC:O(n)
        arr.push_back({A[i], B[i]});
    }
    sort(arr.begin(), arr.end());                           //TC:O(nlogn)
    long total=0;

    for(int i=0; i<n; i++){                                 //TC:O(n)
        int exp = arr[i].first;
        int val = arr[i].second;
        minHeap.push(val);                                  //TC:O(logn)
        total+=(long)val;
        if(minHeap.size()>exp){            
            total -= (long)minHeap.top();
            minHeap.pop();                                  //TC:O(logn)
        }
    }
    return (int)(total%mod);
}

//TC:O(nlogn)
//TC:O(n)
