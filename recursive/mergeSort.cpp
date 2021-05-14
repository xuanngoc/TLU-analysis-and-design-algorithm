#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int temp[right - left + 1];

  int i = left;
  int k = mid + 1;
  int index = 0;

  while(i <= mid && k <= right) {
    if (arr[i] <= arr[k]) {
      temp[index] = arr[i];
      i++;
      index++;
    } else {
      temp[index] = arr[k];
      k++;
      index++;
    }
  }

  while(i <= mid) {
    temp[index] = arr[i];
    i++;
    index++;
  }

  while(k <= right) {
    temp[index] = arr[k];
    k++;
    index++;
  }


  for(i = left; i <= right; i++) {
    arr[i] = temp[i - left];
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}


// A32007- Bui Xuan Ngoc
int main() {
  int arr[] = {4, 2, 1, 3, 4, 56, 13, 24, 5, 9, 77};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < arr_size; i++)
    cout << arr[i] << " ";
  cout<<endl;
  mergeSort(arr, 0, arr_size - 1);
  for (int i = 0; i < arr_size - 1; i++)
    cout << arr[i] << " ";
}
