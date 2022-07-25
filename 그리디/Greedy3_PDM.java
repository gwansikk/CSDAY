import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Greedy3_PDM {

    void run() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        // N, M, K 입력
        String[] input = bf.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int K = Integer.parseInt(input[2]);

        // 숫자배열 입력 및 정렬
        String[] number = bf.readLine().split(" ");
        Arrays.sort(number);

        // 계산
        int sum = 0;
        for(int i = 1; i < M+1; i++){
            if(i % (K+1) == 0){
                sum += Integer.parseInt(number[N-2]);
            }else{
                sum += Integer.parseInt(number[N-1]);
            }
        }

        System.out.println(sum);
    }

    public static void main(String[] args) throws IOException{
        Greedy3_PDM my = new Greedy3_PDM();
        my.run();
    }
}
