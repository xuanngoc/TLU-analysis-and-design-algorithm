#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
  int pivot = arr[right];
  int l = left - 1;

  for(int i = left; i < right; i++) {
    if (arr[i] < pivot) {
      l++;
      int temp = arr[l];
      arr[l] = arr[i];
      arr[i] = temp;
    }
  }
}

void quickSort(int arr[], int left, int right) {
  if (left < right) {
    int p = partition(arr, left, right);
    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
  }
}


int main() {
  int arr[] = {2, 43, 12, 3, 2, 12, 2, 123, 44, 22, 44};

  quickSort(arr, 0, 11 - 1);

  for (int i = 0; i < 11 - 1; i++)
    cout << arr[i] << " ";
  cout << endl;
}
