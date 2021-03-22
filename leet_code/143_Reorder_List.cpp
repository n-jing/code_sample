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
    void reorderList(ListNode* head) {
      ListNode *ptr = head;
      vector<ListNode*> list;
      while (ptr)
      {
        list.push_back(ptr);
        ptr = ptr->next;
      }

      ptr = head;
      int right = list.size() - 1;
      if (right <= 0)
        return head;
      const int n = list.size();
      for (int i = 0; i < (n-1)/2; ++i)
      {
        ListNode *origin_next = ptr->next;
        ptr->next = list[right];
        ptr->next->next = origin_next;
        ptr = origin_next;
        --right;
      }
      if (n % 2 == 0)
        ptr->next->next = NULL;
      else
        ptr->next = NULL;
      return head;
    }
};
