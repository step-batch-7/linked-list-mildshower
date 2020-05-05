#include <stdio.h>
#include <assert.h>
#include "../list.h"

void test_add_to_end(void)
{
  printf("\n\nTesting add_to_end\n\n");

  List_ptr list = create_list();
  printf("\tShould add new element at End when list is empty\n");
  assert(add_to_end(list, 0));
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould add new element at End when list has elements\n");
  assert(add_to_end(list, 1));
  assert(list->last->value == 1);
  assert(list->count == 2);
  printf("\t\t--passed\n\n");
}

void test_add_to_start(void)
{
  printf("\n\nTesting add_to_start\n\n");

  List_ptr list = create_list();
  printf("\tShould add new element at Start when list is empty\n");
  assert(add_to_start(list, 0));
  assert(list->head->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould add new element at Start when list has elements\n");
  assert(add_to_start(list, 1));
  assert(list->head->value == 1);
  assert(list->count == 2);
  printf("\t\t--passed\n\n");
}

void test_insert_at(void)
{
  printf("\n\nTesting insert_at\n\n");

  List_ptr list = create_list();
  printf("\tShould add new element at the given valid position\n");
  assert(insert_at(list, 0, 0));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould not add new element a position is given that exceeds allowed limit\n");
  assert(!insert_at(list, 0, 10));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould not add new element a negative position is given\n");
  assert(!insert_at(list, 0, 10));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();

  return 0;
}