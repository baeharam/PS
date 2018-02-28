package baekjoon;

import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class FastINOUT {

	public static void main(String[] args) throws IOException {
		int tc;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		
		tc=Integer.parseInt(br.readLine());
		
		int[] value=new int[2];
		for(int i=0; i<tc; i++) {
			int k=0;
			StringTokenizer st=new StringTokenizer(br.readLine(), " ");
			
			while(st.hasMoreElements()) {
				value[k++]=Integer.parseInt(st.nextToken());
			}
			bw.write(String.valueOf(value[0]+value[1])+"\n");
			bw.flush();
		}
	}

}
