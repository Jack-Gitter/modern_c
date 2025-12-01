#include <stdio.h>
#include <stdlib.h>

void quick_sort(int arr[], int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot_idx = (right + left) / 2;
  int* new_arr = malloc(sizeof(int) * (right - left + 1));

  int new_arr_idx = 0;
  for (int i = left; i <= right; i++) {
    if (arr[i] < arr[pivot_idx]) {
      new_arr[new_arr_idx++] = arr[i];
    }
  }

  int new_mid = left + new_arr_idx;
  new_arr[new_arr_idx++] = arr[pivot_idx];

  for (int i = left; i <= right; i++) {
    if (i != pivot_idx && arr[i] >= arr[pivot_idx]) {
      new_arr[new_arr_idx++] = arr[i];
    }
  }

  new_arr_idx = 0;
  for (int i = left; i <= right; i++) {
    arr[i] = new_arr[new_arr_idx++];
  }

  quick_sort(arr, left, new_mid);
  quick_sort(arr, new_mid + 1, right);
  free(new_arr);
}

int* merge_sort_2(int arr[], int left, int right) {
  if (left >= right) {
    if (left > right) {
      return NULL;
    }
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
  // merge sort void return
  int arr[5] = {5, 4, 3, 2, 1};
  merge_sort(arr, 0, 4);
  bool merge_sort_is_sorted = sorted(arr, 5);
  printf("merge sort 1 is sorted?:\n");
  printf("%d\n", merge_sort_is_sorted);

  // merge sort int* return
  int arr2[5] = {
      5, 4, 3, 2, 1,
  };
  int* merge_sort_2_res = merge_sort_2(arr2, 0, 4);
  bool merge_sort_2_is_sorted = sorted(merge_sort_2_res, 5);
  printf("merge sort 2 is sorted?:\n");
  printf("%d\n", merge_sort_2_is_sorted);
  free(merge_sort_2_res);

  // quick sort
  int arr3[5] = {
      5, 4, 3, 2, 1,
  };
  quick_sort(arr3, 0, 4);
  bool quick_sort_is_sorted = sorted(arr3, 5);
  printf("quick sort is sorted?:\n");
  printf("%d\n", quick_sort_is_sorted);
}
