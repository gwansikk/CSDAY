import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class ClassAllocation {

    static class Classroom {
        int start;
        int end;

        public Classroom(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Classroom> classrooms = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // 입력
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            classrooms.add(new Classroom(start, end));
        }
        
        // 시작 시간 기준으로 정렬
        Collections.sort(classrooms, (a, b) -> {
            if (a.start == b.start) {
                return a.end - b.end;
            }
            return a.start - b.start;
        });
        
        // 우선순위 큐에 종료 시간을 넣어줌
        pq.add(classrooms.get(0).end);
        for (int i = 1; i < n; i++) {
            // 종료 시간이 가장 빠른 강의실의 종료 시간과 현재 강의의 시작 시간을 비교
            if (pq.peek() <= classrooms.get(i).start) {
                pq.poll();
            }
            pq.add(classrooms.get(i).end);
        }
        bw.write(pq.size() + "\n");
        
        br.close();
        bw.flush();
        bw.close();
    }

}
