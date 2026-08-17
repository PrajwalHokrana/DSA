/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxGain(TreeNode* root, int& maxSum) {
        if (!root) return 0;

        // Kadane intuition: ignore negative branch sums with max(0, ...)
        int leftGain = max(0, maxGain(root->left, maxSum));
        int rightGain = max(0, maxGain(root->right, maxSum));

        // Path sum with current node as the highest turning point
        int currentPathSum = root->val + leftGain + rightGain;

        // Update the global maximum path found so far
        maxSum = max(maxSum, currentPathSum);

        // Return single continuous branch sum to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
};