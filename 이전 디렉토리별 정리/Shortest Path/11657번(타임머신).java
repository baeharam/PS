import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final int inf = (int)2e9;
        List<Edge> e = new ArrayList<Edge>();
        int d[] = new int[501];
                
        int n,m,a,b,c;

        StringTokenizer tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        boolean isConnected = false;

        for(int i=0; i<m; i++){
            tk = new StringTokenizer(br.readLine());
            a = Integer.parseInt(tk.nextToken());
            b = Integer.parseInt(tk.nextToken());
            c = Integer.parseInt(tk.nextToken());
            if(a==1) isConnected = true;
            e.add(new Edge(a,b,c));
        }

        if(!isConnected) d[1] = inf;

        for(int i=2; i<=n; i++) d[i] = inf;

        for(int i=0; i<n-1; i++){
            for(Edge edge : e){
                int from = edge.from;
                int to = edge.to;
                int cost = edge.cost;

                if(d[from]!=inf && d[to] > d[from]+cost) {
                    d[to] = d[from]+cost;
                }
            }
        }

        boolean isCycle = false;
        for(Edge edge : e) {
            if(d[edge.from]!=inf && d[edge.to] > d[edge.from]+edge.cost){
                isCycle = true;
                break;
            }
        }

        if(isCycle) bw.write("-1");
        else {
            for(int i=2; i<=n; i++) {
                bw.write(String.valueOf(d[i]==inf ? -1 : d[i])+"\n");
            }
        }
        bw.flush();
            
        br.close();
        bw.close();
    }

    static class Edge{
        int from;
        int to;
        int cost;
        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }
}