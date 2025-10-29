string Solution::longestPalindrome(string A) {
    int n=A.size();
    int maxLen = 1;
    int startIdx=0;
    int endIdx=0;
    //odd 
    for(int i=0; i<n; i++){
        int left = i-1;
        int right = i+1;
        while(left>=0 && right<n){
            if(A[left]==A[right]){
                int len = right-left+1;
                if(maxLen<len){
                    startIdx = left;
                    endIdx = right;
                    maxLen = len;
                }
            }
            else{
                break;
            }
            left--;
            right++;
        }
    }

    //even
    for(int i=0; i<n; i++){
        int left = i;
        int right = i+1;
        while(left>=0 && right<n){
            if(A[left]==A[right]){
                int len = right-left+1;
                if(maxLen<len){
                    startIdx = left;
                    endIdx = right;
                    maxLen = len;
                }
            }
            else{
                break;
            }
            left--;
            right++;
        }
    }
    return A.substr(startIdx, maxLen);
}