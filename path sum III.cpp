// path sum III 

/* 
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

*/

class Solution {
    void getting_paths(TreeNode*root, int t , int & cnt , vector<int> path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        getting_paths(root->left,t,cnt,path);
        getting_paths(root->right,t,cnt,path);
        long sum=0;
        int size=path.size();
        for(int i=size-1;i>=0;i--){
            sum=sum+path[i];
            if(sum==t){
                cnt++;
            }
        }
        path.pop_back();

        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path ;
        int count =0;
        getting_paths(root,targetSum,count,path);
        return count;

    }
};
