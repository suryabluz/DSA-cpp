#include <unordered_map>
#include <climits>
string Solution::minWindow(string A, string B) {
    unordered_map<char, int> count;             //SC:O(1) // At max we are going to store 52 char A-Z, a-z
    for(char el:B){                             //TC:O(n)
        count[el]++;
    }
    int required = count.size();
    int formed=0;
    int l=0;
    int r=0;
    int minLen = INT_MAX;
    int minLeft = 0;
    int minRight = 0;
    while(r<A.size()){                          
        char right = A[r];
        if(count.find(right)!=count.end()){
            count[right]--;
            if(count[right]==0){
                formed++;
            }
        }
        
        while(formed==required){                
            if((r-l+1)<minLen){
                minLen = r-l+1;
                minLeft = l;
                minRight = r;
            }
            char left = A[l];
            if(count.find(left)!=count.end()){
                count[left]++;
                if(count[left]==1){
                    formed--;
                }
            }
            l++;
        }
        r++;
    }
    return (minLen==INT_MAX)?"-1":A.substr(minLeft, minLen);
}
//TC:O(n)
//SC:O(1)
