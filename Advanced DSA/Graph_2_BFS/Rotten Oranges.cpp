struct Pair{
    int i;
    int j;
    Pair(int x, int y){
        i=x;
        j=y;
    }
};
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    queue<Pair> q;
    int time=0;
    for(int i=0; i<n; i++){ //O(n*m)
        for(int j=0; j<m; j++){
            if(A[i][j]==2){
                q.push(Pair(i,j));
            }
        }
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!q.empty()){ 
        int size = q.size();
        bool spread = false;
        for(int k=0; k<size; k++){
            Pair p = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int ni = p.i + dx[i];
                int nj = p.j + dy[i];
                if(ni>=0 && ni<n && nj>=0 && nj<m && A[ni][nj]==1){
                    A[ni][nj]=2;
                    q.push(Pair(ni, nj));
                    spread = true;
                }
            }
        }
        if(spread){
            time++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]==1){
                return -1;
            }
        }
    }
    return time;
}

//TC: O(n*m)
//SC: O(n*m)