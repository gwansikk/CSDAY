// O(n)
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val input: Int = br.readLine().toInt()

    repeat(input){
        val times = br.readLine().toInt()
        var tempList : ArrayList<String> = arrayListOf()
        for (i in 0 until times){
            tempList.add(br.readLine())
        }
        tempList.sort()
        if (isOkay(tempList)) bw.write("YES\n")
        else bw.write("NO\n")
    }



    bw.flush()
    bw.close()
}

fun isOkay(tempList: ArrayList<String>): Boolean{
    for (i in 0 until tempList.size - 1){
        if (tempList[i + 1].startsWith(tempList[i])) return false
    }
    return true
}