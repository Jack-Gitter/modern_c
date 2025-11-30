#include <stdio.h>
#include <stdlib.h>

// void quick_sort(int arr[], int left, int right) {}
// merge_sort_pointer_ret()
int* merge_sort_2(int arr[], int left, int right) {

  if (left >= right) {
    int* out = malloc(sizeof(int));
    if (left == right) {
      out[0] = arr[left];
    }
    return out;
  }

  int mid = (left + right) / 2;
  int* left_arr = merge_sort_2(arr, left, mid);
  int* right_arr = merge_sort_2(arr, mid + 1, right);
  int* out_arr = malloc(sizeof(int) * right - left + 1);

  int left_len = mid - left + 1;
  int right_len = right - mid;

  int index = 0;
  int left_index = 0;
  int right_index = 0;

  while (left_index < left_len && right_index < right_len) {
    if (left_arr[left_index] < right_arr[right_index]) {
      out_arr[index++] = left_arr[left_index++];
    } else {
      out_arr[index++] = right_arr[right_index++];
    }
  }

  while (left_index < left_len) {
    out_arr[index++] = left_arr[left_index++];
  }
  while (right_index < right_len) {
    out_arr[index++] = right_arr[right_index++];
  }

  free(left_arr);
  free(right_arr);
  return out_arr;
}
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

bool sorted(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  /*int arr[5] = {5, 4, 3, 2, 1};
  merge_sort(arr, 0, 4);
  bool is_sorted = sorted(arr, 5);
  printf("%d\n", is_sorted);*/

  int arr2[5] = {5, 4, 3, 2, 1};
  int* s = merge_sort_2(arr2, 0, 4);
  for (int i = 0; i < 5; i++) {
    printf("%d\n", s[i]);
  }

  // quick_sort(arr2, 0, 4);
  // for (int i = 0; i < 5; i++) {
  //   printf("%d\n", arr2[i]);
  // }
  // bool is_sorted_2 = sorted(arr2, 5);
  // printf("%d\n", is_sorted_2);
}
