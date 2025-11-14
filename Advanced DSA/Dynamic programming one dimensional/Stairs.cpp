int mod = 1000000007;
long stairCase(int A, vector<long> &db){
    if(A==0||A==1){
        db[A]=1;
        return 1;
    }
    if(db[A]!=-1){
        return db[A];
    }
    db[A] = (stairCase(A-1, db)%mod + stairCase(A-2, db)%mod)%mod;
    return db[A];
}

int Solution::climbStairs(int A) {
    vector<long> db(A+1, -1);
    db[A] = stairCase(A, db);
    return (int)db[A];
}
