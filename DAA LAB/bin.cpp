#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int binary(int arr[],int low ,int high,int key){
          if(low > high){
            return -1;
          }
          int mid=(low+high)/2;
          if(arr[mid]==key){
            return mid;
          }else if(arr[mid]<key){
            return binary(arr,mid+1,high,key);
          }else{
               return binary(arr,low,mid-1,key);
          }
}

int main(){
    int n;
    cout<<"enter the number of elements :";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print(arr,n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    cout<<"\n";
    print(arr,n);
    int key;
    cout<<"enter the key to searched :";
    cin>>n;
    int low=0;
    int high=n-1;
    cout<<"the key is at index";
    cout<<binary(arr,low ,high,key);
    return 0;

}