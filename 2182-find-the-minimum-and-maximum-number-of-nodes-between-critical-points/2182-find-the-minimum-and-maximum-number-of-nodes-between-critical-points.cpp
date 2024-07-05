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
        if (!head || !head->next || !head->next->next) return {-1, -1};  // Less than 3 nodes

        vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (criticalPoints.size() < 2) 
        return {-1, -1};

        int minDistance = INT_MAX;
        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxDistance = criticalPoints.back() - criticalPoints.front();

        return {minDistance, maxDistance};
    }
};