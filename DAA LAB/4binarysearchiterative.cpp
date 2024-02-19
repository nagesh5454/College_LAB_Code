#include<iostream>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int binarysearch(int arr[] ,int n, int key){
    int s=0;
    int e=n;

    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){    
         return mid;
        }else if(arr[mid]<key){
            s= mid+1;
        }else{
            e=mid-1;
        }
     }
    
     return -1;
}
int main(){
    int n;
    cout<<"enter the n:";
    cin>>n;

    int arr[n];
    cout<<"enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print(arr,n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"\n sorted array is :";
    print(arr,n);
    cout<<"\n";
    int key;
    cout<<"enter the key to be search:";
    cin>>key;
    cout<<binarysearch(arr,n,key);
    return 0;
}