import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Palindrome {

    private static boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start++) != s.charAt(end--)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 입력
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String s = br.readLine();
            int start = 0; // 시작 인덱스
            int end = s.length() - 1; // 끝 인덱스
            int count = 0; // 팰린드롬이 아닌 문자열의 개수
            while (start < end) {
                if (s.charAt(start) != s.charAt(end)) { // 문자가 다르면 양쪽의 문자를 하나씩 제외하여 팰린드롬인지 확인
                    if (isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1)) {
                        count = 1;
                    } else { // 두 문자를 제외했을 때도 팰린드롬이 아닌 경우
                        count = 2;
                    }
                    break;
                }
                start++;
                end--;
            }
            bw.write(count + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }

}
