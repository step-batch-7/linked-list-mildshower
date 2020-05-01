#include <stdio.h>
#include "list.h"

void perform_action(List_ptr numbers, char chosen_option);
void display_menu(void);
int take_number_from_user(void);
int take_position_from_user(void);
void check_presence_of_number(List_ptr numbers);

int take_number_from_user(void)
{
  int given_number;
  printf("\nEnter the number: ");
  scanf("%d", &given_number);
  return given_number;
}

int take_position_from_user(void)
{
  int given_position;
  printf("\nEnter the position: ");
  scanf("%d", &given_position);
  return given_position;
}

void check_presence_of_number(List_ptr numbers)
{
  int given_number = take_number_from_user();
  int found_index = find_position(numbers, given_number);

  if (found_index < 0)
    printf("\n%d does not exist in the list.", given_number);
  else
    printf("\n%d exists in the list and the first occurrance position is %u\n", given_number, found_index);
}

void insert_number(List_ptr numbers, char chosen_option)
{
  int given_number = take_number_from_user(), given_position;
  Status insertion_status;

  switch (chosen_option)
  {
  case 'a':
    insertion_status = add_to_end(numbers, given_number);
    break;

  case 'b':
    insertion_status = add_to_start(numbers, given_number);
    break;

  case 'c':
    given_position = take_position_from_user();
    insertion_status = insert_at(numbers, given_number, given_position);
    break;

  case 'd':
    insertion_status = add_unique(numbers, given_number);
  }

  printf("Insertion was %ssuccessful.", insertion_status ? "" : "un");
}

void remove_number(List_ptr numbers, char chosen_option)
{
  Status removal_status;
  int given_number, given_position;

  switch (chosen_option)
  {
  case 'e':
    removal_status = remove_from_start(numbers);
    break;

  case 'f':
    removal_status = remove_from_end(numbers);
    break;

  case 'g':
    given_position = take_position_from_user();
    removal_status = remove_at(numbers, given_position);
    break;

  case 'h':
    given_number = take_number_from_user();
    removal_status = remove_first_occurrence(numbers, given_number);
    break;

  case 'i':
    given_number = take_number_from_user();
    removal_status = remove_all_occurrences(numbers, given_number);
    break;

  case 'j':
    removal_status = clear_list(numbers);
  }

  printf("\nRemoval was %ssuccessful.", removal_status ? "" : "un");
}

void perform_action(List_ptr numbers, char chosen_option)
{
  if (chosen_option > 96 && chosen_option < 101)
    insert_number(numbers, chosen_option);
  else if (chosen_option > 100 && chosen_option < 107)
    remove_number(numbers, chosen_option);
  else
    switch (chosen_option)
    {
    case 'k':
      check_presence_of_number(numbers);
      break;

    case 'l':
      display(numbers);
      break;

    default:
      printf("\nPlease choose a valid option from the menu.");
    }

  fflush(stdin);
}

void display_menu(void)
{
  printf("\n\nMain Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end(if it already exists, do not insert)\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform\n");
}

int main(void)
{
  List_ptr numbers = create_list();

  while (1)
  {
    display_menu();
    char chosen_option;
    scanf("%c", &chosen_option);

    if (chosen_option == 'm')
      break;

    perform_action(numbers, chosen_option);
  }

  destroy_list(numbers);
  return 0;
}