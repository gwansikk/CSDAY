import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Nov_28_2352_ICDesign {

    // lis에서 port를 삽입할 위치를 반환
    public static int lowerBound(List<Integer> lis, int port) {
        int left = 0;
        int right = lis.size() - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (lis.get(mid) < port) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 1-N번 포트 정보 입력
        List<Integer> ports = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            ports.add(Integer.parseInt(st.nextToken()));
        }

        // 교차하지 않는 최대 연결 개수 구하기
        List<Integer> lis = new ArrayList<>();
        lis.add(ports.get(0));
        for (int i = 1; i < n; i++) {
            int port = ports.get(i);
            if (lis.get(lis.size() - 1) < port) {
                lis.add(port);
            } else {
                int idx = lowerBound(lis, port);
                lis.set(idx, port);
            }
        }
        bw.write(String.valueOf(lis.size()));
        bw.flush();
        bw.close();
    }

}
