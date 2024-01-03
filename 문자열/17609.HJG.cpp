#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

enum {
	PALINDROME = 0,
	SEMI_PALINDROME,
	NOT_PALINDROME
};

int isPalindrome(string str)
{

	int result = PALINDROME;
	bool isPalindrome=true;
	
	for (int i = 0; i < str.length() / 2; i++)
	{
		string begin_substr;
		string end_substr;
		bool isbegin=true;
		if (result == PALINDROME && isPalindrome && str[i] != str[str.length() - i-1])			//palindrome 아님
		{
			isPalindrome = false;
			result = NOT_PALINDROME;

			begin_substr = str;
			end_substr = str;
			begin_substr.erase(i, 1);					//앞에꺼 자름
			end_substr.erase(str.length() - i - 1, 1);

			if (begin_substr[i] == begin_substr[begin_substr.length() - i - 1])			//앞에꺼인지 뒤에꺼인지
			{
				isbegin = true;
				
			}
			else if (end_substr[i] == end_substr[end_substr.length() - i - 1])
			{
				isbegin = false;
			}
			else
			{										//둘다 잘랐는데 아니면 아닌걸로 걍 반환
				result = NOT_PALINDROME;
				return result;
			}
			isPalindrome = true;
		}
		else if (result == NOT_PALINDROME && isPalindrome == true && isbegin)			//유사에서 앞을 자른게 맞을때
		{
			if (begin_substr[i] != begin_substr[begin_substr.length() - i - 1])			//그 다음줄이 palindrome 아니면
			{
				result = NOT_PALINDROME;
				return result;
			}
		}
		else if (result == NOT_PALINDROME && isPalindrome == true && !isbegin)
		{
			if (end_substr[i] != end_substr[end_substr.length() - i - 1])			//그 다음줄이 palindrome 아니면
			{
				result = NOT_PALINDROME;
				return result;
			}
		}
		

	}
	if (result == NOT_PALINDROME)
	{
		result = SEMI_PALINDROME;
		return result;
	}
	return result;

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	string input;
	int arr[31];


	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> input;
		arr[i] =isPalindrome(input);
		
	}
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;

}