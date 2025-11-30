#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int arr[], int left, int right) {

  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  merge_sort(arr, left, mid);
  merge_sort(arr, mid + 1, right);

  int left_len = mid - left + 1;
  int right_len = right - mid;

  int* left_arr = malloc(sizeof(int) * left_len);
  int* right_arr = malloc(sizeof(int) * right_len);

  for (int i = 0; i < left_len; i++) {
    left_arr[i] = arr[left + i];
  }

  for (int i = 0; i < right_len; i++) {
    right_arr[i] = arr[mid + 1 + i];
  }

  int index = left;
  int left_index = 0;
  int right_index = 0;

  while (left_index < left_len && right_index < right_len) {
    if (left_arr[left_index] < right_arr[right_index]) {
      arr[index++] = left_arr[left_index++];
    } else {
      arr[index++] = right_arr[right_index++];
    }
  }

  while (left_index < left_len) {
    arr[index++] = left_arr[left_index++];
  }
  while (right_index < right_len) {
    arr[index++] = right_arr[right_index++];
  }

  free(left_arr);
  free(right_arr);
}

int main() {
  int arr[5] = {5, 4, 3, 2, 1};
  merge_sort(arr, 0, 4);

  for (int i = 0; i < 5; i++) {
    printf("%d\n", arr[i]);
  }
}
