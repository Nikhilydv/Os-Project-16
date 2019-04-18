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
int tat[10],totwt=0,totat=0;
for(i=1;i<=p;i++)
{
tat[i]=wt[i]+bt[i];
totwt=totwt+wt[i];
totat=totat+tat[i];
}
float avgwt,avgat;
avgwt=(float)totwt/p;
avgat=(float)totat/p;
printf("\n\n \t\t\t\tROUND ROBIN SCHEDULING ALGORITHM \n\n");
printf("\n\n\t PROCESS \t PROCESS ID  \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n ");
for(i=1;i<=p;i++)
{
printf("\n\t %5d \t\t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,p_id[i],bt[i],wt[i],tat[i]);
}
printf("\n\n \t\t\t\tAVERAGE WAITING TIME\t=%.2f",avgwt);
printf("\n\n \t\t\t\tAVERAGE TURN AROUND TIME=%.2f",avgat);
getch();
}         

