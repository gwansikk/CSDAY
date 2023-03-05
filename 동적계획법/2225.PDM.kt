// O(N)
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val MOD = 1000000000

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))){
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, k) = readLine().split(" ").map { it.toInt() }
    val dp = Array(n + 1) { IntArray(k + 1) { 1 } }

    for (i in 1..n) {
        for (j in 2..k) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD
        }
    }

    bw.write("${dp[n][k]}")

    bw.flush()
    bw.close()
}