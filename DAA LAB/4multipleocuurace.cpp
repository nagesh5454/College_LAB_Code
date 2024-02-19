#include <iostream>
using namespace std;
int binarySearchCount(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            count++;
            int i = mid - 1;
            while (i >= left && arr[i] == key) {
                count++;
                i--;
            }
            i = mid + 1;
            while (i <= right && arr[i] ==key) {
                count++;
                i++;
            }

            return count;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Target element not found
    return count;
}

int main() {
    int n;
    cout<<"enter the number of  elements";
    cin>>n;
    int arr[n] ;
    cout<<"enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout<<"enter the key:";
    cin>>key;
    int count = binarySearchCount(arr, n,key);
   cout << "Count: " << count << endl;

    return 0;
}
