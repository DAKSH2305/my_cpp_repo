

// kich nhi karna , bas same question like find all subsets for a set
class Solution {
    int giveSum(vector<int> & temp){
        if(temp.empty()){
            return 0;
        }
        if(temp.size()==1){
            return temp[0];
        }
        int sxor=0;
        for(int i=0;i<temp.size();i++){
            sxor=sxor^temp[i];

        }
        return sxor;
    }
    void solve(vector<int> arr,vector<int> output,int ind,int &totalSum){
        if(ind>=arr.size()){
            int sum=giveSum(output);
            totalSum=totalSum+sum;
            return;
        }
        solve(arr,output,ind+1,totalSum);
        int ele=arr[ind];
        output.push_back(ele);
        
        solve(arr,output,ind+1,totalSum);


    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> output;
        int index=0;
        int XORsum=0;
        solve(nums,output,index,XORsum);
        return XORsum;
        
    }
};
