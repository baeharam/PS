import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;


public class BOJ8896 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        List<ArrayList<Integer>> check = new ArrayList<>();
        for(int i=0; i<3; i++) check.add(new ArrayList<Integer>());
        List<String> rsp = new ArrayList<>();

        while(tc!=0) {
            int n = sc.nextInt();
            for(int i=0; i<n; i++) {
                String s = sc.next(); 
                rsp.add(s);
            }

            // 답을 구하기 위해 미리 복사해놓기
            List<String> temp = new ArrayList<>(rsp);

            int size = rsp.get(0).length();

            for(int i=0; i<size; i++) {
                for(int j=0; j<rsp.size(); j++){
                    switch(rsp.get(j).charAt(i)){
                        case 'R':
                            check.get(0).add(j);
                            break;
                        case 'S':
                            check.get(1).add(j);
                            break;
                        case 'P':
                            check.get(2).add(j);
                            break;
                    }
                }

                // 각 로봇들이 바위, 가위, 보를 얼마나 냈는지 계산
                // 왜? 3개 모두 1개 이상 있다면 무승부이므로 판단하기 위해서!
                int rock = check.get(0).size();
                int scissor = check.get(1).size();
                int paper = check.get(2).size();

                List<String> ans = new ArrayList<>();

                /* 무승부인 경우 제외
                    1. 가위, 바위, 보가 모두 포함되어있음
                    2. 모두 가위, 모두 바위, 모두 보인 경우
                */
                if(!(rock!=0 && scissor!=0 && paper!=0) &&
                    !(rock!=0 && scissor==0 && paper==0) &&
                    !(rock==0 && scissor!=0 && paper==0) &&
                    !(rock==0 && scissor==0 && paper!=0)) {
                    // 바위 vs 가위 = 바위
                    if(rock!=0 && scissor!=0){
                        for(int k=0; k<rock; k++){
                            ans.add(rsp.get(check.get(0).get(k)));
                        }
                    }
                    // 바위 vs 보 = 보
                    else if(rock!=0 && paper!=0){
                        for(int k=0; k<paper; k++){
                            ans.add(rsp.get(check.get(2).get(k)));
                        }
                    }
                    // 보 vs 가위 = 가위
                    else if(paper!=0 && scissor!=0){
                        for(int k=0; k<scissor; k++){
                            ans.add(rsp.get(check.get(1).get(k)));
                        }
                    }
                    rsp.clear();
                    rsp = new ArrayList<>(ans);
                }
                // ArrayList check 초기화
                for(int k=0; k<3; k++) check.get(k).clear();
            }
            if(rsp.size()>1) System.out.println("0");
            else{
                for(int k=0; k<temp.size(); k++){
                    if(temp.get(k).compareTo(rsp.get(0))==0){
                        System.out.println(k+1);
                        break;
                    }
                }
            }
            rsp.clear();
            tc--;
        }
        sc.close();
    }
}