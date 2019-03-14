
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <ctime>

using namespace std;

#define N 100

int sArr[N] = {0};

void randGen(){
	for(int i = 0; i < N; i++){
		sArr[i] = rand() % 100 + 1;
		for(int j = 0; j < i; j++){
			if(sArr[j] == sArr[i]){
				i--;
				break;
			}
		}
	}
}

void swap(int* a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partitioning(int l, int h)
{
	int fivot = sArr[h];
	int j = l - 1;

	for(int i = l; i <= h - 1; i++)
	{
		if(sArr[i] >= fivot)
		{
			j++;
			swap(sArr[i], sArr[j]);
		}
	}

	swap(sArr[h], sArr[j + 1]);

	return j + 1;
}

void quickSort()
{
	
	stack<int> stk;
	stk.push(0);
	stk.push(N-1);

	while(stk.size() > 1){

		int h = stk.top();
		stk.pop();
		int l = stk.top();
		stk.pop();

		int p = partitioning(l, h);

		if(l < p - 1)
		{
			stk.push(l);
			stk.push(p-1);
		}

		if(p + 1 < h)
		{
			stk.push(p+1);
			stk.push(h);
		}

	}

}

int main(void)
{

	srand((unsigned int)time(NULL));

	randGen();

	quickSort();

	for(int i = 0; i < N; i++){
		cout << sArr[i] << " ";
	}

	cout << endl;

	return 0;

}
