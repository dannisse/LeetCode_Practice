#include <iostream>
/*QUESTION: Given the root of a binary tree and an integer targetSum
* return true if the tree has a root-to-leaf path
* such that adding up all the values along the path equals targetSum.
*/

int main() {
    //Definition for a binary tree node.
    struct TreeNode {
        int val; //val is declared as a datatype
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