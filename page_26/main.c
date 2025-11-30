#include <stdlib.h>

/* word decays into a pointer, the same can be represented with
 * example(char* word, int word_len)
 */
void example(char word[5]) {}

/* word_grid decays into a pointer, the same can be represented with
 * example(char** word_grid)
 */
void another_example(char* word_grid[5]);

/* this is the syntax to accept a function. The function decays to a pointer.
 * The same can be represented with
 * first_class_citizens(void (*another_func)(int))
 */

void first_class_citizens(void another_func(int));

int main() {

  /* this is a pointer to a const char. The pointer itself is also const */

  char const* const path_name = "hello world";

  /* the contents of the pointer is const, the following is uncompileable:
   *     *path_name = "blah";
   *
   * the pointer itself is also const, the following is uncompileable:
   *	path_name = malloc(sizeof(char) * 5);
   */
}
