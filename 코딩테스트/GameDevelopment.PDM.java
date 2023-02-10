import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Dir{
    int x;
    int y;
    Dir(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class GameDevelopment_PDM {
    static int[][] Map;
    static Dir[] dir = { // -1 할 경우 반시계방향으로 이동
            new Dir(-1,0), // 북
            new Dir(0,1), // 동
            new Dir(1,0), // 남
            new Dir(0,-1) // 서
    };
    static int count = 0;
    static int result = 1;

    static void DFS(int x, int y, int direction){
        // DFS종료 조건
        if(count == 4){
            return;
        }

        // 범위 조정
        if(direction == -1){
            direction = 3;
        }

        int xx = x + dir[direction].x;
        int yy = y + dir[direction].y;

        if(Map[xx][yy] == 0){
            Map[x][y] = 1;
            count = 0;
            result++;
            DFS(xx,yy,direction);
            return;
        }

        count++;
        DFS(x,y,direction-1);
        return;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] input = bf.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        Map = new int[N][M];

        String[] input2 = bf.readLine().split(" ");
        int x = Integer.parseInt(input2[0]);
        int y = Integer.parseInt(input2[1]);
        int direction = Integer.parseInt(input2[2]); //class로 xy좌표 저장해서 우측 이동하는거 기록

        String[] map;
        for(int i = 0; i < N; i++){
            map = bf.readLine().split(" ");
            for(int j = 0; j < M; j++){
                Map[i][j] = Integer.parseInt(map[j]);
            }
        }

        DFS(x,y,direction);

        System.out.println(result);
    }
}