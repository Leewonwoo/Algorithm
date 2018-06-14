#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> p;
	
	cout << p.size() << endl;

	p.push_back(10);

	cout << p.size() << endl;

	p.push_back(9);

	cout << p.size() << endl;

	p.push_back(8);

	cout << p.size() << endl;

	p.pop();

	cout << p.size() << endl;

	cout << "POP : " << p.pop<int>() << endl;
	cout << "POP :" << p.pop<int>() << endl;

	if (p.isEmpty())
	{
		cout << "Stack Is Empty!" << endl;
	}
	else
	{
		cout << "Stack Size : " << p.size() << endl;
	}

	return 0;
}