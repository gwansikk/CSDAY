import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

data class Lecture(
    val start: Int,
    val end: Int
)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val lectures = ArrayList<Lecture>()
    val room = PriorityQueue<Int>()


    val N = readLine().toInt()

    repeat(N) {
        val (start, end) = readLine().split(" ").map { it.toInt() }
        lectures.add(Lecture(start, end))
    }

    lectures.sortBy { it.start }

    room.add(lectures[0].end)

    for (i in 1 until N) {
        if (room.peek() <= lectures[i].start) {
            room.poll()
            room.add(lectures[i].end)
        }
        else {
            room.add(lectures[i].end)
        }
    }

    bw.write("${room.size}")
    bw.flush()
    bw.close()
}