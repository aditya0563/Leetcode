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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        vector<ListNode*> nodes;
        ListNode* curr=head;

        while(curr!=nullptr){
            nodes.push_back(curr);
            curr=curr->next;
        }

        int l=0,r=nodes.size()-1;
        while(l<r){
            nodes[l]->next=nodes[r];
            l++;
            if(l==r) break;
            nodes[r]->next=nodes[l];
            r--;
        }
        nodes[l]->next=nullptr;
    }
};