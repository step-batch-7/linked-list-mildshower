#include <stdio.h>
#include <assert.h>
#include "../list.h"

void test_add_to_end(void)
{
  printf("Should add new element at end\n");
  List_ptr list = create_list();
  assert(add_to_end(list, 0));
  assert(list->count == 1);
  printf("\t\t--passed\n\n");
}

int main(void)
{
  test_add_to_end();

  return 0;
}