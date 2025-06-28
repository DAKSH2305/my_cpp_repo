// 114. Flatten Binary Tree to Linked List
// link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=problem-list-v2&envId=binary-tree
/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

// LESS OPTIMISED 
class Solution {
    void preorder(TreeNode*root,vector<TreeNode*> &v){
        if(root==NULL){
            
            return ;

        }
        v.push_back(root);
        preorder(root->left,v);
        preorder(root->right,v);
    }
public:
    void flatten(TreeNode* root) {
        if(root==NULL ){
            return;
        }
       
        vector<TreeNode*> sol;
        preorder(root,sol);
        for(int i=0;i<sol.size()-1;i++){
            
            sol[i]->left=NULL;
            sol[i]->right=sol[i+1];
        }
        sol.back()->left=NULL;
        sol.back()->right=NULL;



// FULL OPTIMISED O(N) TC AND SC - O(1)
// MORRIS TRAVERSAL . 

class Solution {
    void morrisTraversal(TreeNode*root){
        TreeNode*curr =root;
        TreeNode*prev;
        while(curr!=NULL){
            if (curr->left){
                prev= curr->left;
                while(prev->right){
                    prev=prev->right;
                    
                }
                prev->right=curr->right;
                curr->right=curr->left;
                
            }
            curr=curr->right;
        }
        curr=root;
        while(curr!=NULL){
            curr->left=NULL;
            curr=curr->right;
        }
    }
   
public:
    void flatten(TreeNode* root) {
   
        morrisTraversal(root);

    }
};

    }
};
