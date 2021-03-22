/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
      if (root == NULL)
        return 0;
      queue<TreeNode*> qe;
      qe.push(root);
      int count = 1;
      while (!qe.empty())
      {
        TreeNode *p = qe.front();
        qe.pop();
        if (p->left)
        {
          qe.push(p->left);
          ++count;
        }
        if (p->right)
        {
          qe.push(p->right);
          ++count;
        }
      }
      return count;
    }
};
