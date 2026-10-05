/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int currSum = 0;
        int sum;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        TreeNode* curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr) {
                currSum += curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            } else {
                sum = currSum;
                currSum = 0;
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
        }
        return sum;
    }
};