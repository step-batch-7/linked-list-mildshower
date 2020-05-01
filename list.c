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

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);

  if (new_node == NULL)
    return Failure;

  new_node->next = list->head;
  list->head = new_node;

  if (list->last == NULL)
    list->last = new_node;

  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{

  if (position == 0)
    return add_to_start(list, value);

  if (position == list->count)
    return add_to_end(list, value);

  if (position > list->count || position < 0)
    return Failure;

  Node_ptr p_walker = list->head;

  for (unsigned curr_pos = 1; curr_pos < position; curr_pos++)
  {
    p_walker = p_walker->next;
  }

  Node_ptr new_node = create_node(value);

  if (new_node == NULL)
    return Failure;

  new_node->next = p_walker->next;
  p_walker->next = new_node;
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

Status remove_from_start(List_ptr list)
{
  if (list->count == 0)
    return Failure;

  Node_ptr node_to_remove = list->head;
  list->head = list->head->next;
  free(node_to_remove);
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list)
{
  if (list->count == 0)
    return Failure;

  if (list->count == 1)
    return clear_list(list);

  Node_ptr p_walker = list->head;

  while (p_walker->next != list->last)
  {
    p_walker = p_walker->next;
  }

  free(p_walker->next);
  p_walker->next = NULL;
  list->last = p_walker;
  list->count--;
  return Success;
}

Status clear_list(List_ptr list)
{
  Node_ptr node_to_remove, p_walker = list->head;

  while (p_walker != NULL)
  {
    node_to_remove = p_walker;
    p_walker = p_walker->next;
    free(node_to_remove);
  }

  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}