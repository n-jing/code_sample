#include <vector>
#include <stack>
#include <iostream>


using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
      if (root == nullptr)
        return 0;
      stack<TreeNode*> serial;
      TreeNode *ptr = root;
      while (ptr)
      {
        serial.push(ptr);
        ptr = ptr->left;
      }

      int count = 0;
      while (!serial.empty())
      {
        TreeNode *ptr = serial.top();
        serial.pop();
        ++count;
        if (count == k)
          return ptr->val;
        if (ptr->right)
        {
          ptr = ptr->right;
          while (ptr)
          {
            serial.push(ptr);
            ptr = ptr->left;
          }
        }
      }

      return 0;
    }
};



int main (int argc, char *argv[])
{
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  Solution su;
  auto p = su.kthSmallest(root, 2);
  cerr << "p:" << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
