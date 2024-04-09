#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n=3;
 int items[4]={0,1,2,3};
 int profit[4]={0,50,30,120};
 int weight[4]={0,5,30,30};
 int pw[4];
 
 int W=50;
 int P=0;
 double x[4];  
 int i,j,temp; 
 for(i=1;i<=n;i++)
 {
   pw[i]=profit[i]/weight[i];
   items[i]=i;
 }//pi/wi calculated for each item i
 for(i=1;i<n;i++)
 {
  for(j=1;j<n-i;j++)
   { if(pw[j]<pw[j+1])
      { 
      //sorting item index
        temp=items[j];
        items[j]=items[j+1];
        items[j+1]=temp;     
      
      //sorting profit index
        temp=profit[j];
        profit[j]=profit[j+1];
        profit[j+1]=temp;     
      
      //sorting weight index
        temp=weight[j];
        weight[j]=weight[j+1];
        weight[j+1]=temp;   
      
      //sorting pw
        temp=pw[j];
        pw[j]=pw[j+1];
        pw[j+1]=temp;   
      }//if
    }//for j 
 }//for i
printf("SORTED AS PER P/W-\n");
for(i=1;i<n+1;i++)
{
 printf("Item=%d  weight=%d  Profit=%d  Prof/wt=%d\n",items[i],weight[i],profit[i],pw[i]);
}
for(i=1;i<=n;i++)
{
  if(weight[i]<W && W>0)//entire item can be accomodated
  {
   W=W-weight[i];
   P=P+profit[i];
   x[i]=1.0;    
  }
  else
   break;
}
//item to be partitioned
P+=pw[i]*W;
x[i]=W/weight[i];
W=0;
printf("maximum profit- %d",P);
for(i=1;i<=n;i++)
 printf("\nFraction of item-%d taken= %f\n",items[i],x[i]);
}//main