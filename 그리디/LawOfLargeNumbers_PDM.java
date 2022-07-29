import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    void run() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(0,1));
        String[] input = bf.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int target = 2;

        while(target != N){
            target++;

            if(target % K == 0){
                arr.add(arr.get(target/K - 1) + 1);
            }else{
                arr.add(arr.get(target-2) +1);
            }
        }

        System.out.println(arr.get(target-1));
    }

    public static void main(String[] args) throws IOException{
        Main my = new Main();
        my.run();
    }
}