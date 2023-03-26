import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val M = br.readLine().toInt()
    var arr = br.readLine().split(" ").map { it.toInt() }

    bw.write("${getSum(N, M, arr)}")
    bw.flush()
    bw.close()
}

fun getSum(N: Int, M: Int, array: List<Int>): Int{
    if (N < M) return 0
    val temp = array.sorted()
    var distance = intArrayOf()

    repeat(N - 1){
        distance = distance.plus(temp[it + 1] - temp[it])
    }

    repeat(M-1){
        distance[distance.indexOf(distance.maxOrNull()!!)] = 0
    }

    return distance.sum()
}