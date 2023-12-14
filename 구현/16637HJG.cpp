#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int num;
int Max_num;

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}
void recur(int index, int cur)
{

	if (index > num - 1)
	{
		Max_num = max(Max_num, cur);
		return;
	}
	char oper = (index == 0) ? '+' : str[index - 1];
	
	if (index + 2 < num)
	{
		int bracket = calculate(str[index] - '0', str[index + 2] - '0', str[index + 1]);
		recur(index + 4, calculate(cur, bracket, oper));
	}

	recur(index+2, calculate(cur, str[index]-'0', oper));			//°ýÈ£ ¾ÈÇØµµ µÊ
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Max_num = INT_MIN;

	cin >> num >> str;

	recur(0, 0);

	cout << Max_num;

}