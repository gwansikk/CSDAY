// O(nlogn)
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val N = readLine().toInt()
    val nums = readLine().split(" ").map { it.toInt() }.sorted()

    val bw = BufferedWriter(OutputStreamWriter(System.out))
    bw.write(getGoodCount(nums).toString())
    bw.flush()
    bw.close()
}

fun getGoodCount(nums: List<Int>): Int{
    var result = 0

    for (i in 0 until nums.size){
        if (isGood(nums, i, nums[i])) result++
    }

    return result
}

fun isGood(nums: List<Int>, num: Int, target: Int): Boolean{
    var start = 0
    var end = nums.size - 1

    while (start < end){
        if (start == num){
            start++
            continue
        }
        if (end == num){
            end--
            continue
        }

        if (nums[start] + nums[end] > target) end--
        else if (nums[start] + nums[end] < target) start++
        else return true

    }
    return false
}

/*
투포인터 활용

1. 입력받은 숫자를 정렬한다.
2. 맨 앞과 두 번째는 절대 good일 수 없으므로 세번째 부터 투포인터를 적용한다.
3. start와 end 설정.

1 2 3 4 5 7 8      10

start : 0번 index
end : i번째 index
start + end > target -> end-1
start + end < target -> start+1
start + end == target -> result++

젠장, 음수 고려 안했다.

5
-4 -3 1 2 3

-3은 -4와 1의 합 가능

5
-3 -2 -1 4 5
=> 이때는 무작정 오른쪽만 움직이면 안댐...

# 반례 1
# 입력:
5
-1 -2 0 -1 -2
# 출력:
2
# 정답:
4

# 반례 2 => 자기 자신을 이용해서 값을 구하면 안되는구나!!!
# 입력:
5
0 0 0 0 1
# 출력:
5
# 정답:
4

 */
