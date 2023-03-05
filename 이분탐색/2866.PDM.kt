//O(N^2)

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))){
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (N, C) = readLine().split(" ").map { it.toInt() }
    //val table = MutableList(N){readln()} // 하나하나 타이핑하면 ㄱㅊ 근데 복붙하면 터지네?
    val table: MutableList<String> = mutableListOf();

    repeat(N){
        val str = readLine()
        table.add(str)
    }
    val colTable = setCol(table, C)

    bw.write("${countLen(colTable, N, C)}")
    bw.flush()
    bw.close()
}

/*
// 타임아웃 나는 방법
fun stringCutter(table: MutableList<String>, N:Int, C: Int): Int {
    var cnt = 1
    while (true){
        val set = mutableSetOf<String>()
        for (i in 0..C-1){
            var str = ""
            for (j in cnt..N-1)
                str += table[j][i]
            set.add(str)
        }
        if (set.size != C) return cnt
        cnt++
    }
}
*/

/*
//1차적으로 체크 후 전체 체크 => 여전히 타임아웃
fun stringCutter(table: MutableList<String>, N:Int, C: Int): Int {
    var cnt = 0
    while (true){
        cnt++
        if (firstCheck(table, C, cnt)) continue

        val set = mutableSetOf<String>()
        for (i in 0..C-1){
            var str = ""
            for (j in cnt..N-1)
                str += table[j][i]
            set.add(str)
        }
        if (set.size != C) return cnt
    }
}

fun firstCheck(table: MutableList<String>, C: Int, cnt: Int): Boolean{
    val test = mutableListOf<Char>()

    for (i in 0..C-1){
        if (test.contains(table[cnt][i])) return false

        test.add(table[cnt][i])
    }

    return true
}
*/

/*
// 이진탐색으로 확인. => 타임아웃
fun binarySearch(table: MutableList<String>, N:Int, C: Int): Int{
    var fir = 1
    var end = N
    var mid = (fir + end)/2

    while (true){
        //println("fir = $fir, mid = $mid, end = $end")

        if (mid == fir || mid == end) return mid -1

        if (init(table, N, C, mid)){ // 같은게 존재함

            end = mid
            if ((fir + end) / 2 == mid) mid = (fir + end) / 2 + 1
            else mid = (fir + end) / 2
        }else{ // 같은게 존재하지 않음
            //if (mid == fir || mid == end) return mid -1
            fir = mid
            if ((fir + end) / 2 == mid) mid = (fir + end) / 2 + 1
            else mid = (fir + end) / 2
        }
    }
}

fun init(table: MutableList<String>, N:Int, C: Int, mid: Int): Boolean{
    val set = HashSet<String>()

    if (!isFirstLetterSame(table, C, mid)) return false // 같은게 존재한다면 밑에내용을 실행. 아니라면 바로 보냄.

    for (i in 0..C-1){
        var str = ""
        for (j in mid-1..N-1)
            str += table[j][i]
        set.add(str)
    }
    //println(set.toString())

    if (set.size != C) return true

    return false
}

fun isFirstLetterSame(table: MutableList<String>, C: Int, mid: Int): Boolean{
    val set = HashSet<Char>()

    for (i in 0..C-1){
        set.add(table[mid-1][i])
    }

    if (set.size != C) return true

    return false
}

 */

fun setCol(table: MutableList<String>, C: Int): MutableList<String>{
    val colTable = mutableListOf<String>()

    for (i in 0 until C){
        val temp = table.map{it[i]}.joinToString("")

        colTable.add(temp)
    }

    return colTable
}

fun countLen(colTable: MutableList<String>, N: Int, C: Int): Int{
    var count = 0

    for (i in 1 .. N){
        val tempSet = hasSetOf<String>()
        colTable.forEach{
            val temp = it.substring(i,N)
            tempSet.add(temp)
        }

        if (tempSet.size != C) break
        count++
    }

    return count
}
// countLen을 이분탐색으로 할 수 있으려나