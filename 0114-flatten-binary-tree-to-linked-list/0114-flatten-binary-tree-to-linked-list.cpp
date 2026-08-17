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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left != NULL) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Rewire: attach original right subtree to the predecessor's right
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            // Move down the flattened right chain
            curr = curr->right;
        }
    }
};