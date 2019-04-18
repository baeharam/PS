import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class test {

    static int n,m;
    static List<Integer>[] hack = new ArrayList[10001];
    static boolean visit[] = new boolean[10001];
    static int ans[] = new int[10001];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());

        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        for(int i=1; i<=n; i++) hack[i] = new ArrayList<Integer>();

        for(int i=0; i<m; i++){
            tk = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(tk.nextToken());
            int to = Integer.parseInt(tk.nextToken());
            hack[from].add(to);
        }

        for(int i=1; i<=n; i++) {
            visit = new boolean[10001];
            dfs(i);
        }

        int max=0;
        for(int i=1; i<=n; i++){
            if(ans[i]>max){
                max = ans[i];
            }
        }

        for(int i=1; i<=n; i++){
            if(ans[i]==max){
                sb.append(i+" ");
            }
        }
        System.out.print(sb.toString());
        br.close();
    }

    static void dfs(int v){
        visit[v] = true;
        for(int i=0; i<hack[v].size(); i++){
            if(!visit[hack[v].get(i)]){
                ans[hack[v].get(i)]++;
                dfs(hack[v].get(i));
            }
        }
    }
}