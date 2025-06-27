// 106. Construct Binary Tree from Inorder and Postorder Traversal

// 


class Solution {
    TreeNode*ans(vector<int> &post, vector<int>& in,int & ind,int st,int end,int n,unordered_map<int,int>& m ){
        // pass by reference - vector and map to save memory , otherwise it will give TLE if passed by values due to too many copies .
        if(ind<0){
            return NULL;

        }
        if(st>end){
            return NULL;

        }
        int ele=post[ind--];
        TreeNode*root=new TreeNode(ele);
        int pos=m[ele];
        /* 
            execute right part before left - because in postorder LRN is followed 
           and since we are traversing from back , Right part come before left 
         */
        root->right=ans(post,in,ind,pos+1,end,n,m);
        root->left=ans(post,in,ind,st,pos-1,n,m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* head;
        int postind=postorder.size()-1;
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        head=ans(postorder,inorder,postind,0,inorder.size()-1,inorder.size(),m);

       return head;
    }
};
