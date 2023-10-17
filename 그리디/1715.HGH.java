import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

public class Oct17_1715_CardSorting {

    private static int calcMinComparison(PriorityQueue<Integer> card) {
        int res = 0;
        while (card.size() > 1) {
            int s1 = card.poll();
            int s2 = card.poll();
            int sum = s1 + s2;
            res += sum;
            card.add(sum);
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        PriorityQueue<Integer> card = new PriorityQueue<>();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int ea = Integer.parseInt(br.readLine());
            card.add(ea);
        }
        bw.write(String.valueOf(calcMinComparison(card)));
        bw.flush();
        bw.close();
    }

}
