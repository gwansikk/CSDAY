#include <iostream>

#define MIN 1
#define MAX 8

using namespace std;

int movable(int col, int row)
{
    int cnt(0);

    if (col - 2 >= MIN)
    {
        if (row - 1 >= MIN)
            cnt++;
        if (row + 1 <= MAX)
            cnt++;
    }
    if (col + 2 <= MAX)
    {
        if (row - 1 >= MIN)
            cnt++;
        if (row + 1 <= MAX)
            cnt++;
    }
    if (row - 2 >= MIN)
    {
        if (col - 1 >= MIN)
            cnt++;
        if (col + 1 <= MAX)
            cnt++;
    }
    if (row + 2 <= MAX)
    {
        if (col - 1 >= MIN)
            cnt++;
        if (col + 1 <= MAX)
            cnt++;
    }

    return cnt;
}

int main()
{
    std::ios_base ::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    char col, row;

    cin >> col >> row;
    col = col - 'a' + 1;
    row -= '0';

    cout << movable(col, row) << "\n";

    return 0;
}