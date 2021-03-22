/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode *fast = head;
      ListNode *slow = head;
      bool circle = false;
      while (fast && fast->next && slow)
      {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
          circle = true;
          break;
        }
      }
      if (!circle)
        return nullptr;
      ListNode *circle_ptr = fast;
      int count = 0;
      do
      {
        circle_ptr = circle_ptr->next;
        count++;
      } while(circle_ptr != fast);
      fast = slow = head;
      while (count-- > 0)
        fast = fast->next;
      while (fast != slow)
      {
        fast = fast->next;
        slow = slow->next;
      }

      return fast;
    }
};
