#include <iostream>
#include <string>

int arr[40001];		//
int lis[40001];

int binarysearch(int left, int right, int target)
{
	int mid;

	while (left < right)
	{
		mid = (right + left) / 2;
		if (lis[mid] < target)
		{
			left = mid + 1;
		}
		else
			right = mid;
	}
	return right;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	//���ִ°��߿��� ���������� �ش��ϴ°͸� ������ ��

	//3 4 5 6 1 2

	int N;				//

	int j = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
	lis[0] = arr[0];
	for (int i = 1; i < N; i++)
	{

		if (arr[i] < lis[j])	//�ڿ� ���� ���� �� ������
		{
			int idx = binarysearch(0, j, arr[i]);		//��ġŽ����
			lis[idx] = arr[i];						
			
		}
		else				//�� ũ��
		{
			lis[j+1] = arr[i];				//���ϵڿ� �־��ְ�
			j++;
		}
	}

	std::cout << j + 1;

	return 0;

}