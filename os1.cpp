#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

float avg_wait_time1=0.0,avg_turnaround_time1=0.0;

int p,wait_time3[50],turnaround_time3[50];
float avg_turnaround_time3=0.0, avg_wait_time3=0.0;

int turnaround_time2[50], position,q,temp1,sum=0,wait_timetwo[50];
float avg_wait_time2,avg_turnaround_time2;
int Total=0,t1=0,t2=0,t3=0;

int i, n, at[50], bt[50], pr[50],j=0,k=0,l=0;
int bursttime1[50],bursttime2[50],bursttime3[50];
int total,x,temp[50],counter=0;
int arrivaltime1[50],arrivaltimetwo[50],prioritytwo[50],processtwo[50],arrivaltimethree[50];

void priority()
{
	for(i=0;i<k;i++)  
    {
        position=i;
        for(q=i+1;q<k;q++)
        {
            if(prioritytwo[q]<prioritytwo
			[position])
            {
                position=q;
            }
        }
        temp1=prioritytwo[i];
        prioritytwo[i]=prioritytwo[position];
        prioritytwo[position]=temp1; 
        
        temp1=bursttime2[i];
        bursttime2[i]=bursttime2[position];
        bursttime2[position]=temp1;
        
        temp1=processtwo[i];
        processtwo[i]=processtwo[position];
        processtwo[position]=temp1;
    }
    wait_timetwo[0]=0;
    for(i=1;i<k;i++)
    {
        wait_timetwo[i]=0;
        for(q=0;q<i;q++)
        {
            wait_timetwo[i]=wait_timetwo[i]+bursttime2[j];
        }
        sum=sum+wait_timetwo[i];
    }
    avg_wait_time2=sum/k;
    sum=0;
    printf("\n \t\tProcess ID\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<k;i++)
    {
    	turnaround_time2[i]=bursttime2[i]+wait_timetwo[i];
        sum=sum+turnaround_time2[i];
        printf("\nProcess[%d]\t\t\t%d\t\t\t%d\t\t\t %d\n",processtwo[i],bursttime2[i],wait_timetwo[i],turnaround_time2[i]);
    }
    avg_turnaround_time2=sum/k;
    printf("\n \t\tAverage Waiting Time is :\t%f",avg_wait_time2);
    printf("\n \t\tAverage Turnaround Time:\t%f\n",avg_turnaround_time2);
    
    for(i=0;i<k;i++)
    {
    	while(bursttime2[i]!=0)
    	{
    		if(bursttime2[i]>10)
    		{
				printf("\nProcess %d of Queue2 is running for 10 units",i+1);
				bursttime2[i]=bursttime2[i]-10;
			}
			else if(bursttime2[i]<=10)
			{
				printf("\nProcess %d of Queue2 is running for %d units",i+1,bursttime2[i]);
				bursttime2[i]=0;
			}
		}
	}

}
void round_robin()
{
	printf("\t\tTime Quantum for Queue1 is 4\n");
	for(i=0;i<j;i++)
	{
		temp[i]=bursttime1[i];
	} 
	printf("\n \t\tProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x=j;
    for(i=0,total=0;x!=0;) 
    { 
    	if(temp[i]<=4&&temp[i]>0) 
        {
			printf("\n \t\tProcess[%d] of Queue1 is running for %d unit time",i+1,temp[i]); 
            total=total+temp[i]; 
            temp[i]=0; 
            counter=1; 
        } 
        else if(temp[i]>0) 
        {
			printf("\n \t\tProcess[%d] of Queue1 is running for 4 unit time",i+1); 
            temp[i]=temp[i]-4; 
            total=total+4; 
        } 
        if(temp[i]==0&&counter==1) 
        { 
            x--; 
            printf("\n \t\tProcess[%d]\t%d\t%d\t%d",i+1,bursttime1[i],total-arrivaltime1[i],total-arrivaltime1[i]-bursttime1[i]);
            avg_wait_time1=avg_wait_time1+total-arrivaltime1[i]-bursttime1[i]; 
            avg_turnaround_time1=avg_turnaround_time1+total-arrivaltime1[i]; 
            counter = 0; 
        } 
        if(i==j-1) 
        {
            i=0; 
        }
        else if(arrivaltime1[i+1]<=total) 
        {
            i++;
        }
        else 
        {
           i=0;
        }
   } 
    avg_wait_time1=avg_wait_time1/j;
    avg_turnaround_time1=avg_turnaround_time1/j;
    printf("\n \t\tAverage Waiting Time:%f",avg_wait_time1); 
    printf("\n \t\tAverage Turnaround Time:%f\n",avg_turnaround_time1); 
}

void first_come_first_serve()
{
	wait_time3[0] = 0;   
    for(i=1;i<l;i++)
    {
        wait_time3[i] = 0;
        for(p=0;p<l;p++)
        {
            wait_time3[i]=wait_time3[i]+bursttime3[p];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<l;i++)
    {
        turnaround_time3[i]=bursttime3[i]+wait_time3[i];
        avg_wait_time3=avg_wait_time3+wait_time3[i];
        avg_turnaround_time3=avg_turnaround_time3+turnaround_time3[i];
        printf("\n \t\tProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bursttime3[i],wait_time3[i],turnaround_time3[i]);
    }
    avg_wait_time3=avg_wait_time3/l;
    avg_turnaround_time3=avg_turnaround_time3/l;
    printf("\nAverage Waiting Time is : %f",avg_wait_time3);
    printf("\nAverage Turnaround Time is : %f",avg_turnaround_time3);
    for(i=0;i<l;i++)
    {
    	while(bursttime3[i]!=0)
    	{
    		if(bursttime3[i]>10)
    		{
				printf("\nProcess[%d] of Queue3 is run for 10 units",i+1);
				bursttime3[i]=bursttime3[i]-10;
			}
			else if(bursttime3[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is run for %d units",i+1,bursttime3[i]);
				bursttime3[i]=0;
			}
		}
	}
}
void round_robin_One()
{
	printf("\t\t\tTime Quantum between the 3 queues is 10\n");
	for(i=1;i<Total;i=i+10)
	{
		if(t1>10)
		{
			printf("\t\t\tQueue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("\t\t\tQueue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("\t\t\tQueue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("\t\t\tQueue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("\t\t\tQueue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("\t\t\tQueue3 is running for %d units\n\n\n",t3);
			t3=0;
		}
	}
}
int main()
{
	system("cls");
	system("color c0");
		system("cls");
		printf("\n\n\n____________________________________________________________________________________________________________\n\n");
		printf("\t\t\t|Problem-6-Multilevel queue scheduling algorithm|");
        printf("\t|LOVELY PROFESSIONAL UNIVERSITY|");
        printf("\t---------------------------------------------");
        printf("______________________________________________________________________________________________________________________\n");
        printf("\tprepared by:NIRBHAY NARAYAN SINGH");
        printf("\tRegistration no-11803895");
        printf("\tsubmitted to:");
		printf("\n_______________________________________________________________________________\n\n");
		
		printf("\t\t\t\t\t|Made in Quarantine|\n\n\n");
	
	printf("\n\t\t\t\tEnter the no. of process (Enter it...):");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\t\t\tEnter details of process[%d]\n",i+1);
		printf("\t\t\tArrival Time:");
		scanf("%d",&at[i]);
		printf("\t\t\tBurst Time:");
		scanf("%d",&bt[i]);
		printf("\t\t\tPriority(1 to 15):");
		scanf("%d",&pr[i]);
		Total=Total+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\n\n \t\t\tProcess[%d] belongs to Queue 1\n",i+1);
			arrivaltime1[j]=at[i];
			bursttime1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}	
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("\t\t\tProcess[%d] belongs to Queue 2\n",i+1);
			arrivaltimethree[k]=at[i];
			bursttime2[k]=bt[i];
			prioritytwo[k]=pr[i];
			processtwo[k]=k+1;
			k++;
			t2=t2+bt[i];
		}	
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("\t\t\tProcess[%d] belongs to Queue 3\n\n\n\n",i+1);
			arrivaltimethree[l]=at[i];
			bursttime3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}
	round_robin_One();
	round_robin();
	first_come_first_serve();
	priority();	
	return 0;
}
