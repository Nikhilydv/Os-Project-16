#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
int n;
printf("\t\t\t\t\tENTER THE NUMBER OF PROCESSES \n\t\t\t\t\t");
 scanf("%d",&n);
 int p;
 p=n;
 int ts;
  printf("\n\t\t\t\t\tEnter the Timeslice\n\t\t\t\t\t");
 scanf("%d",&ts);
system("cls");
 int p_id[10],bt[10],bt1[10];
 int i;
 for(i=1;i<=n;i++)
{
printf("\n\t\t\t\t\tEnter the process ID %d \n\t\t\t\t\t",i);
scanf("%d",&p_id[i]);
printf("\n\t\t\t\t\tEnter the Burst Time for the process \n\t\t\t\t\t");
scanf("%d",&bt[i]);
bt1[i]=bt[i];
system("cls");
}
 int wt[10];
int flag[10];
for(i=1;i<=n;i++)
{
  flag[i]=1;
  wt[i]=0;
 }
 int j;
while(n!=0)
 {
   for(i=1;i<=n;i++)
   {
     if(bt1[i]>=ts)
     {
	 for(j=1;j<=n;j++)
       {
	  if((i!=j)&&(flag[i]==1)&&(bt1[j]!=0))
	  wt[j]+=ts;
       }
 bt1[i]-=ts;
 if(bt1[i]==0)
{
flag[i]=0;
n--;
}
}
else
{
  for(j=1;j<=n;j++)
      {
	  if((i!=j)&&(flag[i]==1)&&(bt1[j]!=0))
	  wt[j]+=bt1[i];
       }
bt1[i]=0;
n--;
flag[i]=0;
}
 }
}
}         

