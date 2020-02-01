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
    TreeNode* origin;
public:
    int search(TreeNode* cur) {
        int ret = INT_MAX;
        if(cur->left != NULL) ret = min(ret, search(cur->left)+1);
        if(cur->right != NULL) ret = min(ret, search(cur->right)+1);
        if(ret == INT_MAX) return 1; // 叶子节点
        return ret;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        origin = root;
        return search(root);
    }
};