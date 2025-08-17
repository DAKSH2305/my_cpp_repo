//739. Daily Temperatures
// monotonic stack 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                
                
                res[st.top()]=i-st.top();


                st.pop();
            }
            st.push(i);
            
        }
        res.push_back(0);
        return res;
    }
}
