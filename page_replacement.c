#include<stdio.h>
#include<stdlib.h>
int page[10],frame[10],f,n,isPagehit,pageHit=0;
void FIFO(){
	int curptr;
	for(int i=0;i<n;i++){
		isPagehit=0;
		for(int j=0;j<f;j++){
			if(frame[j]==page[i]){
				pageHit++;
				isPagehit=1;
			}
		}
		if(isPagehit==0){
				curptr=curptr%f;
				frame[curptr]=page[i];
				curptr++;
		}
			printf("Frame :");
			for(int k=0;k<f;k++){
				printf("%d\t",frame[k]);
			}
			printf("\n");
		}
		printf("number of page hits is %d ",pageHit);
		printf("number of pagefaults is %d ",n-pageHit);
}
int LeastRecent(int recent[],int f){
	int x;
	int Leastpage=0;
	int LeastpageVal=recent[0];
	for(x=1;x<f;x++){
		if(recent[x]<LeastpageVal){
			LeastpageVal=recent[x];
			Leastpage=x;
		}
	}
	return Leastpage;
}
void LRU(){
	int pageHit=0,isPageHit=0,firstFrame=0,counter=0,recent[10];
	for(int i=0;i<f;i++)
		frame[i]=-1;
	for(int i=0;i<n;i++){
		isPageHit=0,firstFrame=0;
		for(int j=0;j<f;j++){
			if(page[i]==frame[j]){
				pageHit++;
				isPageHit=1;
				counter++;
				recent[j]=counter;
				break;
			}
		}
		if(isPageHit==0){
			for(int j=0;j<f;j++){
				if(frame[j]==-1){
					frame[j]=page[i];
					firstFrame=1;
					counter++;
					recent[j]=counter;
					break;
				}
			}
		}
		if(isPageHit==0 && firstFrame==0){
			int pos=LeastRecent(recent,f);
			counter++;
			frame[pos]=page[i];
			recent[pos]=counter;
		}
		printf("Frame :");
			for(int k=0;k<f;k++){
				printf("%d\t",frame[k]);
			}
			printf("\n");
	}
	
	printf("number of page hits is %d ",pageHit);
	printf("number of pagefaults is %d ",n-pageHit);	
}			




void main(){
	int choice;
	printf("enter the page size\n");
	scanf("%d",&n);
	printf("enter the pages\n");
	for(int i=0;i<n;i++){
		scanf("%d",&page[i]);
	}
	printf("enter the frame size\n");
	scanf("%d",&f);
	for(int j=0;j<f;j++){
		frame[j]=-1;
		
	}
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:FIFO();
			break;
		case 2:LRU();
			break;
	}
}
