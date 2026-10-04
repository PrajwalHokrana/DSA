class Solution {
private:
    int matchingNodes = 0;

    // Returns {subtreeSum, nodeCount}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int totalSum = leftSum + rightSum + root->val;
        int totalCount = leftCount + rightCount + 1;

        // Integer division automatically rounds down
        if (totalSum / totalCount == root->val) {
            matchingNodes++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodes = 0;
        dfs(root);
        return matchingNodes;
    }
};