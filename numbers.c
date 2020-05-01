#include <stdio.h>
#include "list.h"

void display_menu(void);
int take_number_from_user(void);

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

int main(void)
{
  List_ptr list = create_list();

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
    {
      Status addition_status = add_to_end(list, take_number_from_user());
      printf("Addition was %ssuccessful.", addition_status ? "" : "un");
      break;
    }

    case 'b':
    {
      Status addition_status = add_to_start(list, take_number_from_user());
      printf("Addition was %ssuccessful.", addition_status ? "" : "un");
      break;
    }

    case 'j':
      clear_list(list);
      printf("\nList has been cleared.");
      break;

    case 'l':
      display(list);
      break;

    default:
      printf("\nPlease choose a valid option from the menu.");
      break;
    }

    fflush(stdin);
  }

  return 0;
}