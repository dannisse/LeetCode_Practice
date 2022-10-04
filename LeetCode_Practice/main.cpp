#include <iostream>

int main() {
    //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//Easiest solution to Path Sum using recursion
    class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root==NULL)
                return false;
            if (root->left==NULL && root ->right == NULL && targetSum - root->val ==0)
                return true;
            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        }
    };
}
