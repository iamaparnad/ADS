#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dnode
{
  int data;
  struct dnode *left;
  struct dnode *right;
};
  typedef struct dnode dnode;
  dnode *first;
  void insertfirst();
  void insertlast();
  void display();
  void main()

  {

    int choice=0,item;
    clrscr();
    while(1)
    {
      printf("\n*********************************\n");
      printf("\n____________options available________________\n");
      printf("\n1.insertfirst\n2.insertlast\n3.display\n4.exit\n");
      printf("\nenter your choice\n");
      scanf("%d",&choice);


    switch(choice)
    {
    case 1:
    printf("\nenter any value....\n");
    scanf("%d",&item);
    insertfirst(item);
    break;
    case 2:
    printf("\nenter any value....\n");
    scanf("%d",&item);
    insertlast(item);
    break;
    case 3:
    display(&first);
    break;
    case 4:
    exit(0);
    default:
    printf("\nINVALID CHOICE!!!PLEASE ENTER CORRECT CHOICE\n");
    }
  }
}

  dnode* getnode()
  {
    dnode *t;
    t=(dnode *)malloc(sizeof(dnode));
    return t;
  }

void insertfirst(dnode **first,int item)
 {
  dnode *temp;
  temp=getnode();
  temp->data=item;
  temp->left=NULL;
  if((*first)==NULL)
  temp->right=NULL;
  else
  {
    temp->right=(*first);
    (*first)->left=temp;
  }
  (*first)=temp;
 }
 void insertlast(dnode **first,int item)
  {
    dnode *temp,*current;
    temp=getnode();
    temp->data=item;
    temp->right=NULL;
    if((*first)==NULL)
    {
      temp->left=NULL;
      (*first)=temp;
    }
    else
    {
      current=(*first);
      while(current->right!=NULL)
      current=current->right;
      temp->left=current;
      current->right=temp;
    }
  }
  void display(dnode **first)
  {
  dnode *temp;
  printf("\n printing values....\n");
  temp=*first;
  while(temp!=NULL)
   {
     printf("%d\n",temp->data);
     temp=temp->right;
   }
 }
