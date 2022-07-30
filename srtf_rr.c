#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,at[10],bt[10],rt[10],flag=0,count,remain,tq,time;
	int sum_tat=0,sum_wt=0,choice;
	printf("enter the choice:1.ROUND ROBIN\n2.SRTF\n");
	scanf("%d",&choice);
	printf("enter the number of process\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("enter the Arrival time of P%d\n",(i+1));
		scanf("%d",&at[i]);
		printf("enter the Burst time of P%d\n",(i+1));
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	switch(choice){
		case 1: printf("enter the time quantum\n");
			scanf("%d",&tq);
			remain=n;
			printf("Process\tTurn Around Time\tWaiting time\n");
			for(count=0,time=0;remain!=0;){
				if(rt[count]<=tq && rt[count]!=0){
					flag=1;
					time+=rt[count];
					rt[count]=0;
				}
				else if(rt[count]>0){
					time+=tq;
					rt[count]-=tq;
				}
				if(rt[count]==0 && flag==1){
					remain--;
					printf("P%d\t\t%d\t\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
					flag=0;
					sum_tat+=time-at[count];
					sum_wt+=time-at[count]-bt[count];
				}
				if(count==n-1)
					count=0;
				else if(at[count]<=time)
					count++;
				else
					count=0;
				}
				printf("Average turnaround time is %f\n",(float)sum_tat/n);
				printf("Average waiting time is %f\n",(float)sum_wt/n);
				break;
		case 2:remain=0;
			int smallest;
			rt[9]=999;
			int endTime;
			printf("Process\tTurn Around Time\tWaiting time\n");
			for(time=0;remain!=n;time++){
				smallest=9;
				for(int i=0;i<n;i++){
					if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0){
						smallest=i;
					}
				}
				rt[smallest]--;
					if(rt[smallest]==0){
						remain++;
						endTime=time+1;
						printf("P%d\t\t%d\t\t%d\t\n",smallest+1,endTime-at[smallest],endTime-at[smallest]-bt[smallest]);
						sum_tat+=endTime-at[smallest];
						sum_wt+=endTime-at[smallest]-bt[smallest];
					}
				}
				printf("average turn around time %f\n",(float)sum_tat/n);
				printf("average waiting time %f\n",(float)sum_wt/n);
				break;
		default:exit(0);
				
						
		}
		return 0;
	}
