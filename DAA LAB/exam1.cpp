//iterative binrary search
#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int binarysearch(int arr[],int n,int key){
    int si=0;
    int ei=n;
    while(si<=ei){
        int mid=(si+ei)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            ei=mid-1;
        }else{
            si=mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    
    int arr[n];
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    print(arr,n);
    int key;
    cout<<"enter the key to search";
    cin>>key;
    cout<<endl;

    
    cout<<binarysearch(arr,n,key);
    return 0;
}