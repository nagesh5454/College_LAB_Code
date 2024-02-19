#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int binarySearch(int arr[], int low, int high, int key){
    if (low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if (key == arr[mid]){
        return mid;
    }
    else if (key < arr[mid]){
        return binarySearch(arr, low, mid - 1, key);
    }
    else{
        return binarySearch(arr, mid + 1, high, key);
    }
}
//iteative
int binarysearchiterative(int arr[] ,int n, int key){
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
int main(void){
    int n;
    cout<<"how many elements: ";
    cin>>n;
    cout<<"enter the elments: ";
    int arr[n] ;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print(arr,n);
     cout<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
     print(arr,n);
     cout<<endl;
    int key;
    cout<<"enter the key element"<<endl;
    cin >> key;
  
    int low = 0, high = n - 1;
    //recursive
    // int index = binarySearch(arr, low, high, key);
    // if (index != -1){
    //     cout << "Element found at index " << index << endl;
    // } else{
    //     cout << "Element not found in the array";
    // }
    
 //iterative
    cout<<binarysearchiterative(arr,n,key);
    return 0;
    
}