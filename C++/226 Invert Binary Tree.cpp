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
private:
    void invertNode(TreeNode* cur) {
        if(cur == NULL) return;
        TreeNode* tmp = cur->left;
        cur->left = cur->right; cur->right = tmp;
        invertNode(cur->left);
        invertNode(cur->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invertNode(root);
        return root;
    }
};