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
    
        int MOD = 1e9+7;
        long long sum=0;
        long long maxP=0;
    
        int totalSum(TreeNode* root){
            if(!root) return 0;
    
            int leftSum = totalSum(root->left);
            int rightSum = totalSum(root->right);
    
            long long subTreeSum = root->val + leftSum + rightSum;
            long long remainingTreeSum = sum - subTreeSum;
            maxP = max(maxP,remainingTreeSum * subTreeSum);
    
            return subTreeSum;
        }
    
        int maxProduct(TreeNode* root) {
            if(!root) return 0;
    
            sum = totalSum(root);
            totalSum(root);
    
            return maxP % MOD;
        }
    };