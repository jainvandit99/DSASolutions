/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations. */

#include<stdc++.h>
using namespace std;

vector<int> array1 = {0,1,0,3,12};
vector<int> array2 = {0};
vector<int> array3 = {1,0};
vector<int> array4 = {0,1};
vector<int> array5 = {0,1,0,0,5,4,3,0,0,0,0,0,2};   


void printArray(vector<int> arr1){
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

//Solution in O(n2)
vector<int> putZeroesInEndN2(vector<int> arr){
    int noOfOperations = 0;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]!=0) continue;
        for(int j=i;j<arr.size()-1;j++){
            if(arr[j+1] == 0) break;
            iter_swap(arr.begin() + j, arr.begin() + j+1);
            noOfOperations++;
        }
    }
    cout<<"Number of Operations in O(n2): "<<noOfOperations<<endl;
    return arr;
}

//Solution in O(n)
vector<int> putZeroesInEndN(vector<int> nums){
    int currentIndex = 0;
    int noOfOperations = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != 0){
            iter_swap(nums.begin() + i,nums.begin() + currentIndex);
            currentIndex++;
            noOfOperations++;
        }
    }
    currentIndex = nums.size()-1;
    cout<<"Number of Operations in O(n): "<<noOfOperations<<endl;
    return nums;
}

int main(){
    cout<<"Arr1: ";
    printArray(putZeroesInEndN2(array1));

    cout<<"Arr1: ";
    printArray(putZeroesInEndN(array1));

    cout<<"Arr2: ";
    printArray(putZeroesInEndN2(array2));

    cout<<"Arr2: ";
    printArray(putZeroesInEndN(array2));

    cout<<"Arr3: ";
    printArray(putZeroesInEndN2(array3));

    cout<<"Arr3: ";
    printArray(putZeroesInEndN(array3));

    cout<<"Arr4: ";
    printArray(putZeroesInEndN2(array4));

    cout<<"Arr4: ";
    printArray(putZeroesInEndN(array4));

    cout<<"Arr5: ";
    printArray(putZeroesInEndN2(array5));

    cout<<"Arr5: ";
    printArray(putZeroesInEndN(array5));

}