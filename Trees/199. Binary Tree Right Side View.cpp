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
    
    
    void levelOrderHelper(TreeNode* root, vector<int>& ans) {
        
        deque<TreeNode*> q;
        q.push_back(root);
        //ans.push_back(q.back()->val);
        
        
        while(!q.empty()) {
            
            int count = q.size();
            //cout<<count<<" ";
            int v = q.back()->val;
            ans.push_back(v);
            
            while(count--) {
                cout<<count<<" ";
                TreeNode* p = q.front();
                q.pop_front();
                
                if(p->left != NULL)
                    q.push_back(p->left);
                
                if(p->right != NULL)
                    q.push_back(p->right);
                
            }
        
        }
            
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        
        levelOrderHelper(root, ans);
        return ans;
    }
};