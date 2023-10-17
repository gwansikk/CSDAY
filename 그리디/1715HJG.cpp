//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	priority_queue <int, vector<int>, greater<int>> pq;
//	int num;
//	int N;
//	cin >> N;
//	int tmp = 0;
//	int result = 0;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> num;
//		pq.push(num);
//	}
//
//	//sort(num, num+N);
//	if (N == 1)
//	{
//		result += 0;
//	}
//	//result += num[0];
//	//tmp += pq];
//	while(pq.size() != 1)
//	{
//		tmp = pq.top();
//		pq.pop();
//		tmp += pq.top();
//		pq.pop();
//		//만약 배열의 해당 수보다 작으면 다음 차례 크면 그 위치
//		pq.push(tmp);
//		result += tmp;
//	}
//	//result += result;
//	cout <<result;
//	//배열에 저장해서 
//	//더한값을 배열에 올바른 위치에 정렬해서 더하기
//	//20 35 40 40 50
//	//20+35  + 55+40  +  95+40  +  135+50
//	//55 + 95 + 135 + 185
//	//150 + 320 = 470
//	
//	//20+35=55
//	//40 40 50 55
//	//40+40=80
//	//50 55 80
//	//50+55=105
//	//80+105=185
//	//55+80+105+185
//	//425
//	//20 35 40 40 50		
//	//20 55 40 40 50			//더하고
//	//20 40 40 50 55			//정렬
//	//20 40 80 50 55			//더하고
//	//20 40 50 55 80			//정렬
//	//20 40 50 105 80			//더하고
//	//20 40 50 80 105			//정렬
//	//20 40 50 80 185			//더하고
//	//							정렬
//
//
//
//
//
//
//}