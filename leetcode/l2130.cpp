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
    int pairSum(ListNode* head) {
        ListNode *curr = head, *mid = head, *prev = nullptr, *next = head->next;
        while (curr != nullptr) {
            curr = curr->next->next;
            mid->next = prev;
            prev = mid;
            mid = next;
            next = mid->next;
        }

        int maxSum = INT_MIN, sum;
        while (prev != nullptr) {
            sum = prev->val + mid->val;
            if (sum > maxSum) {
                maxSum = sum;
            }
            prev = prev->next;
            mid = mid->next;
        }

        return maxSum;
    }
};

// 1->2->3->4->5->6
