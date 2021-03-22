#include <stack>
#include <vector>
#include <iostream>
#include <queue>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string tree_serial;
      queue<TreeNode*> tree;
      tree.push(root);
      while (!tree.empty())
      {
        TreeNode* t = tree.front();
        tree.pop();
        if (t == nullptr)
        {
          tree_serial += "n ";
          continue;
        }
        else
        {
          tree_serial += to_string(t->val) + " ";
          tree.push(t->left);
          tree.push(t->right);
        }
      }
      return tree_serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      int idx = data.find(" ");
      string d = data.substr(0, idx);
      if (d == "n")
        return nullptr;
      ++idx;
      TreeNode *root = new TreeNode(atoi(d.c_str()));
      queue<TreeNode*> layer;
      layer.push(root);
      while (!layer.empty())
      {
        queue<TreeNode*> next_layer;
        while (!layer.empty())
        {
          TreeNode *t = layer.front();
          layer.pop();
          int next_idx = data.find(" ", idx);
          d = data.substr(idx, next_idx - idx);
          if (d != "n")
          {
            t->left = new TreeNode(atoi(d.c_str()));
            next_layer.push(t->left);
          } 
          idx = next_idx+1;
          next_idx = data.find(" ", idx);
          d = data.substr(idx, next_idx - idx);
          if (d != "n")
          {
            t->right = new TreeNode(atoi(d.c_str())); 
            next_layer.push(t->right);
          }
          idx = next_idx+1;
        }
        layer = next_layer;
      }

      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  Codec su;
  string str = su.serialize(root);
  TreeNode *r = su.deserialize(str);
  cerr << r->val << " " << r->left->val << " " << r->right->val << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
