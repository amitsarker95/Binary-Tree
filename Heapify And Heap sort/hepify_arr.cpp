#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){

    int tmp;
    tmp  = *a;
    *a = *b;
    *b = tmp;

}

void heapify(int *arr,int n,int curr){
    int larg = curr;
    int leftChild = 2*larg+1;
    int rightChild = 2*larg+2;

    if(leftChild<n && arr[leftChild] > arr[larg]){
        larg = leftChild;
    }
    if(rightChild<n && arr[rightChild] > arr[larg]){
        larg = rightChild;
    }
    if(larg != curr){
        swap(arr[larg],arr[curr]);
        heapify(arr,n,larg);
    }


}
void heapSort(int *arr,int n){
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }

}
void printArr(int *arr,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"Before Heapify : "<<endl;
printArr(arr,n);
int nonLeaf = (n/2)-1;

for(int i=nonLeaf;i>=0;i--){
    heapify(arr,n,i);
}
cout<<"After Heapify : "<<endl;
printArr(arr,n);
heapSort(arr,n);
cout<<"After Heap Sort : "<<endl;
printArr(arr,n);

return 0;
}
