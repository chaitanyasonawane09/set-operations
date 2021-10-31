
#include<stdio.h>
void accept(int *p,int n);
void display(int *q,int n);
int set(int *p,int *q,int m,int n);
void union2(int *p,int *q,int m,int n);
void sort(int *m,int n);
void inter2(int *p,int *q,int m,int n);
void diff2(int *p,int *q,int m,int n);
void symdiff2(int *p,int *q,int m,int n);
int main()
{
    int n,m;
    printf("enter the no of elements of set 'a' : ");
    scanf("%d",&m);
    printf("enter the no of elements of set 'b' : ");
    scanf("%d",&n);
     int a[m];
     int b[n];
     printf("\n enter element of set a : ");
     accept(a,m);
     printf("\n enter element of set b : ");
     accept(b,n);
    printf("\n  element of set a\n");
     display(a,m);
    printf("\n  element of set b\n");
     display(b,n);
     set(a,b,m,n);
}
   int set(int *p,int *q,int m,int n)
   {
       int o;
    printf("\n\nenter the no of process \n 1.union \n 2.intersection \n 3.difference \n 4.Symmetric difference of two sets \n 5.exit \n ");
  scanf("%d",&o);
  if(o==5)
    return 0;
  else
  {
  switch(o)
{
   case 1:  union2(p,q,m,n);
             break;
    case 2: inter2(p,q,m,n);
            break;
    case 3: diff2(p,q,m,n);
            break;
    case 4:symdiff2(p,q,m,n);
    break;
     return 0;
}
  }

}
void accept(int *p,int n)
{

  for(int i=0;i<n;i++)
  {
      scanf("%d",&*(p+i));
  }
}
void display(int *q,int n)
{

    for(int i=0;i<n;i++)
    {
        printf("\n%d",*(q+i));
    }
    printf("\n");
}
void sort(int *m,int n)
{
    for(int k=0;k<n-1;k++)
    {
        for(int j=0;j<n-1;j++)
        {
          if(*(m+j)>*(m+j+1))
          {
              int temp=*(m+j);
              *(m+j)=*(m+j+1);
              *(m+j+1)=temp;

          }
        }

    }
}
void union2(int *p,int *q,int m,int n)
{
    int k=0,union1[100],i,j;
   for(i=0;i<m;i++)
   {
      union1[k]=*(p+i);
      k++;
   }
   for(i=0;i<n;i++)
   {
     // int f=0;
       for(j=0;j<m;j++)
       {
           if(*(q+i)==*(p+j))
           {
               //f=1;
           break;
           }
       }
      // if(f==0)
      if(j==m)
       {
           union1[k]=*(q+i);
           k++;
       }
   }
   printf("\n\n************************union of a and b****************************") ;
     display(union1,k);

       set(p,q,m,n);

}

void inter2(int *p,int *q,int m,int n)
{
    sort(p,m);
    sort(q,n);
    int inter1[100];
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
       if(*(p+i)<*(q+j))
       {
           i++;

       }
        else if(*(p+i)>*(q+j))
        {
            j++;


        }
        else if(*(p+i)==*(q+j))
                {
                  inter1[k]=*(p+i);
                  i++;
                  j++;
                  k++;
                }
}
      printf("\n\n************************intersection of a and b****************************") ;
       display(inter1,k);
         set(p,q,m,n);
}

void diff2(int *p,int *q,int m,int n)
{
 int inter[100],k=0;
 for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)

{
    if(*(p+i)==*(q+j))
    {
       inter[k]=*(p+i);
       k++;
       break;
    }
}
}

printf("\n*********************the difference of a and b*************************** ");
printf("\n a-b : ");
for(int i=0;i<m;i++)
{
    int f=0;
    for(int j=0;j<k;j++)

{
    if(*(p+i)==*(inter+j))
    {
       f=1;
       break;
    }
}
if(f==0)
{
    printf("%d\t",*(p+i));
}
}

printf("\n b-a : ");
for(int i=0;i<n;i++)
{
    int f=0;
    for(int j=0;j<k;j++)

{
    if(*(q+i)==*(inter+j))
    {
       f=1;
       break;
    }
}
if(f==0)
{
    printf("%d\t",*(q+i));
}
}
  set(p,q,m,n);
}


void symdiff2(int *p,int *q,int m,int n)
{
    int inter[100],k=0;
 for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)

{
    if(*(p+i)==*(q+j))
    {
       inter[k]=*(p+i);
       k++;
       break;
    }
}
}

printf("\n*********************the symmetric difference of a and b*************************** ");
printf("\n");
for(int i=0;i<m;i++)
{
    int f=0;
    for(int j=0;j<k;j++)

{
    if(*(p+i)==*(inter+j))
    {
       f=1;
       break;
    }
}
if(f==0)
{
    printf("%d\t",*(p+i));
}
}

for(int i=0;i<n;i++)
{
    int f=0;
    for(int j=0;j<k;j++)

{
    if(*(q+i)==*(inter+j))
    {
       f=1;
       break;
    }
}
if(f==0)
{
    printf("%d\t",*(q+i));
}
}
  set(p,q,m,n);
}

















