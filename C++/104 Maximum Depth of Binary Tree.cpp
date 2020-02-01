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
    int search(TreeNode* cur, int depth) {
        if(cur == NULL) return depth-1;
        return max(search(cur->left, depth+1), search(cur->right, depth+1)); 
    }
    int maxDepth(TreeNode* root) {
        return search(root, 1);
    }
};