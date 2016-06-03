#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

const int maxnum=100;
const int maxint=99999;

int main(){
    int vertices;
    int edges;
    int v_range;
    double v_speed;
    int src;
    int des;
    int endpoint0;
    int endpoint1;
    int weight;
    double e_time;
    double dist[maxnum];    //當前點到src的最短距離
    int prev[maxnum];   //當前點的前一點

    cin>>vertices;
    cin>>edges;
    int A[vertices][vertices];
    for(int a=0;a<vertices;a++){
        for(int b=0;b<vertices;b++){
            A[a][b]=maxint;
        }
    }
    for(int i=0;i<edges;i++){
        cin>>endpoint0;
        cin>>endpoint1;
        cin>>weight;
        if(weight<A[endpoint0][endpoint1]){
        A[endpoint0][endpoint1]=weight;
        A[endpoint1][endpoint0]=weight;
        }
    }
    cin>>v_range;
    cin>>v_speed;
    cin>>src;
    cin>>des;

    for(int a=0;a<vertices;a++){
        for(int b=0;b<vertices;b++){
            if(A[a][b]>=v_range)
                A[a][b]=maxint;
        }
    }

    bool s[maxnum];
	    // 判断是否已存入该点到S集合中
	for(int i=0; i<vertices; i++)
	{
		dist[i] = A[src][i];
		s[i] = 0;     // 初始都未用过该点
		if(dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = src;
	}
	dist[src] = 0;
	s[src] = 1;

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
         // 注意是从第二个节点开始，第一个为源点
	for(int i=1; i<vertices; i++)
	{
		int tmp = maxint;
		int u = src;
		// 找出当前未使用的点j的dist[j]最小值
		for(int j=0; j<vertices; j++)
			if((!s[j]) && dist[j]<tmp)
			{
				u = j;              // u保存当前邻接点中距离最小的点的号码
				tmp = dist[j];
			}
		s[u] = 1;    // 表示u点已存入S集合中

		// 更新dist
		for(int j=0; j<vertices; j++)
			if((!s[j]) && A[u][j]<maxint)
			{
				int newdist = dist[u] + A[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}

	int path[maxnum];
	int path_seq = 0;
	path[path_seq] = des;
	path_seq++;
	int tmp = prev[des];
	while(tmp != src)
	{
		path[path_seq] = tmp;
		path_seq++;
		tmp = prev[tmp];
	}
	path[path_seq] = src;
	e_time=dist[des]/v_speed;

	cout<<"Route:";
	for(int i=path_seq; i>=0; i--){
			cout<<path[i]<<" ";
	}
	cout<<endl;
	cout<<"Total distance:"<<dist[des]<<endl;
	cout<<"Estimation time:"<<e_time<<endl;
}
