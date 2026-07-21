/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* head=nullptr;
        ListNode** tail=&head;

        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<=l2->val){
                *tail=l1;
                l1=l1->next;
            }
            else{
                *tail=l2;
                l2=l2->next;
            }
            tail=&((*tail)->next);
        }

        *tail=(l1!=nullptr)?l1:l2;
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int step=1,n=lists.size();

        while(step<n){
            for(int i=0;i+step<n;i+=step*2) lists[i]=merge(lists[i],lists[i+step]);
            step*=2;
        }

        return lists[0];
    }
};