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
    
    /*
    
    Step 1: inorder ka index pata karna hoga.
    Step 2: recursion shrink array into two parts start 0 -to index - 1 and index + 1 to end
    
    
    
    */
    TreeNode* build(vector<int> &preorder, int &ps, vector<int> &inorder, int is, int ie, unordered_map<int,int> &m) {
        
        
       if(is > ie)
           return NULL;
        
        auto  itr = m.find(preorder[ps]);
        int index = itr->second;
        
        TreeNode* root = new TreeNode(preorder[ps++]);

        root->left = build(preorder, ps, inorder, is, index - 1, m);
        root->right = build(preorder, ps, inorder, index + 1, ie, m);
        
        return root;
      
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0)
            return NULL;
        
        
        unordered_map<int, int> m;
        
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        
        int ps = 0;
         return build(preorder, ps, inorder, 0, inorder.size() -1, m);
        
        
        
        
    }
};