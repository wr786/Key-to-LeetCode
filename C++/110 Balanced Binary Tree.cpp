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
    int toMaxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(toMaxDepth(root->left), toMaxDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(toMaxDepth(root->left) - toMaxDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};