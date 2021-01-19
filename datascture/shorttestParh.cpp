#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include<string>
#include<cstring>
using namespace std;


//定义顶点的最大值
#define MaxVertex 50
//定义顶点类型
typedef char VertexInfo[4];
//定义一个图的结构体
struct Graph
{
	//一维数组 -- 顶点信息
	VertexInfo vertex[MaxVertex];
	//二维数组 -- 边或者弧 对应关系 或者 权
	int edge[MaxVertex][MaxVertex];
	//顶点的个数
	int vertexNum;
	//边的条数
	int edgeNum;
};

//寻找顶点在一维数组中的位置
int localVertex(Graph &g, VertexInfo v)
{
	//遍历顶点数组
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//寻找值与v相等的顶点
		if (strcmp(v, g.vertex[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

//用邻接矩阵创建图 -- 有向的网图
void createGraph(Graph &g)
{
	cout << "输入图的顶点数和边数(用空格间隔)" << endl;
	cin >> g.vertexNum >> g.edgeNum;

	cout << "请输入图的" << g.vertexNum << "个顶点: " << endl;
	//循环输入
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//接收顶点的值
		cin >> g.vertex[i];
	}

	//初始化顶点之间的对应关系
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			//初始化为最大值
			g.edge[i][j] = INT_MAX;
		}
	}

	//定义变量
	int w;	//权重
	VertexInfo v1, v2;	//顶点
	//输入边和权重
	cout << "依次输入" << g.edgeNum << "条边的 弧尾 弧头  权重" << endl;
	//循环输入
	for (int i = 0; i < g.edgeNum; i++)
	{
		cin >> v1 >> v2 >> w;

		//找到v1在一维数组中的位置
		int m = localVertex(g, v1);
		//找到v2在一维数组中的位置
		int n = localVertex(g, v2);
		//赋值
		g.edge[m][n] = w;
		//如果是无向图
		g.edge[n][m] = w;
	}
}

//打印图
void printGraph(Graph &g)
{
	cout << "打印图 -- 邻接矩阵:" << endl;
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
		cout << g.vertex[i] << "\t";
		for (int j = 0; j < g.vertexNum; ++j)
		{
			if (g.edge[i][j] == INT_MAX)
			{
				cout << "∞" << "\t";
			}
			else
			{
				cout << g.edge[i][j] << "\t";
			}
		}
	}
	cout << endl;
}

//深度优先搜索
void DFS(Graph &g)
{
	//创建一个数组,标记节点是否已经被访问
	bool *visited = new bool[g.vertexNum];
	//数组初始化
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//全部标记为未访问
		visited[i] = false;
	}

	//创建栈对象
	stack<int> st;
	//从数组的第一个顶点开始
	//访问第一个顶点
	visited[0] = true;
	//打印第一个顶点
	cout << g.vertex[0] << " ";
	//下标压栈
	st.push(0);

	while (!st.empty())
	{
		int i;
		for (i = 0; i < g.vertexNum; ++i)
		{
			//取出顶点
			int top = st.top();
			//顶点的邻接点 -- 没有被访问过
			if (!visited[i] && g.edge[top][i] < INT_MAX)
			{
				//访问
				visited[i] = true;
				//打印
				cout << g.vertex[i] << " ";
				//下标压栈
				st.push(i);
			}
		}
		//查找完一遍,栈顶元素出栈
		if (i >= g.vertexNum)
		{
			st.pop();
		}
	}

	delete[] visited;
}

//广度优先搜索
void BFS(Graph &g)
{
	//创建一个数组,标记顶点是否被访问
	bool *visited = new bool[g.vertexNum];
	//初始化
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//false -- 未访问
		visited[i] = false;
	}

	//定义一个队列对象
	queue<int> q;
	//第一个顶点标记为已访问
	visited[0] = true;
	//打印第一个顶点
	cout << g.vertex[0] << " ";
	//顶点在数组中的下标,入队列
	q.push(0);

	while (!q.empty())
	{
		int front = q.front();
		for (int i = 0; i < g.vertexNum; ++i)
		{
			//寻找队列中队头的顶点的邻接点
			if (!visited[i] && g.edge[front][i] < INT_MAX)
			{
				//标记为已访问
				visited[i] = true;
				//打印
				cout << g.vertex[i] << " ";
				//下标入队列
				q.push(i);
			}
		}
		//寻找完所有的邻接点之后,下标出队列
		q.pop();
	}
	delete[] visited;
}

