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
    int dfs(TreeNode* current, TreeNode* parent, TreeNode* grandParent) {
        if (current == nullptr) return 0;

        int sum = 0;
        // If grandparent exists and is even, add current value
        if (grandParent != nullptr && grandParent->val % 2 == 0) {
            sum += current->val;
        }

        // Recurse down: current becomes parent, parent becomes grandParent
        sum += dfs(current->left, current, parent);
        sum += dfs(current->right, current, parent);

        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};