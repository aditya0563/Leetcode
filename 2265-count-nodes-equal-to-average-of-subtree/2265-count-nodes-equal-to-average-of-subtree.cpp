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
    int matchCount = 0;

    pair<int, int> postOrder(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        
        pair<int, int> leftSubtree = postOrder(node->left);
        pair<int, int> rightSubtree = postOrder(node->right);
        
        int currentSum = leftSubtree.first + rightSubtree.first + node->val;
        int currentCount = leftSubtree.second + rightSubtree.second + 1;
        
        if (currentSum / currentCount == node->val) {
            matchCount++;
        }
        
        return {currentSum, currentCount};
    }

    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return matchCount;
    }
};