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
public:
    void search(TreeNode* cur, int depth) {
        if(cur == NULL) return;
        if(ret.size() <= depth) {
            vector<int> newLine;
            ret.push_back(newLine);
        }
        ret[depth].push_back(cur->val);
        search(cur->left, depth+1);
        search(cur->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        search(root, 0);
        return ret;
    }
};