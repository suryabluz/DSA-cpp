int Solution::candy(vector<int> &A) {
    int n=A.size();
    vector<int> candy(n, 1);        //SC:O(n)
    int count=1;
    //left max
    for(int i=1; i<n; i++){         //TC:O(n)
        if(A[i-1]<A[i]){
            candy[i]=candy[i-1]+1;
        }
    }

    //right max
    count=1;
    for(int i=n-2; i>=0; i--){          //TC:O(n)
        if(A[i+1]<A[i]){
            candy[i] = max(candy[i], candy[i+1]+1);
        }
    }

    //calculate the total no of candies
    int total=0;
    for(int i=0; i<n; i++){             //TC:O(n)
        total+=candy[i];
    }
    return total;
}

//TC:O(n)
//TC:O(n)