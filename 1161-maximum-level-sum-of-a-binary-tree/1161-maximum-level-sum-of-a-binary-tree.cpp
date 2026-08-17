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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int answer=1;
        int max = INT_MIN;
        if (!root)
            return answer; // Handle empty tree edge case

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // 1. Get the number of nodes at the current level
            int levelSize = q.size();
            int sum = 0;
                // 2. Process exactly 'levelSize' nodes
                for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                // 3. Push children to the queue for the next level
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            if (sum > max) {
                answer = level;
                max = sum;
            }
            level++;
        }

        return answer;
    }
};