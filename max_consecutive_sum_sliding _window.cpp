// program to find max sum of consecutive 3 elements in vector .
// approach - sliding window
// Time Complexity: O(n)
//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
void  largesum(vector<int> v,int n){
    int sum;
    int ans;

    int a=0;
    int b=2;
    while(b<n-1){    
        sum=v[a]+v[a+1]+v[b]
        ans=max(sum,sum-v[a]+v[b+1]);
        a++;
        b++;
    }
    cout<<ans;  
    
}
int main() {
    vector<int> b={3,1,6,2,8,9,2,0};
    largesum(b,8);
    

    return 0;
}
