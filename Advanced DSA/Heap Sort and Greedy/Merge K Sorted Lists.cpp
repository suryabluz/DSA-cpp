/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    bool operator()(const ListNode* a, const ListNode* b) const{
        return a->val > b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;       //SC:O(k)
    int n=A.size();
    for(int i=0; i<n; i++){
        pq.push(A[i]);
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    while(!pq.empty()){                                         //TC:O(n)
        ListNode* top = pq.top();
        pq.pop();                                               //TC:O(logk)
        tail->next = top;
        tail = tail->next;
        if(top->next!=NULL){
            pq.push(top->next);                                 //TC:O(logk)
        }
    }
    return dummy->next;
}

//TC:O(nlogk)
//SC:O(k)