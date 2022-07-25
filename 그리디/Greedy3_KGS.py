n, m, k = map(int, input().split())
array = list(map(int, input().split()))

array.sort(reverse=True)

firstMaxNumber = array[0];
secondMaxNumber = array[1];
sumNumber = 0

while True:
    for i in range(k):
        if m == 0:
            break

        sumNumber += firstMaxNumber;
        m -= 1
    
    if m == 0:
        break

    sumNumber += secondMaxNumber
    m -= 1

print(sumNumber)
