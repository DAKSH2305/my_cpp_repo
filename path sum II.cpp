// path sum II 
/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/
class Solution {
     void pathsum(TreeNode*root,int s,int k,vector<int> v,vector<vector<int>>& ans){
        if(root==NULL){
            return ;
        }
        s=s+root->val;
        v.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(s==k){
                ans.push_back(v);
                return;
                
            }
        }
        pathsum(root->left,s,k,v,ans);
        pathsum(root->right,s,k,v,ans);
        v.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v2;
        vector<int> v3;
        pathsum(root,0,targetSum,v3,v2);
        return v2;
    }
};
