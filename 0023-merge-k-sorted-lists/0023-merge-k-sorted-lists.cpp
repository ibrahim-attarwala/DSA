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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto x : lists) {
            if (x != nullptr) {
                q.push(x);
            }
        }
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
            tail->next = x;
            tail = tail->next;
            if (x->next != nullptr) {
                q.push(x->next);
            }
        }
        return dummy->next;
    }
};