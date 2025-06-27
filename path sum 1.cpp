// path sum I 
/* 
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
*/

class Solution {
    bool pathsum(TreeNode*root,int s,int k){
        if(root==NULL){
            return false;
        }
        s=s+root->val;
        if(root->left==NULL&&root->right==NULL){
            return (s==k);
        }
        return pathsum(root->left,s,k)||pathsum(root->right,s,k);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathsum(root,0,targetSum);
    }
};
