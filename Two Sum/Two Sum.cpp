//Google Interview Question From Youtube. Link: https://www.youtube.com/watch?v=XKu_SEDAykw
// Given an input of numbers (Here assume an array or vector) and a sum
//The input is assumed to be a sorted integer array
//Find if a pair of numbers from the array can add up to the given sum
// Numbers can be negative and can be repeated

#include <stdc++.h>
using namespace std;

vector<int> array1 = {1,2,4,4};
vector<int> array2 = {1,2,3,9};
vector<int> array3 = {2,7,11,15};

//Solution in O(n2) using nested loops
bool doesContainPairWithSumN2(vector<int> arr1, int sum){
    for(int i=0;i<arr1.size();i++){
        for(int j=i+1;j<arr1.size();j++){
            if(arr1[i]+arr1[j] == sum){
                return true;
            }
        }
    }
    return false;
}

//Solution in O(n) using algorithm like a binary search
bool doesContainPairWithSumN(vector<int> arr1, int sum){
    int start = 0;
    int end = arr1.size() - 1;
    while(start<end){
        int s = arr1[start] + arr1[end];
        if(s == sum) return true;
        else if(s<sum) start++;
        else end--;
    }
    return false;
}
//The above solution works well because it is specified that the input is a sorted array
//In the case that the array is not sorted one way could be to sort the array and do the same soluition as above
//Or

//Solution in O(n) in case the array is not sorted. [Here the space complexity increases to O(n)]
vector<int> doesContainPairWithSumUnsortedN(vector<int>& nums, int target){
    unordered_map<int,int> m1;
    for(int i=0;i<nums.size();i++){
        int diff = target-nums[i];
        if(m1.count(diff)){
            return {i,m1[diff]};
        }
        m1[nums[i]] = i;
    }
    return vector<int>();
}


int main(){
    // doesContainPairWithSumN2(array1, 8)? cout<<"Contains Pair. Searched in O(n2)\n" : cout<<"Doesn't contain pair. Searched in O(n2)\n";
    // doesContainPairWithSumN2(array2, 8)? cout<<"Contains Pair. Searched in O(n2)\n" : cout<<"Doesn't contain pair. Searched in O(n2)\n";
    // doesContainPairWithSumN(array1, 8)? cout<<"Contains Pair. Searched in O(n)\n" : cout<<"Doesn't contain pair. Searched in O(n)\n";
    // doesContainPairWithSumN(array2, 8)? cout<<"Contains Pair. Searched in O(n)\n" : cout<<"Doesn't contain pair. Searched in O(n)\n";
    vector<int> result = doesContainPairWithSumUnsortedN(array3, 9);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}