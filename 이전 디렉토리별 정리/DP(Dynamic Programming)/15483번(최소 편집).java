import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s1 = br.readLine(),s2 = br.readLine();
        int len1 = s1.length(), len2 = s2.length();

        int dp[][] = new int[1001][1001];

        for(int i=0; i<=len1; i++) dp[0][i] = i;
        for(int i=0; i<=len2; i++) dp[i][0] = i;

        for(int i=1; i<=len2; i++){
            for(int j=1; j<=len1; j++){
                if(s1.charAt(j-1)==s2.charAt(i-1)) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                }
            }
        }

        bw.write(String.valueOf(dp[len2][len1]));
        bw.flush();

        br.close();
        bw.close();
    }
}