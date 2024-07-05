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
        vector<int> ans = {INT_MAX, INT_MIN};
        ListNode* curr = head;
        int prevCritical = -1, firstCritical = -1, prevNode = curr->val, id = 0;
        curr = curr->next;

        while (curr != NULL && curr->next != NULL) {
            id++;
            int currNode = curr->val;
            int nextNode = curr->next->val;
            if ((prevNode > currNode && currNode < nextNode) || (prevNode < currNode && currNode > nextNode)) {
                if (firstCritical == -1) {
                    firstCritical = id;
                    prevCritical = id;
                } else {
                    ans[0] = min(ans[0], id - prevCritical); // min distance
                    prevCritical = id;
                }
                ans[1] = max(ans[1], id - firstCritical); // max distance
            }
            prevNode = currNode;
            curr = curr->next;
        }
        vector<int> defaultAns = {-1, -1};
        return (ans[0] == INT_MAX) ? defaultAns : ans;
    }
};