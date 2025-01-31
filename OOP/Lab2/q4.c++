// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int *unique(int *arr,int size){
    int *uniqueArray = new int[size];
    int index=0;
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < index; j++) {
            if (arr[i] == uniqueArray[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueArray[index] = arr[i];
            index++;
        }
    }
    int *uniqueArr = new int[index];
    for(int i=0;i<index;i++){
        uniqueArr[i]=uniqueArray[i];
    }
    delete[] uniqueArray;
    
    return uniqueArr;
}
int main() {
int size;
cout<<"enter number of elements"<<endl;
cin>>size;

int *arr = new int[size];
for(int i=0;i<size;i++){
    cout<<"enter element"<<endl;
    cin>>arr[i];
}
int *uniqueArr = unique(arr,size);

int uniqueSize=0;

while(uniqueArr[uniqueSize]) uniqueSize++;
cout<<"\nUnique elements"<<endl<<endl;
for(int i=0;i<uniqueSize;i++){
    cout<<uniqueArr[i]<<endl;
}
delete [] uniqueArr;
    return 0;
}
