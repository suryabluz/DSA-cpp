string Solution::solve(string A) {
    stack<string> st;
    int n=A.size();
    for(int i=0; i<n; i++){
        string word="";
        while(A[i]!=' ' && i<n){
            word+=A[i];
            i++;
        }
        if(word==""){
            continue;
        }
        st.push(word);
    }
    string res="";
    while(!st.empty()){
        res+=st.top();
        st.pop();
        if(st.empty()){
            continue;
        }
        res+=" ";
    }

    return res;
}
