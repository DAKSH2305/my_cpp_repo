// 216. Combination Sum III


class Solution {
    void backtrack(int start, int k, int n, vector<int>& path, vector<vector<int>>& ans){
        if(path.size()==k&& n==0){
            ans.push_back(path);
            return ;

        }
        if(path.size()>k || n<0) return;
        for(int i=start; i<=9;++i){
            path.push_back(i);
            backtrack(i+1,k,n-i,path,ans);
            path.pop_back();
        }


    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if ((n > (45 - ((9 - k) * ((10 - k) / 2)))) || (n < (k * (k + 1) / 2)))   


{
            cout<<"i am here";
            return ans;
        }
   
        vector<int> path;
        backtrack(1, k, n, path, ans);
       return ans;
          
    }
   
};
