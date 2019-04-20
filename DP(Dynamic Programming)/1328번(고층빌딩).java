import java.util.Scanner;

public class Main {
    
    static final long mod = 1000000007L;
    static long dp[][][] = new long[101][101][101];
    static int n,l,r;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        l = sc.nextInt();
        r = sc.nextInt();

        dp[1][1][1] = 1L;
        
        for(int i=2; i<=n; i++){
            for(int j=1; j<=l; j++){
                for(int k=1; k<=r; k++){
                    dp[i][j][k] = (dp[i-1][j][k-1]%mod + dp[i-1][j-1][k]%mod + (i-2)*dp[i-1][j][k]%mod)%mod;
                }
            }
        }

        System.out.println(dp[n][l][r]%mod);

        sc.close();
    }
}