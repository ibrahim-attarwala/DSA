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
    ListNode* kthNode(ListNode* temp, int k){
        k-=1;
        while(temp!=nullptr && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* kNode=kthNode(temp,k);
            if(kNode==nullptr){
                if(prev)prev->next=temp;
                break;
            }

            ListNode* nextNode=kNode->next;
            kNode->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=kNode;
            }
            else{
                prev->next=kNode;
            }
            temp->next=nextNode;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};