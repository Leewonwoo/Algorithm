#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
#define min(a,b) a > b ? b : a;

class Vertex;

class edge
{

public:
	int w;
	Vertex* start;
	Vertex* end;
	edge():w(0){}
};

class Vertex
{
public:
	int id;
	int parentId;//크루스칼의 싸이클을 확인하기 위해 만든 변수
	vector<edge> e;
	Vertex():id(0),parentId(-1){}
	Vertex(int _id):id(_id),parentId(-1){}

	void pushedge(Vertex* v, int w){
		edge _e;
		_e.start = this;
		_e.end = v;
		_e.w = w;
		e.push_back(_e);
	}

	void setParent(int pid)
	{
		parentId = pid;
	}

};

bool operator<(edge t, edge u)
{
	return t.w > u.w;
}

class Graph
{
public:
	vector<Vertex*> v;
	Graph(){}

	void kruskal()
	{
		//크루스칼 알고리즘은 모든 간선을 우선순위 큐에 넣고 디스조인트 셋에 포함되어 있는지(사이클 검사) 확인한다.		
		priority_queue<edge> pq;

		for(auto _v : v)
		{
			for(auto _e : _v->e)
			{
				pq.push(_e);
			}
		}

		while(!pq.empty())
		{
			cout << pq.top().start->id << " -> " << pq.top().end->id << endl;
			auto e = pq.top();
			
			if(e.start->parentId != e.end->parentId)
			{
				int uf = min(e.start->id, e.end->id);
				e.start->setParent(uf);
				e.end->setParent(uf);
			}

			pq.pop();
		}

	}

	void prim()
	{
		//프림 알고리즘은 BFS를 사용해 우선순위 큐에 모든 간선을 넣은 후 가중치가 적은 애들을 연결하며 방문 노드를 제외하여 연결한다.
		set<int> visited;
		priority_queue<edge> pq;

	}

	void dijkstra()
	{

	}

	void print()
	{
		for(auto _v : v)
		{
			cout << "Node id : " <<_v->id << endl;
			for(auto _e : _v->e)
			{
				cout << "From " << _v->id << " To " << _e.end->id << " And Weight is : " << _e.w << endl; 
			}
		}
	}

	~Graph()
	{
		while(v.size() > 0)
		{
			Vertex* _v = v.back();
			v.pop_back();
			delete _v;
		}
	}

};

int main(void)
{
	
	queue<Vertex* > qv;
	Graph g;

	//INIT Graph
	Vertex* v1 = new Vertex(1);
	Vertex* v2 = new Vertex(2);
	Vertex* v3 = new Vertex(3);
	Vertex* v4 = new Vertex(4);
	Vertex* v5 = new Vertex(5);
	Vertex* v6 = new Vertex(6);

	v1->pushedge(v2, 6);
	v1->pushedge(v4, 4);

	v2->pushedge(v1, 6);
	v2->pushedge(v3, 5);
	v2->pushedge(v4, 3);
	v2->pushedge(v5, 7);
	v2->pushedge(v6, 8);

	v3->pushedge(v2, 5);
	v3->pushedge(v6, 8);

	v4->pushedge(v1, 4);
	v4->pushedge(v2, 3);
	v4->pushedge(v5, 9);

	v5->pushedge(v2, 7);
	v5->pushedge(v4, 9);
	v5->pushedge(v6, 11);

	v6->pushedge(v3, 8);
	v6->pushedge(v2, 8);
	v6->pushedge(v5, 11);

	g.v.push_back(v1);
	g.v.push_back(v2);
	g.v.push_back(v3);
	g.v.push_back(v4);
	g.v.push_back(v5);
	g.v.push_back(v6);

	//g.print();
	g.kruskal();
}
