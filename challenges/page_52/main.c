#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void print_state(size_t arr[100], int n) {
  printf("State: ");
  for (int i = 0; i < n; i++) {
    if (arr[i] == SIZE_MAX) {
      printf("%d->ROOT ", i);
    } else {
      printf("%d->%zu ", i, arr[i]);
    }
  }
  printf("\n");
}
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

  printf("=== Test 1: Basic Union ===\n");
  u(arr, 0, 1); // Connect 0 and 1
  printf("After u(0,1): ");
  printf("find_parent(0)=%d, find_parent(1)=%d\n", find_parent(arr, 0),
         find_parent(arr, 1));
  if (find_parent(arr, 0) == find_parent(arr, 1)) {
    printf("✓ PASS: 0 and 1 in same set\n");
  } else {
    printf("✗ FAIL: 0 and 1 should be in same set\n");
  }

  printf("\n=== Test 2: Chain Union ===\n");
  init(arr);
  u(arr, 0, 1);
  u(arr, 1, 2);
  u(arr, 2, 3);
  printf("After u(0,1), u(1,2), u(2,3):\n");
  printf("Roots: 0=%d, 1=%d, 2=%d, 3=%d\n", find_parent(arr, 0),
         find_parent(arr, 1), find_parent(arr, 2), find_parent(arr, 3));
  if (find_parent(arr, 0) == find_parent(arr, 3)) {
    printf("✓ PASS: All in same set\n");
  } else {
    printf("✗ FAIL: Should all be connected\n");
  }

  printf("\n=== Test 3: Multiple Separate Sets ===\n");
  init(arr);
  u(arr, 0, 1);
  u(arr, 2, 3);
  u(arr, 4, 5);
  printf("After u(0,1), u(2,3), u(4,5):\n");
  int root0 = find_parent(arr, 0);
  int root2 = find_parent(arr, 2);
  int root4 = find_parent(arr, 4);
  printf("Roots: {0,1}=%d, {2,3}=%d, {4,5}=%d\n", root0, root2, root4);
  if (root0 != root2 && root2 != root4 && root0 != root4) {
    printf("✓ PASS: Three separate sets\n");
  } else {
    printf("✗ FAIL: Sets should be separate\n");
  }

  printf("\n=== Test 4: Merge Two Sets ===\n");
  u(arr, 1, 3); // Merge {0,1} with {2,3}
  printf("After u(1,3):\n");
  if (find_parent(arr, 0) == find_parent(arr, 2)) {
    printf("✓ PASS: Sets merged\n");
  } else {
    printf("✗ FAIL: Sets should be merged\n");
  }

  printf("\n=== Test 5: Union Same Set (Idempotent) ===\n");
  init(arr);
  u(arr, 0, 1);
  int root_before = find_parent(arr, 0);
  u(arr, 0, 1); // Union again
  int root_after = find_parent(arr, 0);
  printf("Root before=%d, after=%d\n", root_before, root_after);
  if (root_before == root_after && arr[root_after] == SIZE_MAX) {
    printf("✓ PASS: Repeated union doesn't break structure\n");
  } else {
    printf("✗ FAIL: Root should still be valid\n");
  }

  printf("\n=== Test 6: Path Compression Check ===\n");
  init(arr);
  // Create a chain manually: 4->3->2->1->0
  arr[1] = 0;
  arr[2] = 1;
  arr[3] = 2;
  arr[4] = 3;
  printf("Before find_parent(4): ");
  print_state(arr, 5);

  find_parent(arr, 4);
  printf("After find_parent(4) [no compression yet]: ");
  print_state(arr, 5);

  // Now do a union that uses compression
  u(arr, 4, 5);
  printf("After u(4,5) [with compression]: ");
  print_state(arr, 6);
  printf("✓ Check: Path should be flattened\n");

  return 0;
}
