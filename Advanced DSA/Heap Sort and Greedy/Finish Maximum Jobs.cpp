//Time class
class Time{
    public:
    int start;
    int end;
};

int Solution::solve(vector<int> &A, vector<int> &B) {
    vector<Time> arr;
    //insert the array value in pair
    // TC: O(n)
    for(int i=0; i<A.size(); i++){
        arr.push_back({A[i], B[i]});
    }
    //sort the array
    // TC: O(nlogn)
    std::sort(arr.begin(), arr.end(), [](const Time &a, const Time &b){
        return a.end < b.end;
    });
    int count=1;
    Time currJob = arr[0];
    int i=1;
    int n = arr.size();
    //greedily select the jobs
    // TC: O(n)
    while(i<n){
        if(currJob.end<=arr[i].start){
            count++;
            currJob = arr[i];
        }
        i++;
    }
    return count;
}

//TC: O(nlogn)
//SC: O(n)