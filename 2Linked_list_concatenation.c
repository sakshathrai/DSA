#include <stdio.h>
#include <stdlib.h>
struct node1
{
   int data;
   struct node1 *next;
};

struct node2
{
   int data;
   struct node2 *next;
};

struct node1 *head1 = NULL;
struct node2 *head2 = NULL;

void insert1()
{
   struct node1 *temp;
   temp = (struct node1 *)malloc(sizeof(struct node1));
   printf("Enter the data to be inserted to Linked List 1: ");
   scanf("%d", &temp->data);
   temp->next = NULL;
   if (head1 == NULL)
      head1 = temp;
   else
   {
      struct node1 *t;
      t = head1;
      while (t->next != NULL)
         t = t->next;
      t->next = temp;
   }
}

void insert2()
{
   struct node2 *temp;
   temp = (struct node2 *)malloc(sizeof(struct node2));
   printf("Enter the data to be inserted to Linked List 2: ");
   scanf("%d", &temp->data);
   temp->next = NULL;
   if (head2 == NULL)
      head2 = temp;
   else
   {
      struct node2 *t;
      t = head2;
      while (t->next != NULL)
         t = t->next;
      t->next = temp;
   }
}

void display()
{
   struct node1 *p;
   p = head1;
   while (p != NULL)
   {
      printf("%d->", p->data);
      p = p->next;
   }
   printf("NULL");
}

void con12()
{
   if (head1 == NULL && head2 == NULL)
      printf("Both the Linked Lists are empty");
   else if (head1 == NULL && head2 != NULL){
      head1 = head2;
      display();
   }
      
   else if (head1 != NULL && head2 != NULL)
   {
      struct node1 *p;
      p = head1;
      while (p->next != NULL)
         p = p->next;
      p->next = head2;
      display();
   }
}

int main()
{
   int ch;
   printf("******LINKED LIST CONCATENATION******");
   printf("\n1. Insert in 1st Linked List.\n2. Insert in 2nd Linked List.\n3. Concatenate the Linked List 1 & 2.\n4.Exit.\n");
   while (1)
   {
      printf("\nEnter the Choice: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         insert1();
         break;
      case 2:
         insert2();
         break;
      case 3:
         con12();
         break;
      case 4:
         exit(0);
      default:
         printf("\nInvalid choice!!");
         break;
      }
   }
}