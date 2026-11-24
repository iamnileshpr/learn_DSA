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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;

        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int base=len/k;
        int extra=len%k;

        vector<ListNode*>ans(k,NULL);
        ListNode* curr=head;

        for(int i=0;i<k;i++){
            if(curr==NULL){
                break;
            }
            ans[i]=curr;
            int part=base;
            if(i<extra) part++;
            for (int j = 1; j < part; j++) {
                curr = curr->next;
            }

            ListNode* nextPart = curr->next;

            curr->next = nullptr;

            
            curr = nextPart;
        }

        return ans;
        
    }
};