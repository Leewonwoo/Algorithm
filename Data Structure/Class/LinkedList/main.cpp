#include "LinkedList.h"
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{

	LinkedList<int> *v = new LinkedList<int>();

	v->push(1);
	v->push(2);
	v->push(3);
	v->push(4);
	v->push(5);
	v->push(6);

	for (int i = 0; i < v->size(); i++)
	{
		cout << v->operator[](i) << endl;
	}

	cout << "Pop : " << v->pop() << endl;

	v->search_elem(3);

	v->delete_elem(3);

	for (int i = 0; i < v->size(); i++)
	{
		cout << v->operator[](i) << endl;
	}

	LinkedList<int> p;

	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	p.push(5);

	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << endl;
	}


	return 0;

}