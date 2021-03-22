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
    ListNode* oddEvenList(ListNode* head) {
      ListNode *prev_o = head;
      ListNode *even_head = head == NULL ? NULL : head->next;
      ListNode *prev_e = even_head;
      while (prev_e)
      {
        if (prev_e->next == NULL)
          break;
        prev_o->next = prev_e->next;
        prev_e->next = prev_e->next->next;
        prev_o->next->next = even_head;

        prev_e = prev_e->next;
        prev_o = prev_o->next;
      }

      return head;
    }
};
