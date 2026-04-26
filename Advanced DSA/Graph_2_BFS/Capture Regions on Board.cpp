
struct Pair{
    int i;
    int j;
    Pair(int a, int b){
        i=a;
        j=b;
    }
};
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    queue<Pair> q;
    int n=A.size();
    int m=A[0].size();
    //top
    for(int j=0; j<m; j++){ //TC: O(m)
        if(A[0][j]=='O'){
            q.push(Pair(0,j));
            A[0][j]='S';
        }
    }
    //bottom
    for(int j=0; j<m; j++){ //TC: O(m)
        if(A[n-1][j]=='O'){
            q.push(Pair(n-1,j));
            A[n-1][j]='S';
        }
    }
    //left
    for(int i=1; i<n-1; i++){ //TC:O(n)
        if(A[i][0]=='O'){
            q.push(Pair(i,0));
            A[i][0]='S';
        }
    }
    //right
    for(int i=1; i<n-1; i++){ //TC:O(n)
        if(A[i][m-1]=='O'){
            q.push(Pair(i,m-1));
            A[i][m-1]='S';
        }
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!q.empty()){ //TC: O(n*m)
        Pair p = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ni=p.i+dx[i];
            int nj=p.j+dy[i];
            if(ni>=0 && ni<n && nj>=0 && nj<m && A[ni][nj]=='O'){
                q.push(Pair(ni, nj));
                A[ni][nj]='S';
            }
        }
    }
    for(int i=0; i<n; i++){ //TC:O(n*m)
        for(int j=0; j<m; j++){
            if(A[i][j]=='O'){
                A[i][j]='X';
            }
            if(A[i][j]=='S'){
                A[i][j]='O';
            }
        }
    }
}

//TC: O(n*m)
//SC: O(n*m)