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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans{1,-1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;
        int first = -1;
        int prevCrit = -1;
        int minDist = INT_MAX;
        int maxDist = -1;
        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            bool crit =(curr->val > prev->val && curr->val > next->val) ||
                            (curr->val < prev->val && curr->val < next->val);
            if (crit) {
                if(first == -1) {
                    first = pos;
                }
                else{
                    minDist= min(minDist,pos-prevCrit);
                    maxDist= max(maxDist,pos-first);
                }
                prevCrit = pos;
            }
            prev = curr;
            curr = next;
            pos++;
        }
        if (maxDist== -1) {
            return {-1, -1};
        }
        return {minDist, maxDist};
    }
};