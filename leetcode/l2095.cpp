struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) return nullptr;
        

        int len = 1;
        ListNode* curr = head;
        ListNode* mid = head;
        ListNode* midParent = head;
        int midIdx = 0;

        while (curr != nullptr) {
            int trueMid = len / 2;
            if (midIdx < trueMid) {
                midIdx++;
                midParent = mid;
                mid = mid->next;
            }
            
            curr = curr->next;
            len++;
        }

        midParent->next = mid->next;

        return head;
    }
};
