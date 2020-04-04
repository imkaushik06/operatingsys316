
#include<stdio.h>
#include<conio.h>
int main()
{
	printf("----------------------OPERATING SYSTEM PROJECT CODE-------------------------\n");
	
	printf("\n Name: Kaushik Pandey         Registration No. 11814352          Roll No: 58 ");
	printf("\n\n----------------------------------------------------------------------------\n");
	
    int Burst_time[15],Process_num[15],Waiting_t[15],T_A_T[15];
    int A_T[15],Priority[15],i,j,No_of_process,tot=0,flag,temp,Avg_wt_time,Avg_T_A_T;
    printf("Enter Number of Process:");
    scanf("%d",&No_of_process);
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<No_of_process;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&Burst_time[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&A_T[i]);
        printf("Enter Priority:");
        scanf("%d",&Priority[i]);
        Process_num[i]=i+1;
    }
    for(i=0;i<No_of_process;i++)
    {
        flag=i;
        for(j=i+1;j<No_of_process;j++)
        {
            if(Priority[j]<Priority[flag])
            flag=j;
        }
        temp=Priority[i];
        Priority[i]=Priority[flag];
        Priority[flag]=temp;
        temp=Burst_time[i];
        Burst_time[i]=Burst_time[flag];
        Burst_time[flag]=temp;
        temp=Process_num[i];
        Process_num[i]=Process_num[flag];
        Process_num[flag]=temp;
    }
    Waiting_t[0]=0;  
    for(i=1;i<No_of_process;i++)
    {
        Waiting_t[i]=0;
        for(j=0;j<i;j++)
            Waiting_t[i]+=Burst_time[j];
        tot+=Waiting_t[i];
    }
    Avg_wt_time=tot/No_of_process;  
    tot=0;
    printf("\n------------------------------------------------------------------------------------------------------------------");
    printf("\nProcess\t                   Burst Time        Waiting Time             Turnaround Time");
    for(i=0;i<No_of_process;i++)
    {
        T_A_T[i]=Burst_time[i]+Waiting_t[i];  
        tot+=T_A_T[i];
               printf("\nProcess %d       \t %d\t        \t %d\t              \t %d",Process_num[i],Burst_time[i],Waiting_t[i],T_A_T[i]);
    }
        printf("\n-----------------------------------------------------------------------------------------------------------------");
    Avg_T_A_T=tot/No_of_process;
    printf("\n\nAverage Waiting Time = %d",Avg_wt_time);
    printf("\nAverage Turnaround Time = %d",Avg_T_A_T);
    return 0;
}

