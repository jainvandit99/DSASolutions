#include <stdc++.h>
using namespace std;
vector<char> array1 = {'a','b','c','d'};
vector<char> array2 = {'x','y','a','w','z'};
vector<char> array3 = {'x','y','w','z'};

//Function should take input as two arrays of characters (alphabets)
//Should return true if common element is found
//Should return false if no common element is found

//Solution in O(n2) using two for loops
bool doesContainCommonElementN2(vector<char> arr1, vector<char> arr2){
    for(int i=0;i<arr1.size(); i++){
        for(int j=0;j<arr2.size();j++){
            if(arr1[i] == arr2[j]){
                return true;
            }
        }
    }
    return false;
}

//Solution in O(n) using map to check if character has occured before
bool doesContainCommonElementN(vector<char> arr1, vector<char> arr2){
    map<char,bool> m1; //Space Complexity becomes O(1)
    for(int i=0; i<arr1.size(); i++){
        m1[arr1[i]] = true;
    }
    for(int i=0; i<arr2.size(); i++){
        if(m1[arr2[i]]){
            return true;
        }
    }
    return false;
}

int main(){
    doesContainCommonElementN2(array1,array2)? cout<<"Found in O(n2) \n" : cout<<"Not Found in O(n2) \n";
    doesContainCommonElementN(array1,array2)? cout<<"Found in O(n) \n" : cout<<"Not Found in O(n) \n";
    doesContainCommonElementN2(array1,array3)? cout<<"Found in O(n2) \n" : cout<<"Not Found in O(n2) \n";
    doesContainCommonElementN(array1,array3)? cout<<"Found in O(n) \n" : cout<<"Not Found in O(n) \n";
}