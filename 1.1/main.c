#include <stdio.h>
#include <stdlib.h>

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {

  double a[5] = {[0] = 9.0, [1] = 2.9, [4] = 3.E+25, [3] = .00007};

  for (size_t i = 0; i < 5; i++) {
    printf("element %zu is %g, \t its square is %g\n", i, a[i], a[i] * a[i]);
  }

  return EXIT_SUCCESS;
}
