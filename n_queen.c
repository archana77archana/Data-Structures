#include<stdio.h>
#include<conio.h>
#include<math.h>

int a[30],count=0;

int place(int pos)
{
 int i;
 //pos stores the one which has the 'Q'
 for(i = 1; i < pos; i++)
 {
 //if the iterated position equal to the position passed as input and the diagonals and 90 degree positions
 //not does not hace any problem, we will return 0
  if((a[i] == a[pos]) || ((abs(a[i]-a[pos]) == abs(i-pos))))
   return 0;
 }
 //else return 1
 //then we can prove that it is feasible
 return 1;
}

//Iterates each row and column and prints the matrix
void print_sol(int n)
{
 int i,j;
 count++;
 printf("\n\nSolution #%d:\n",count);
 
 for(i = 1; i <= n; i++)
 {
  for(j = 1; j <= n; j++)
  {
  //prints if the position of queen
   if(a[i] == j)
    printf("Q\t");
    
    //else just passes off with a tab position left
   else
    printf("*\t");
  }
  printf("\n");
 }
}

//has the row as input
void queen(int n)
{
 int k = 1;
 a[k] = 0;
 while(k != 0)
 {
  a[k] = a[k]+1;
  
  //checks that the row is less than the max no. and if it is not the correct place 
  while((a[k] <= n) && !place(k))
  //go to the next place
   a[k]++;
  if(a[k] <= n)
  {
  //if we reach the last node of the matrix, just print the matrix
   if(k == n)
    print_sol(n);
   else
   {
   //else just go the next noded, and print that node as 0
    k++;
    a[k] = 0;
   }
  }
  else
   k--;
 }
}
void main()
{
 int i,n;
 clrscr();
 
 //give the max no
 printf("Enter the number of Queens\n");
 scanf("%d",&n);
 
 //do the printing of the solution
 queen(n);
 printf("\nTotal solutions=%d",count);
 getch();
}
