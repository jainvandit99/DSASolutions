#include<stdc++.h>
using namespace std;

vector<int> array1 = {1,2,3,1};
vector<int> array2 = {1,2,3,4};
vector<int> array3 = {1,1,1,3,3,4,3,2,4,2};

bool doesContainDuplicateN(vector<int> arr){
    int result = arr[0];
    for(int i =1;i<arr.size();i++){
        result = result ^ arr[i];
    }
    cout<<result<<endl;
    if(result) return true;
    return false;
}

int main(){
    doesContainDuplicateN(array1)? cout<<"Arr1: Duplicate Exists \n": cout<<"Arr1: Doesn't contain Duplicate \n";
    doesContainDuplicateN(array2)? cout<<"Arr2: Duplicate Exists \n": cout<<"Arr2: Doesn't contain Duplicate \n";
    doesContainDuplicateN(array3)? cout<<"Arr3: Duplicate Exists \n": cout<<"Arr3: Doesn't contain Duplicate \n";

}