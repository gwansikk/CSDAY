import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (M, N) = readLine().split(" ").map { it.toInt() }
    val graph = Array(N){IntArray(M)}

    repeat(N){
        val input = readLine().split(" ").map { it.toInt() }
        graph[it] = input.toIntArray()
    }

    bw.write("${BFS(graph,M, N)}")
    bw.flush()
    bw.close()

}

fun BFS(graph: Array<IntArray>, M: Int, N: Int): Int{
    var max = 0
    val box = graph
    var que:Queue<Pair<Int, Int>> = LinkedList()
    val dx = intArrayOf(1,-1,0,0)
    val dy = intArrayOf(0,0,1,-1)

    // 시작점 추가
    for (i in 0 until N){
        for (j in 0 until M){
            if (box[i][j] == 1) que.add(Pair(i,j))
        }
    }

    while (!que.isEmpty()) {
        val position = que.poll()
        repeat(4){index -> // 4방위 확인
            val xPos = position.first + dx.get(index)
            val yPos = position.second + dy.get(index)
            if(check(xPos, yPos, M, N)){ // 범위 확인
                // 현재 값이 -1이 아니고, 현재 숫자 + 1보다 작은지 확인이 필요함.
                if(box[xPos][yPos] == 0) {
                    que.add(Pair(xPos,yPos))
                    box[xPos][yPos] = box[position.first][position.second] + 1
                    if (max < box[xPos][yPos]) max = box[xPos][yPos]
                }
            }
        }
    }

    for (i in box){
        if (i.contains(0)) return -1
    }

    if (max == 0) return 0

    return max - 1
}

fun check(x: Int, y: Int, M: Int, N: Int): Boolean{
    if (x < 0 || x >= N) return false
    if (y < 0 || y >= M) return false
    return true
}