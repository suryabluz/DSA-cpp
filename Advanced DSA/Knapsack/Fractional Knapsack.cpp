struct Pair{
    int val;
    int wt;
};

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
   vector<Pair> items;                                                  //SC:O(n)
   int n=A.size();
   double ans=0.0;
   for(int i=0; i<n; i++){                                              //TC:O(n)
       items.push_back({A[i], B[i]});
   }
   sort(items.begin(), items.end(), [](const Pair &a, const Pair &b){   //TC: O(nlogn)
       return (double)a.val/a.wt > (double)b.val/b.wt;
   });
   for(int i=0; i<n; i++){                                              //TC:O(n)
       int weight = items[i].wt;
       int value = items[i].val;
       if(C>=weight){
           ans+=value;
           C-=weight;
       }
       else{
           ans+=((double)value/weight)*C;
           break;
       }
   }
   return (int)(ans*100+1e-9);
}

//TC:O(nlogn)
//SC:O(n)