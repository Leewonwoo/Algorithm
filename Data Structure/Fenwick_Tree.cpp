#include <iostream>
#include <vector>
#include <time.h>
#include <queue>

using namespace std;

#define N 100

void update(int arr[], int i, int num)
{
	while (i <= N)
	{
		arr[i] += num;
		i += (i & -i);
	}
}

int sum(int arr[], int n)
{
	int s = 0;
	
	while (n > 0)
	{
		s += arr[n];
		n -= (n & -n);
	}

	return s;
}

int main()
{

	int arr[N + 1] = { 0 };
	int tree[N + 1] = { 0 };

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
		update(tree, i, arr[i]);
	}

	return 0;

}
