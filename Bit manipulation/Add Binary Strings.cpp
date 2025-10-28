#include <algorithm>

using namespace std;

string Solution::addBinary(string A, string B) {
    int nA = A.size()-1;
    int nB = B.size()-1;
    char carry='0';
    string res;
    while(nA>=0 && nB>=0){
        if(A[nA]=='0' && B[nB]=='0'){
            res+=carry;
            carry='0';
        }
        if((A[nA]=='0' && B[nB]=='1') || (A[nA]=='1' && B[nB]=='0')){
            if(carry=='0'){
                res+='1';
            }
            else{
                res+='0';
            }
        }
        if(A[nA]=='1' && B[nB]=='1'){
            if(carry=='0'){
                res+='0';
            }
            else{
                res+='1';
            }
            carry = '1';
        }
        nA--;
        nB--;
    }
    while(nA>=0){
        if(carry=='1' && A[nA]=='1'){
            res+='0';
            carry='1';
        }
        else if(carry=='0' && A[nA]=='0'){
            res+='0';
            carry = '0';
        }
        else{
            res+='1';
            carry='0';
        }
        nA--;
    }
    while(nB>=0){
        if(carry=='1' && B[nB]=='1'){
            res+='0';
            carry='1';
        }
        else if(carry=='0' && B[nB]=='0'){
            res+='0';
            carry = '0';
        }
        else{
            res+='1';
            carry='0';
        }
        nB--;
    }
    if(carry=='1'){
        res+=carry;
    }
    reverse(res.begin(), res.end());
    return res;
}
