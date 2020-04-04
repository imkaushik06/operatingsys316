 
#include<stdio.h>
#include<conio.h>
int main()
{
    int Burst_T[15],Process_no[15],Waiting_T[15],T_A_T[15];
    int A_T[15],Prior[15],i,j,Number_of_Process,tot=0,flag,temp,Avg_Waiting_T,Avg_T_A_T;
    printf("Enter Number of Process:");
    scanf("%d",&Number_of_Process);
    printf("\nEnter Burst Time and Prior\n");
    for(i=0;i<Number_of_Process;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&Burst_T[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&A_T[i]);
        printf("Enter Prior:");
        scanf("%d",&Prior[i]);
        Process_no[i]=i+1;
    }
    for(i=0;i<Number_of_Process;i++)
    {
        flag=i;
        for(j=i+1;j<Number_of_Process;j++)
        {
            if(Prior[j]<Prior[flag])
            flag=j;
        }
        temp=Prior[i];
        Prior[i]=Prior[flag];
        Prior[flag]=temp;
        temp=Burst_T[i];
        Burst_T[i]=Burst_T[flag];
        Burst_T[flag]=temp;
        temp=Process_no[i];
        Process_no[i]=Process_no[flag];
        Process_no[flag]=temp;
    }
    Waiting_T[0]=0;  
    for(i=1;i<Number_of_Process;i++)
    {
        Waiting_T[i]=0;
        for(j=0;j<i;j++)
            Waiting_T[i]+=Burst_T[j];
        tot+=Waiting_T[i];
    }
    Avg_Waiting_T=tot/Number_of_Process;  
    tot=0;
    printf("------------------------------------------------------------------------------------------------------------------");
    printf("\nProcess\t       B.T.              W.T.                T A T");
    for(i=0;i<Number_of_Process;i++)
    {
        T_A_T[i]=Burst_T[i]+Waiting_T[i];  
        tot+=T_A_T[i];
               printf("\nProcess %d \t %d\t \t   %d\t\t%d",Process_no[i],Burst_T[i],Waiting_T[i],T_A_T[i]);
    }
        printf("\n-----------------------------------------------------------------------------------------------------------------");
    Avg_T_A_T=tot/Number_of_Process;
    printf("\n\nAvg Waiting Time = %d",Avg_Waiting_T);
    printf("\nAvg Turn Around Time = %d",Avg_T_A_T);
    return 0;
}

