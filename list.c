#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_ptr create_node(int value)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;

  return node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));

  if (list != NULL)
  {

    list->head = NULL;
    list->last = NULL;
    list->count = 0;
  }

  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);

  if (new_node == NULL)
    return Failure;

  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }

  list->last = new_node;
  list->count++;
  return Success;
}

void display(List_ptr list)
{
  Node_ptr p_walker = list->head;
  unsigned position = 0;
  printf("\nHere is the List:\n");

  while (p_walker != NULL)
  {
    printf("%3u -> %d\n", position, p_walker->value);
    position++;
    p_walker = p_walker->next;
  }
}