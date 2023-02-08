// O(n^2)
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))){
    val token = StringTokenizer(readLine())

    val N = Integer.parseInt(token.nextToken()) // 세로
    val M = Integer.parseInt(token.nextToken()) // 가로

    // 미로 생성
    val maze = Array(N) { IntArray(M) }
    repeat(N){ x ->
        val str = readLine()
        repeat(M){ y ->
            maze[x][y] = Integer.parseInt(str[y].toString())
        }
    }

    println(bfs(N, M, maze))
}

class Node(
    val x: Int,
    val y: Int,
    val prev: Node?
)

fun bfs(row: Int, col: Int, maze: Array<IntArray>): Int {
    val visited = Array(row) { BooleanArray(col) }

    val queue: Queue<Node> = LinkedList()
    queue.offer(Node(0, 0, null))

    var cnt = 0

    // 서->남->동->북 으로 탐색
    val dist_x = intArrayOf(1, 0, -1, 0)
    val dist_y = intArrayOf(0, 1, 0, -1)

    while (!queue.isEmpty()) {
        val node = queue.poll()

        // 출구 도착
        if (node.x == col - 1 && node.y == row - 1) {
            var path = node
            while (path != null) {
                path = path.prev
                cnt++
            }
            break
        }

        // 경로 탐색
        for (i in 0..3) {
            val xx = node.x + dist_x[i]
            val yy = node.y + dist_y[i]

            if (!rangeCheck(xx, yy, row, col) && !visitedCheck(xx, yy, maze, visited)) {
                visited[yy][xx] = true
                queue.offer(Node(xx, yy, node))
            }
        }
    }

    return cnt
}

fun rangeCheck(
    x: Int, y: Int,
    row: Int, col: Int
) = x < 0 || y < 0 || x > col - 1 || y > row - 1


fun visitedCheck(
    x: Int, y: Int,
    maze: Array<IntArray>,
    visited: Array<BooleanArray>,
) = visited[y][x] || maze[y][x] == 0
