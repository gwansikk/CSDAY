// O(n)
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val stack: Stack<Int> = Stack()
val pair: ArrayList<Pair<Int, Int>> = arrayListOf()
val result: HashSet<String> = hashSetOf()


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val input: String = br.readLine()

    for (i in 0 until input.length){
        if (input[i] == '(') stack.push(i)
        if (input[i] == ')') pair.add(Pair(stack.pop(),i))
    }

    val max = pair.size
    val chk = BooleanArray(max)

    for (i in 1..max) { // 순서쌍 만들기
        findAll(chk, 0, i, max, input) //combination, 여러개중 i개 선택
    }

    result.sorted().forEach{bw.write("$it\n")}
    bw.flush()
    bw.close()
}

fun findAll(chk: BooleanArray, idx: Int, cnt: Int, max: Int, input: String) {
    if (cnt == 0) {
        getResult(chk, input)
        return
    }
    for (i in idx until max) {
        chk[i] = true
        findAll(chk, i + 1, cnt - 1, max, input)
        chk[i] = false
    }
}

fun getResult(chk: BooleanArray, input: String){
    var temp = input
    for (i in 0 until chk.size){
        if (chk[i]) temp = deleteBracket(pair[i], temp)
    }
    result.add(temp.replace(" ", ""))
}

fun deleteBracket(index: Pair<Int, Int>, input: String): String{
    var temp = input.toMutableList()
    temp[index.first] = ' '
    temp[index.second] = ' '
    return temp.joinToString("")
}

/*
괄호가 나오는 순서는 스택으로 표현 가능
총 출력 갯수는 (괄호 쌍 갯수)! + 1

스택에 쌓을때 (의 인덱스, )의 인덱스를 쌓음
(가 나오면 (의 인덱스를 스텍에 넣고, )가 나오면 스텍을 팝함. 팝 할때 (의 index, )의 index해서 Pair 혹은 Class로 저장.
ex)
(1+1)+(1*1)
Pair(0,4), Pair(6,10) 두개 생성
이걸 배열에 넣어둠.

순서쌍 만드는 알고리즘 필요.



0번째부터 + 1, + 2 .. + n이렇게 진행해야함.


해당 인덱스의 괄호를 ""로 replace 시켜버림



고려해야할 예시
(1+1)+(2+2)
(1+1)+1
(0/(0))
(2+(2*2)+2)
(1+(2*(3+4)))
 */