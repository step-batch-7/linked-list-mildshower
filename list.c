#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_ptr create_node(int value)
{
  Node_ptr node = malloc(sizeof(Node));

  if (node != NULL)
  {
    node->value = value;
    node->next = NULL;
  }

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

  Node_ptr *ptr_to_set = &list->head;

  if (list->head != NULL)
  {
    ptr_to_set = &list->last->next;
  }

  *ptr_to_set = new_node;
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

  if (position > list->count || position < 0)
    return Failure;

  if (position == 0)
    return add_to_start(list, value);

  if (position == list->count)
    return add_to_end(list, value);

  Node_ptr new_node = create_node(value);

  if (new_node == NULL)
    return Failure;

  Node_ptr p_walker = list->head;

  for (unsigned curr_pos = 1; curr_pos < position; curr_pos++)
  {
    p_walker = p_walker->next;
  }

  new_node->next = p_walker->next;
  p_walker->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  if (find_position(list, value) >= 0)
    return Success;

  return add_to_end(list, value);
}

void display(List_ptr list)
{
  Node_ptr p_walker = list->head;
  unsigned position = 0;
  printf("\nHere is the List with element count %u:\npos -> value\n", list->count);
  while (p_walker != NULL)
  {
    printf("%3u -> %d\n", position, p_walker->value);
    p_walker = p_walker->next;
    position++;
  }
}

Status remove_from_start(List_ptr list)
{
  if (list->count == 0)
    return Failure;

  if (list->count == 1)
    return clear_list(list);

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

Status remove_at(List_ptr list, int position)
{
  if (position >= list->count || position < 0)
    return Failure;

  if (list->count == 1 || position == list->count - 1)
    return remove_from_end(list);

  if (position == 0)
    return remove_from_start(list);

  Node_ptr p_walker = list->head;

  for (int curr_position = 1; curr_position < position; curr_position++)
  {
    p_walker = p_walker->next;
  }

  Node_ptr node_to_remove = p_walker->next;
  p_walker->next = p_walker->next->next;
  free(node_to_remove);
  list->count--;
  return Success;
}

int find_position(List_ptr list, int value)
{
  int position = -1;
  Node_ptr pWalker = list->head;

  for (unsigned index = 0; pWalker != NULL; index++)
  {
    if (pWalker->value == value)
    {
      position = index;
      break;
    }

    pWalker = pWalker->next;
  }

  return position;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int first_occurrence_position = find_position(list, value);

  if (first_occurrence_position < 0)
    return Failure;

  return remove_at(list, first_occurrence_position);
}

Status remove_all_occurrences(List_ptr list, int value)
{
  if (find_position(list, value) < 0)
    return Failure;

  Node_ptr p_walker = list->head;

  if (list->count == 1)
    return remove_from_start(list);

  while (p_walker->next->next != NULL)
  {
    if (p_walker->next->value == value)
    {
      Node_ptr node_to_remove = p_walker->next;
      p_walker->next = p_walker->next->next;
      free(node_to_remove);
      list->count--;
    }
    else
      p_walker = p_walker->next;
  }

  if (list->head->value == value)
    remove_from_start(list);

  if (list->last->value == value)
    remove_from_end(list);

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