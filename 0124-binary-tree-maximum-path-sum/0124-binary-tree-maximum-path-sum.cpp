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
    int sum(TreeNode* node,int& res){
        if(!node) return 0;
        int left=max(0,sum(node->left,res));
        int right=max(0,sum(node->right,res));
        res=max(res,left+right+node->val);
        return node->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int res=INT_MIN;
        sum(root,res);
        return res;
    }
};