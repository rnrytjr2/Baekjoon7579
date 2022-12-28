// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
int N, M, Marray[101], Carray[101], maxdata;
int DP[10000001];
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> Marray[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> Carray[i];
		maxdata += Carray[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = maxdata; j >= 1; j--)
		{
			if (Carray[i] <= j)
			{
				DP[j] = max(DP[j], DP[j - Carray[i]] + Marray[i]);
			}
		}
	}
	for (int i = 1; i <= maxdata; i++)
	{
		if (DP[i] >= M)
		{
			cout << i;
			break;
		}
	}
}