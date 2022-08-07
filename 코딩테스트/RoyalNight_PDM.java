import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RoyalNight_PDM {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int cnt = 0;

        String input = bf.readLine();
        int x = input.charAt(0) - 'a' + 1;
        int y = Integer.parseInt(String.valueOf(input.charAt(1)));

        if(x+2 <= 8){
            if(y+1 <= 8){
                cnt++;
            }
            if(y-1 >= 1){
                cnt++;
            }
        }
        if(x-2 >= 1){
            if(y+1 < 8){
                cnt++;
            }
            if(y-1 >= 1){
                cnt++;
            }
        }
        if(y+2 <= 8){
            if(x+1 <= 8){
                cnt++;
            }
            if(x-1 >= 1){
                cnt++;
            }
        }
        if(y-2 >= 1){
            if(x+2 <= 8){
                cnt++;
            }
            if(x-2 >= 1){
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}
