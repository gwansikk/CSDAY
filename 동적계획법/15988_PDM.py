cycle = int(input())
list = [1, 2, 4, 7]

for i in range(cycle):
    num = int(input())
    number = 5

    while (True):
        if num <= 4:
            break

        list.append(list[number-4] + list[number-3] + list[number-2])
        number += 1
        if number > num:
            break
    print(list[num - 1])


'''
arr[0] + arr[1] + arr[2] = arr[3]
1       2           4       7

'''