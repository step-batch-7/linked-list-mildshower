#include <stdio.h>
#include <assert.h>
#include "../list.h"

void test_add_to_end(void)
{
  printf("\n\nTesting add_to_end\n\n");

  List_ptr list = create_list();
  printf("\tShould add new number at End when list is empty\n");
  assert(add_to_end(list, 0));
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould add new number at End when list has elements\n");
  assert(add_to_end(list, 1));
  assert(list->last->value == 1);
  assert(list->count == 2);
  printf("\t\t--passed\n\n");
}

void test_add_to_start(void)
{
  printf("\n\nTesting add_to_start\n\n");

  List_ptr list = create_list();
  printf("\tShould add new number at Start when list is empty\n");
  assert(add_to_start(list, 0));
  assert(list->head->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould add new number at Start when list has elements\n");
  assert(add_to_start(list, 1));
  assert(list->head->value == 1);
  assert(list->count == 2);
  printf("\t\t--passed\n\n");
}

void test_insert_at(void)
{
  printf("\n\nTesting insert_at\n\n");

  List_ptr list = create_list();
  printf("\tShould add new number at the given valid position\n");
  assert(insert_at(list, 0, 0));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  add_to_end(list, 2);
  printf("\tShould add new number at middle\n");
  assert(insert_at(list, 1, 1));
  assert(list->head->value == 0);
  assert(list->last->value == 2);
  assert(list->count == 3);
  printf("\t\t--passed\n\n");

  printf("\tShould not add new number a position is given that exceeds allowed limit\n");
  assert(!insert_at(list, 0, 10));
  assert(list->head->value == 0);
  assert(list->last->value == 2);
  assert(list->count == 3);
  printf("\t\t--passed\n\n");

  printf("\tShould not add new number a negative position is given\n");
  assert(!insert_at(list, 0, 10));
  assert(list->head->value == 0);
  assert(list->last->value == 2);
  assert(list->count == 3);
  printf("\t\t--passed\n\n");
}

void test_add_unique(void)
{
  printf("\n\nTesting add_unique\n\n");

  List_ptr list = create_list();
  printf("\tShould add new number if the number is not present in the list\n");
  assert(add_unique(list, 0));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould not add new number if the number is present in the list\n");
  assert(!add_unique(list, 0));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");
}

void test_remove_from_start(void)
{
  printf("\n\nTesting remove_from_start\n\n");

  List_ptr list = create_list();
  add_to_end(list, 0);
  add_to_end(list, 1);
  printf("\tShould remove the first number of the list\n");
  assert(remove_from_start(list));
  assert(list->head->value == 1);
  assert(list->last->value == 1);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould clear the list when only one number is in the list\n");
  assert(remove_from_start(list));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould fail if the list is empty\n");
  assert(!remove_from_start(list));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");
}

void test_remove_from_end(void)
{
  printf("\n\nTesting remove_from_end\n\n");

  List_ptr list = create_list();
  add_to_end(list, 0);
  add_to_end(list, 1);
  printf("\tShould remove the last number of the list\n");
  assert(remove_from_end(list));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould clear the list when only one number is present\n");
  assert(remove_from_end(list));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould fail if the list is empty\n");
  assert(!remove_from_end(list));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");
}

void test_remove_at(void)
{
  printf("\n\nTesting remove_at\n\n");

  List_ptr list = create_list();
  add_to_end(list, 0);
  printf("\tShould fail if exceeded position is given\n");
  assert(!remove_at(list, 10));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould fail if negative position is given\n");
  assert(!remove_at(list, 10));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould remove the number of the given valid position\n");
  assert(remove_at(list, 0));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould fail if the list is empty\n");
  assert(!remove_at(list, 0));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");
}

void test_remove_first_occurrence(void)
{
  printf("\n\nTesting remove_first_occurrence\n\n");

  List_ptr list = create_list();
  add_to_end(list, 0);
  add_to_end(list, 0);
  printf("\tShould first match only\n");
  assert(remove_first_occurrence(list, 0));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould fail if no match exists\n");
  assert(!remove_first_occurrence(list, 1));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould clear list if the list has only one element and that element matches\n");
  assert(remove_first_occurrence(list, 0));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");
}

void test_remove_all_occurrences(void)
{
  printf("\n\nTesting remove_all_occurrences\n\n");

  List_ptr list = create_list();
  add_to_end(list, 0);
  add_to_end(list, 1);
  add_to_end(list, 0);
  printf("\tShould fail if no matches found\n");
  assert(!remove_all_occurrences(list, 2));
  assert(list->head->value == 0);
  assert(list->last->value == 0);
  assert(list->count == 3);
  printf("\t\t--passed\n\n");

  printf("\tShould remove all mathces\n");
  assert(remove_all_occurrences(list, 0));
  assert(list->head->value == 1);
  assert(list->last->value == 1);
  assert(list->count == 1);
  printf("\t\t--passed\n\n");
}

void test_find_position(void)
{
  printf("\n\nTesting find_position\n\n");

  List_ptr list = create_list();
  add_to_end(list, 0);
  add_to_end(list, 0);

  printf("\tShould give first matched position\n");
  assert(find_position(list, 0) == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould give -1 when no match found\n");
  assert(find_position(list, 1) == -1);
  printf("\t\t--passed\n\n");
}

void test_clear_list(void)
{
  printf("\n\nTesting clear_list\n\n");

  List_ptr list = create_list();
  add_to_end(list, 0);
  add_to_end(list, 1);

  printf("\tShould clear the whole list\n");
  assert(clear_list(list));
  assert(list->head == NULL);
  assert(list->last == NULL);
  assert(list->count == 0);
  printf("\t\t--passed\n\n");
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_find_position();
  test_clear_list();

  return 0;
}