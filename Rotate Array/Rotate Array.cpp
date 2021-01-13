//Rotate Array
#include<stdc++.h>
using namespace std;
vector<int> arr1 = {1,2,3,4,5,6,7};
vector<int> arr2 = {-1,-100,3,99};

void printArray(vector<int> arr1){
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

///Solution1 in O(n*k) complexity and O(1) space: swapping each item at a time
vector<int> rotateArrayN2(vector<int> arr1, int k){
    k=k%arr1.size();
    int temp1,temp2;
    for(int i=0;i<k;i++){
        temp2 = arr1[0];
        for(int j=1;j<arr1.size();j++){
            temp1 = arr1[j];
            arr1[j] = temp2;
            temp2 = temp1; 
        }
        arr1[0] = temp2;
    }
    return arr1;
}

///Solution2 in O(n) complexity and O(n) space: creating a new vector and pushing element based on k
vector<int> rotateArrayWithSpace(vector<int> arr1, int k){
    k=k%arr1.size();
    vector<int> answer;
    for(int i=arr1.size()-k;i<arr1.size();i++){
        answer.push_back(arr1[i]);
    }
    for(int i=0;i<arr1.size()-k;i++){
        answer.push_back(arr1[i]);
    }
    return answer;
}

///Solution3 in O(n) complexity and O(1) space: Cyclic swapping
vector<int> rotateArrayN(vector<int> arr1, int k){
    k=k%arr1.size();
    int count = 0;
    int temp1,temp2,forward_pos;
    for(int start = 0; count<arr1.size(); start++){
        int pos = start;
        temp2 = arr1[start];
        do{
            forward_pos = (pos+k)%arr1.size();
            temp1 = arr1[forward_pos];
            arr1[forward_pos] = temp2;
            temp2 = temp1;
            pos = forward_pos;//We don't go one element after the other but one cycle after the other. 0,0+k,0+2k,0+3k-n(if 0+3k exceeds array)
            count++; 
        }while(pos!=start);
    }
    return arr1;
}

int main(){
    cout<<"Arr1 in O(n*k): ";
    printArray(rotateArrayN2(arr1,3));
    cout<<"Arr2 in O(n*k): ";
    printArray(rotateArrayN2(arr2,2));
    cout<<"Arr1 in O(n) space and O(n) time complexity: ";
    printArray(rotateArrayWithSpace(arr1,3));
    cout<<"Arr2 in O(n) space and O(n) time complexity: ";
    printArray(rotateArrayWithSpace(arr2,2));
    cout<<"Arr1 in O(1) space and O(n) time complexity: ";
    printArray(rotateArrayN(arr1,3));
    cout<<"Arr2 in O(1) space and O(n) time complexity: ";
    printArray(rotateArrayN(arr2,2));
}
