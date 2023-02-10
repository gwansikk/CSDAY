import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 9251_PDM {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    void run() throws IOException {
        String first = bf.readLine();
        String second = bf.readLine();
        first = '0'+first;
        second = '0'+second;
        int[][] str = new int[first.length()][second.length()];

        for(int i = 1; i < first.length(); i++){
            for(int j = 1; j < second.length(); j++){
                if(first.charAt(i) == second.charAt(j)) {
                    str[i][j] = str[i - 1][j - 1] + 1;
                }else{
                    if(str[i-1][j] > str[i][j-1]){
                        str[i][j] = str[i-1][j];
                    }else{
                        str[i][j] = str[i][j-1];
                    }
                }
            }
        }

        System.out.println(str[first.length()-1][second.length()-1]);
    }

    public static void main(String[] args) {
        9251_PDM my = new 9251_PDM();
        try{
            my.run();
        }catch(Exception e){}
    }

}
