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
    vector<vector<int>> ret;
    int maxDepth = 0;
public:
    void 
    search(TreeNode* root, int depth) {
        if(root == NULL) {
            maxDepth = max(maxDepth, depth - 1);
            return;
        }
        if(ret.size() <= depth) {
            vector<int> newRow;
            ret.push_back(newRow);
        }
        search(root->left, depth+1);
        search(root->right, depth+1);
    }

    void
    insertVals(TreeNode* root, int depth) {
        if(root == NULL) return;
        ret[maxDepth - depth].push_back(root->val);
        insertVals(root->left, depth+1);
        insertVals(root->right, depth+1);
    }

    vector<vector<int>> 
    levelOrderBottom(TreeNode* root) {
        search(root, 0);
        insertVals(root, 0);
        return ret;
    }
};