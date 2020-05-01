#include <stdio.h>
#include "list.h"

void display_menu(void);
int take_number_from_user(void);
void add_number_to_end(List_ptr numbers);
void add_number_to_start(List_ptr numbers);
void insert_number_at_selected_position(List_ptr numbers);
void remove_number_at_start(List_ptr numbers);
void remove_number_at_end(List_ptr numbers);

void display_menu(void)
{
  printf("\n\nMain Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform\n");
}

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

void add_number_to_end(List_ptr numbers)
{
  int given_number = take_number_from_user();
  Status addition_status = add_to_end(numbers, given_number);
  printf("Addition was %ssuccessful.", addition_status ? "" : "un");
}

void add_number_to_start(List_ptr numbers)
{
  int given_number = take_number_from_user();
  Status addition_status = add_to_start(numbers, given_number);
  printf("Addition was %ssuccessful.", addition_status ? "" : "un");
}

void insert_number_at_selected_position(List_ptr numbers)
{
  int given_number = take_number_from_user();
  int given_position = take_position_from_user();
  Status addition_status = insert_at(numbers, given_number, given_position);
  printf("Addition was %ssuccessful.", addition_status ? "" : "un");
}

void remove_number_at_start(List_ptr numbers)
{
  Status removal_status = remove_from_start(numbers);
  printf("\nRemoval was %ssuccessful.", removal_status ? "" : "un");
}

void remove_number_at_end(List_ptr numbers)
{
  Status removal_status = remove_from_end(numbers);
  printf("\nRemoval was %ssuccessful.", removal_status ? "" : "un");
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

    switch (chosen_option)
    {
    case 'a':
      add_number_to_end(numbers);
      break;

    case 'b':
      add_number_to_start(numbers);
      break;

    case 'c':
      insert_number_at_selected_position(numbers);
      break;

    case 'e':
      remove_number_at_start(numbers);
      break;

    case 'f':
      remove_number_at_end(numbers);
      break;

    case 'j':
      clear_list(numbers);
      printf("\nList has been cleared.");
      break;

    case 'l':
      display(numbers);
      break;

    default:
      printf("\nPlease choose a valid option from the menu.");
      break;
    }

    fflush(stdin);
  }

  destroy_list(numbers);
  return 0;
}