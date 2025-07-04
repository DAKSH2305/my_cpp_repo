// 1382. Balance a Binary Search Tree



class Solution {
    void inorder(TreeNode* root,vector<int>&nodes )// pass by refernce to kiya karo chacha , change bhi to karni hoti hai
    {
        if(root==NULL){
            return ;
        }
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);

    }
    TreeNode* inorderToBst(int s,int e, vector<int> &data){
        // pass by refernce kiya karo uncle , memory jyada nhi leta.
        if(s>e){
            return NULL;
            

        }
        int mid=s+(e-s)/2;
        TreeNode* temp=new TreeNode(data[mid]);
        temp->right=inorderToBst(mid+1,e,data);
                temp->left=inorderToBst(s,mid-1,data);
                return temp;


    }
public:

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return inorderToBst(0,v.size()-1,v);
        

    }
};
