#include <stdint.h>
#include <stdlib.h>
void init(size_t arr[100]) {
  for (int i = 0; i < 100; i++) {
    arr[i] = SIZE_MAX;
  }
}

int find_parent(size_t arr[100], int elem_idx) {
  while (arr[elem_idx] != SIZE_MAX) {
    elem_idx = arr[elem_idx];
  }
  return elem_idx;
}

void find_replace(size_t arr[100], int elem_idx, int new_root) {
  while (arr[elem_idx] != SIZE_MAX) {
    int new_idx = arr[elem_idx];
    arr[elem_idx] = new_root;
    elem_idx = new_idx;
  }
}

// finds the root of search, replaces the second tree with them
void find_compress(size_t arr[100], int search_idx, int replace_idx) {
  size_t root = find_parent(arr, search_idx);
  find_replace(arr, replace_idx, root);
}

void u(size_t arr[100], int left, int right) {
  size_t left_parent = find_parent(arr, left);
  size_t right_parent = find_parent(arr, right);
  find_compress(arr, left, right);
  arr[right_parent] = left_parent;
}

int main() {
  size_t arr[100] = {};
  init(arr);
}
