// bucket sort code

#include <iostream>
#include<vector>
using namespace std;

void bucketSort(int arr[], int size){
    vector<vector<float>> bucket(size , vector<float>());
    for(int i=0;i<size;i++){
        int index = arr[i]*size;
        bucket[index].push_back(arr[i]);
        
    }
    for(int i=0;i<size;i++){
        if(!bucket[i].empty()){
        sort(bucket[i].begin(),bucket[i].end())
        }
    }
    int k=0;
    for(int i=0;i<size;i++){
        for( int j=0;j<bucket[i].size(); j++){
            arr[k++] = bucket[i][j];
        }
    }
    
}
int main()
{ float arr[]= {0.12 , 0.14 , 0.34 , 0.18, 0.42};
int size = sizeof(arr)/sizeof(arr[0]);
bucketSort(arr , size);
for(int i =0;i<size; i++){
    cout<< arr[i]<<" ";
    
}
    

    return 0;
}
