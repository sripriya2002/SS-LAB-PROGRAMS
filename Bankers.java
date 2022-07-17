import java.util.*;
public class Bankers{
	int max[][],need[][],allocation[][],available[][];
	int np,nr;
	Scanner sc=new Scanner(System.in);
	public void input(){
		System.out.println("enter the processes\n");
		np=sc.nextInt();
		System.out.println("enter the resources\n");
		nr=sc.nextInt();
		max=new int[np][nr];
		need=new int[np][nr];
		allocation=new int[np][nr];
		available=new int[1][nr];
		System.out.println("enter the allocation matrix\n");
		for(int i=0;i<np;i++){
			for(int j=0;j<nr;j++){
				allocation[i][j]=sc.nextInt();
			}
		}
		System.out.println("enter the maximum matrix\n");
		for(int i=0;i<np;i++){
			for(int j=0;j<nr;j++){
				max[i][j]=sc.nextInt();
			}
		}
		System.out.println("enter the available matrix\n");
		for(int i=0;i<nr;i++){
			available[0][i]=sc.nextInt();
		}
		sc.close();
	}
	public void cal_need(){
		for(int i=0;i<np;i++){
			for(int j=0;j<nr;j++){
				need[i][j]=max[i][j]-allocation[i][j];
			}
		}
	}
	public boolean check(int p){
		boolean flag=false;
		for(int i=0;i<nr;i++){
		
			if(need[p][i]<=available[0][i]){
				flag=true;
			}
			else{
				flag=false;
				break;
			}
		}
		return flag;
	}
	public void algorithm(){
		cal_need();
		int c=0;
		boolean ret;
		boolean status[]=new boolean[np];
		while(c<np){
			boolean allocated=false;
			for(int i=0;i<np;i++){
				ret=check(i);
				if(!status[i]&& ret){
					status[i]=true;
					allocated=true;
					c++;
					System.out.println("Allocated process is "+i);
					for(int j=0;j<nr;j++){
						available[0][j]+=allocation[i][j];
					}
					
					}
				}
				if(!allocated)break;
				
			}
			if(c==np)
				System.out.println("safely allocated\n");
			else
				System.out.println("not safe\n");
		}
		public static void main(String args[]){
			Bankers obj=new Bankers();
			obj.input();
			obj.algorithm();
		}
	}
