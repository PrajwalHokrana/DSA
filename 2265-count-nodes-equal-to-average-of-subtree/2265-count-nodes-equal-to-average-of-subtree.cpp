class Solution {
private:
    int matchingNodes = 0;

    // Returns {subtreeSum, nodeCount}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        int avg = sum/nodes;

        if(avg==root->val)
        {
            matchingNodes++;
        }

        return {sum,nodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodes = 0;
        dfs(root);
        return matchingNodes;
    }
};