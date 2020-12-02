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
    
    bool isValid(TreeNode* root, TreeNode* max, TreeNode* min) {
        
        if(root == NULL)
            return true;
        
        if((max != NULL && root->val >= max->val) or (min != NULL && root->val <= min->val))
            return false;
        
        else 
            return (isValid(root->left, root, min)&& isValid(root->right, max, root) );
        
    
        return false;
    }
    
    
    
        
    
    
    bool isValidBST(TreeNode* root) {
        
        return isValid(root, NULL, NULL);
        
    }
};