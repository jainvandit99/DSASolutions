/* 
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [0]
Output: 0

Example 4:
Input: nums = [-1]
Output: -1

Example 5:
Input: nums = [-2147483647]
Output: -2147483647

Constraints:
1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1

*/

#include<stdc++.h>
using namespace std;

vector<int> array1 = {-2,1,-3,4,-1,2,1,-5,4};
vector<int> array2 = {1};
vector<int> array3 = {0};
vector<int> array4 = {-2147483647};
vector<int> array5 = {-1};


//Solution in O(n2)
int maxSumContagiousArrayN2(vector<int> arr1){
    if(!(arr1.size() > 0)){
        return 0;
    }
    int max_sum = arr1[0];
    for(int i=0;i<arr1.size();i++){
        int max1 = arr1[i];
        int sum = arr1[i];
        for(int j=i+1;j<arr1.size();j++){
            sum+=arr1[j];
            max1 = max(max1,sum);
        }
        max_sum = max(max_sum,max1);
    }
    return max_sum;
}

//Solution in O(n). This method is called the Kadane's algorithm. Link: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
int maxSumContagiousArrayN(vector<int> arr1){
    if(!(arr1.size() > 0)){
        return 0;
    }
    int max_till_now = arr1[0];
    int max_with_current = arr1[0];
    for(int i=1;i<arr1.size();i++){                                 //Loop stars from index = 1 because the first element is already taken care of in max_till_now and max_with_current
        max_with_current = max(max_with_current+arr1[i],arr1[i]);
        max_till_now = max(max_till_now, max_with_current);
    }
    return max_till_now;
}

int main(){
    cout<<"Arr1: "<<maxSumContagiousArrayN2(array1)<<"\n";
    cout<<"Arr2: "<<maxSumContagiousArrayN2(array2)<<"\n";
    cout<<"Arr3: "<<maxSumContagiousArrayN2(array3)<<"\n";
    cout<<"Arr4: "<<maxSumContagiousArrayN2(array4)<<"\n";
    cout<<"Arr5: "<<maxSumContagiousArrayN2(array5)<<"\n";

    cout<<"Arr1: "<<maxSumContagiousArrayN(array1)<<"\n";
    cout<<"Arr2: "<<maxSumContagiousArrayN(array2)<<"\n";
    cout<<"Arr3: "<<maxSumContagiousArrayN(array3)<<"\n";
    cout<<"Arr4: "<<maxSumContagiousArrayN(array4)<<"\n";
    cout<<"Arr5: "<<maxSumContagiousArrayN(array5)<<"\n";
}
