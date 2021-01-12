//Merge 2 Sorted Arrays
#include <stdc++.h>
using namespace std;

vector<int> array1 = {1,3,5,7,8};
vector<int> array2 = {2,3,4,5,6,7,8,9};

vector<int> mergeSortedArrays(vector<int> arr1, vector<int> arr2){
    if(arr1.size() == 0 && arr2.size() == 0){
        return vector<int>();
    }
    int arr1ptr = 0;
    int arr2ptr = 0;
    vector<int> newArr;
    while(arr1ptr < arr1.size() && arr2ptr < arr2.size()){
        if(arr1[arr1ptr] < arr2[arr2ptr]){
            newArr.push_back(arr1[arr1ptr]);
            arr1ptr++;
        }else{
            newArr.push_back(arr2[arr2ptr]);
            arr2ptr++;
        }
    }
    while(arr2ptr<arr2.size()){
        newArr.push_back(arr2[arr2ptr]);
        arr2ptr++;
    }
    while(arr1ptr<arr1.size()){
        newArr.push_back(arr1[arr1ptr]);
        arr1ptr++;
    }
    return newArr;
}

int main(){
    vector<int> op = mergeSortedArrays(array1,array2);
    for(int i=0;i<op.size();i++){
        cout<<op[i]<<" ";
    }
}