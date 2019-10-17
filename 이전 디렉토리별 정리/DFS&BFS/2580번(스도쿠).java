import java.util.Scanner;

public class Main {

    static int board[][] = new int[9][9];

    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                board[i][j] = sc.nextInt();
            }
        }

        dfs();

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }

        sc.close();
    }

    static boolean dfs(){
        int x=-1,y=-1;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]==0){
                    x=i;
                    y=j;
                    break;
                }
            }
        }

        if(x==-1 && y==-1) return true;

        for(int i=1; i<=9; i++){
            if(allTest(x, y, i)) {
                board[x][y]=i;
                if(dfs()) return true;
                board[x][y]=0;
            }
        }
        return false;
    }

    static boolean allTest(int r, int c, int num){
        return rowTest(r, num) && colTest(c, num) && boxTest(r, c, num);
    }

    static boolean rowTest(int r, int num) {
        for(int i=0; i<9; i++){
            if(board[r][i]==num) 
                return false;
        }
        return true;
    }

    static boolean colTest(int c, int num) {
        for(int i=0; i<9; i++){
            if(board[i][c]==num) 
                return false;
        }
        return true;
    }

    static boolean boxTest(int r, int c, int num) {
        int sr=r/3*3, sc=c/3*3;
        for(int i=sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++){
                if(board[i][j]==num)
                    return false;
            }
        }
        return true;
    }
}