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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left != NULL) root->left = removeLeafNodes(root->left, target);
        if(root->right != NULL) root->right = removeLeafNodes(root->right, target);
        if(root->left == NULL && root->right == NULL) { // 叶子节点
            if(root->val == target) return NULL;
            else return root;
        }
        return root;
    }
};