int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int ans = 0;
    for(int i=0; i<n; i++){                     //TC:O(n)
        for(int j=1; j<m; j++){                 //TC:O(m)
            if(A[i][j]==1){
                A[i][j]=A[i][j-1]+A[i][j];
            }
        }
    }
    for(int i=0; i<n; i++){                     //TC:O(n)
        for(int j=0; j<m; j++){                 //TC:O(m)
            if(A[i][j]==0){
                continue;
            }
            int width = A[i][j];
            for(int k=i; k>=0; k--){            //TC:O(n)
                width = min(width, A[k][j]);
                if(width==0){
                    break;
                }
                int height = i-k+1; 
                ans = max(ans, width*height);
            }
        }
    }
    return ans;
}
//TC:O(n*n*m)
//SC:O(1)