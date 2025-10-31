// BALANCED BINARY TREE

class Solution {
    pair<bool,int> isBalancedfast(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        pair<int,int> left= isBalancedfast(root->left);
        pair<int,int> right= isBalancedfast(root->right); 
        

        bool leftans=left.first;
        bool rightans= right.first;
        bool diff = abs(left.second-right.second)<=1;

        pair<bool,int> ans;
        ans.second = max(left.second,right.second)+1;
        if( leftans&& rightans && diff){
            ans.first=true;
        }
        else{
            ans.first=false;

        }
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        
        return isBalancedfast(root).first;

    }
};