// 最短路径
// 迪杰斯特拉(Dijkstra)算法
// path哪一顶点到当前点的距离最近
void dijkstraPath(Graph &g, int *path, int *dist, int v0)
{
	int min = 0;
	int pos = v0;	// 访问的起始顶点
	//定义一个数组, 标记顶点是否已经被访问
	bool *visited = new bool[g.vertexNum];
	//初始化
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;	//顶点未访问
		if (i != v0) //排除顶点到出发点的计算
		{
			//初始化所有点的最近邻接点都是V0点
			path[i] = v0;
			// v0到各个顶点的权重
			dist[i] = g.edge[v0][i];
			cout << g.vertex[v0] << " 到 " << g.vertex[i]
				<< " 距离: dist[" << i << "]=" << dist[i] << endl;
		}
		else
		{
			// path[]数组 - 到当前点的最近的邻接点
			// dist[] 数组 - 从出发点到各个点的最短距离
			// i == v0没有任何意义, 不存在路径
			path[i] = -1;
			dist[i] = INT_MAX;
		}
	}
	//把v0标记为已访问
	visited[v0] = true;

	for (int i = 0; i < g.vertexNum; ++i)
	{
		min = INT_MAX;
		for (int j = 0; j < g.vertexNum; ++j)
		{
			// 没有被访问, 并且找到了拥有更小权值的边
			// path[]数组 - 到当前点的最近的邻接点
			// dist[] 数组 - 从出发点到各个点的最短距离
			if (!visited[j] && min>dist[j])
			{
				//保存最小值
				min = dist[j];
				//保存位置
				pos = j;
				cout << "+++ 顶点更新: pos =" << pos
					<< "顶点为: " << g.vertex[pos] << endl;
			}
		}
		//pos位置的顶点标记为已访问
		visited[pos] = true;

		// dist V0点到各个点的距离
		for (int j = 0; j < g.vertexNum; ++j)
		{
			// g.edge[pos][j] < INT_MAX - 判断pos->j这条边是存在的
			if (!visited[j] && dist[pos] + g.edge[pos][j] < dist[j] && g.edge[pos][j] < INT_MAX)
			{
				// 更新最短距离
				//例如 将j看成E  pos看成B，求出A到E最短路径
				dist[j] = dist[pos] + g.edge[pos][j];
				//更新路径, 到顶点j最近的顶点是pos
				path[j] = pos;
				cout << "=== 更新最短距离: dist[" << j
					<< "] = " << dist[j] << endl;
			}
		}
	}
}

// v0 - 起始点
// v  - 到达点
void showPath(Graph &g, int *path, int v0, int v)
{
	//创建一个栈对象
	stack<int> st;
	int temp = v;
	while (temp != v0)
	{
		st.push(temp);
		//寻找上一个顶点
		temp = path[temp];
	}
	st.push(v0);

	//打印路径
	while (!st.empty())
	{
		cout << g.vertex[st.top()] << " ";
		st.pop();
	}
}

int main()
{
	//定义一个图的对象
	Graph g;
	//用邻接矩阵创建图
	createGraph(g);
	//打印
	printGraph(g);

	//深度优先搜索
	cout << "深度优先搜索" << endl;
	DFS(g);
	cout << endl;

	//广度优先搜索
	cout << "广度优先搜索" << endl;
	BFS(g);
	cout << endl;

	/*==================================================
	==================================================*/
	cout << "迪杰斯特拉(Dijkstra)算法" << endl;
	// path数组 - 到当前点的最近的邻接点
	int path[50];
	// dist[] 数组 - 从出发点到各个点的最短距离
	int dist[50];
	// 出发点
	int v0 = 0;
	dijkstraPath(g, path, dist, v0);
	// A->D怎么走?多么长?
	// dist[3] = A->D的最短距离
	// path[3]
	for (int i = 1; i < g.vertexNum; ++i)
	{
		cout << "路径: ";
		showPath(g, path, v0, i);
		cout << "路径长度: " << dist[i] << endl;
	}

	return 0;
}
