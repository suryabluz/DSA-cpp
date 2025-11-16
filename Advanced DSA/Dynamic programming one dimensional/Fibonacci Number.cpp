#include<iostream>
#include<vector>

using namespace std;

int fib(int A, vector<int> &db){
    if(A==0||A==1){
        db[A] = A;
        return A;
    }
    if(db[A]!=-1){
        return db[A];
    }
    db[A] = fib(A-1, db)+fib(A-2, db);
    return db[A];
}
int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int A;
    cin >> A;
    vector<int> db(A+1, -1);
    db[A] = fib(A, db);
    cout << db[A];
    return 0;
}