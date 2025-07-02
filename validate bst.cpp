// validate binary search tree 

class Solution { 
    /*
    void inorder(vector<int> & vec, TreeNode* root){
        if(root==NULL){
            return ;

        }
        inorder ( vec,root->left);
        vec.push_back(root->val);
        inorder(vec,root->right);
    }
  */
    bool isBST(TreeNode* root, long min, long max){
        if(root==NULL){
            return true;
        }
        if(root->val>min&&root->val<max){
            bool left= isBST(root->left,min,root->val);
            bool right=isBST(root->right,root->val,max);
            return left&&right;
        }
        else{
            return false;
        }

    }
    
public:
    bool isValidBST(TreeNode* root) {
        /* vector<int> v;
        inorder(v,root);
        vector<int> c=v;
        sort(c.begin(),c.end());
        if(c==v){
            return true;
        }
        return false;
        */
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        return isBST(root,LONG_MIN,LONG_MAX);

    }
};
