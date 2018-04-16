#include <iostream>
#include <vector>
#include <time.h>
#include <queue>

using namespace std;

#define N 100

int init(int a[], int t[], int node, int start, int end)
{
	if (start == end)
	{
		return t[node] = a[start];
	}
	else
	{
		return t[node] = init(a, t, node * 2, start, (start + end) / 2) + init(a, t, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

int sum(int t[], int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return t[node];
	}
	return sum(t, node * 2, start, (start + end) / 2, left, right) + sum(t,node*2+1,(start+end)/2+1,end,left,right);
}

void update(int t[], int node, int start, int end, int index, int diff)
{
	if (index < start || index > end) return;
	t[node] = t[node] + diff;
	if (start != end)
	{
		update(t, node * 2, start, (start + end) / 2, index, diff);
		update(t, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main()
{

	int arr[N + 1] = { 0 };
	int tree[N + 1] = { 0 };

	for (int i = 1; i <= N; i++) 
	{
		scanf("%lld", &arr[i]);
	}



	return 0;

}
