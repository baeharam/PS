package baekjoon;

import java.util.Scanner;

public class PaperCutting {
	static int[][] paper=new int[2147][2147];
	static int[] ans=new int[3];
	
	// 2차원 배열의 모든 원소가 같은지 검사하고 같지않으면 -2리턴
	// 같으면 그 숫자 리턴
	static int isAllSame(int index1, int index2, int size) {
		int sameValue=paper[index1][index2];
		for(int i=index1; i<index1+size; i++) {
			for(int j=index2; j<index2+size; j++)
				if(sameValue!=paper[i][j]) return -2;
		}
		return sameValue;
	}
	
	static void PaperCutter(int index1,int index2, int size)
	{
		if(size==1) {
			if(paper[index1][index2]==0) ans[0]++;
			else if(paper[index1][index2]==-1) ans[2]++;
			else if(paper[index1][index2]==1) ans[1]++;
		}
		else {
			int flag=isAllSame(index1,index2,size);
			if(flag==-2) {
				int i=index1,j=index2;
				int interval=size/3;
				while(i<index1+size) {
					while(j<index2+size) {
						PaperCutter(i,j,interval);
						j+=interval;
					}
					i+=interval;
					j=index2;
				}
			}
			else if(flag==0) ans[0]++;
			else if(flag==1) ans[1]++;
			else if(flag==-1) ans[2]++;
		}
	}
	
	public static void main(String args[]) {
		// 입력
		Scanner reader=new Scanner(System.in);
		int n = reader.nextInt();
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				paper[i][j]=reader.nextInt();
			}
		}
		
		PaperCutter(0,0,n);
		System.out.println(ans[2]);
		System.out.println(ans[0]);
		System.out.println(ans[1]);
		reader.close();
	}
	
}
