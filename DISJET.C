#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct disj
{
 int parent[10];
 int rank[10];
 int n;
 }dis;
 void makeset()
   {

     int i;

     for(i=0;i<dis.n;i++)
     {
      dis.parent[i]=i;
      dis.rank[i]=0;
     }
   }
void displayset()
  {
   int i;
   printf("\n parent array\n");
   for(i=0;i<dis.n;i++)//for printing parent
   {
    printf("%d",dis.parent[i]);
    }
    printf("\n rank array \n");
    for(i=0;i<dis.n;i++)
    {
      printf("%d",dis.rank[i]);//for printing rank
    }

   }
   int find(int x)
   {
    if(dis.parent[x]!=x)
    {
     dis.parent[x]=find(dis.parent[x]);
    }
    return dis.parent[x];
   }
   void Union(int x,int y)
   {
    int xset=find(x);
    int yset=find(y);
    if(xset==yset)
    return;
    if(dis.rank[xset]<dis.rank[yset])
    {
      dis.parent[xset]=yset;
      dis.rank[xset]=-1;
    }
    else if(dis.rank[xset]>dis.rank[yset])
    {
      dis.parent[yset]=xset;
      dis.rank[yset]=-1;
    }
    else
    {
      dis.parent[yset]=xset;
      dis.rank[xset]=dis.rank[xset]+1;
      dis.rank[yset]=-1;
    }
   }
   int main()
   {
    int n,x,y;
    int ch,wish;
    printf("\n how many elements ?");
    scanf("%d",&dis.n);
    makeset();

    do
    {
      printf("\n______________________menu____________________\n");
      printf("\n1.Union\n2.find\n3.display\n4.makeset\n");
      printf("enter choice \n");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:
      printf("\n enter elements to perform union");
      scanf("%d%d",&x,&y);
      Union(x,y);
      break;
      case 2:
      printf("\n enter elements to check if connected components");
      scanf("%d%d",&x,&y);
      if(find(x)==find(y))
      printf("\n connected components\n");
      else
      printf("\n not connected components \n");
      break;
      case 3:
      displayset();
      break;
      case 4:
      makeset();
      break;
      default:
      printf("\n invalid choice\n");
    }
    printf("\n do you wish to continue?(1/0)\n");
    scanf("%d",&wish);
    }
    while(wish==1);
    return 0;
   }