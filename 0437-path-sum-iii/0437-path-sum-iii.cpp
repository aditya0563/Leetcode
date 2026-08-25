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
    int count = 0;
    
    void dfs(TreeNode* root, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if (!root) return;
        
        currentSum += root->val;
        
        if (prefixSums.count(currentSum - targetSum)) {
            count += prefixSums[currentSum - targetSum];
        }
        
        prefixSums[currentSum]++;
        
        dfs(root->left, currentSum, targetSum, prefixSums);
        dfs(root->right, currentSum, targetSum, prefixSums);
        
        prefixSums[currentSum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1; 
        dfs(root, 0, targetSum, prefixSums);
        return count;
    }
};