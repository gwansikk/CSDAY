import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()

    val arr = IntArray(N)
    val st = StringTokenizer(readLine())
    for (i in 0 until N) {
        arr[i] = st.nextToken().toInt()
    }

    val list = IntArray(N)
    list[0] = arr[0]
    var index = 1

    arr.forEach { portNumber ->
        when {
            list[index - 1] < portNumber -> list[index++] = portNumber
            list[0] > portNumber -> list[0] = portNumber
            else -> {
                val temp = Arrays.binarySearch(list, 0, index, portNumber)
                list[
                        if (temp < 0) -temp - 1
                        else temp
                ] = portNumber
            }
        }
    }

    val bw = BufferedWriter(OutputStreamWriter(System.out))
    bw.write(index.toString())
    bw.flush()
    bw.close()
}
