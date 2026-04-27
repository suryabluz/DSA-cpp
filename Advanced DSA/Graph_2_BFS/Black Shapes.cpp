struct Pair{
    int i;
    int j;
    Pair(int a, int b){
        i=a;
        j=b;
    }
};

void checkAdjacent(vector<string> &A, queue<Pair> &q, int *point){  
    int n = A.size();
    int m = A[0].size();
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!q.empty()){
        Pair p = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ni = p.i + dx[i];
            int nj = p.j + dy[i];
            if(ni>=0 && ni<n && nj>=0 && nj<m && A[ni][nj]=='X'){
                q.push(Pair(ni, nj));
                A[ni][nj] = 'S';
            }
        }
    }
    (*point)++;
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    int total=0;
    queue<Pair> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]=='X'){
                q.push(Pair(i,j));
                A[i][j]='S';
                checkAdjacent(A,q,&total);
            }
        }
    }
    return total;
}

//TC: O(n*m)
//SC: O(n*m)