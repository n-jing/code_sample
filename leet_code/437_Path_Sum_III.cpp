#include <iostream>
#include <vector>
#include <array>

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
    int pathSum(TreeNode* root, int sum) {
      if (root == NULL)
        return 0;
      int count = 0;
      count_node(root, count, sum);
      return count;
    }
  void count_path(TreeNode *root, int &count, int sum, int total)
    {
      if (root == NULL)
        return ;
      if (root->val == sum)
        ++count;
      count_path(root->left, count, sum - root->val, total);
      count_path(root->right, count, sum - root->val, total);

    }
  void count_node(TreeNode *root, int &count, int sum)
    {
      if (root == NULL)
        return ;
      if (root->val == sum)
        count++;
      count_node(root->left, count, sum);
      count_node(root->right, count, sum);

      count_path(root->left, count, sum - root->val, sum);
      count_path(root->right, count, sum -  root->val, sum);
    }
};

#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(-2);
  root->left->left = new TreeNode(1);
  root->left->left->left = new TreeNode(-1);
  Solution su;
  auto p = su.pathSum(root, 0);
  cerr << "r:" << p << endl;
  return 0;
}
