// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



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
    TreeNode*ans(vector<int> &pre, vector<int>& in,int & ind,int st,int end,int n,unordered_map<int,int>& m ){
        // pass by reference - vector and map to save memory , otherwise it will give TLE if passed by values due to too many copies .
        if(ind>=n){
            return NULL;

        }
        if(st>end){
            return NULL;

        }
        int ele=pre[ind++];
        TreeNode*root=new TreeNode(ele);
        int pos=m[ele];
        root->left=ans(pre,in,ind,st,pos-1,n,m);
        root->right=ans(pre,in,ind,pos+1,end,n,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head;
        int preind=0;
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        head=ans(preorder,inorder,preind,0,inorder.size()-1,inorder.size(),m);

       return head;

        
    }
};
