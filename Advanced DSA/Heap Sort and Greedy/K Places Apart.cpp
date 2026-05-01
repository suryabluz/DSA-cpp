vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq; //SC:O(B)
    vector<int> ans;                //SC:O(n)
    if(B==0){   
        return A;
    }
    for(int i=0; i<=B; i++){        //TC:O(B)
        pq.push(A[i]);              //TC:O(logB)
    }
    int n=A.size();
    for(int i=B+1; i<n; i++){       //TC:O(n-B)
        ans.push_back(pq.top());    
        pq.pop();                   //TC:O(logB)
        pq.push(A[i]);              //TC:O(logB)    
    }
    while(!pq.empty()){             //TC:O(B)
        ans.push_back(pq.top());    
        pq.pop();                   //TC:O(logB)    
    }
    return ans;
}
//TC:O( BlogB + nlogB + BlogB)
//SC:O(n+B)