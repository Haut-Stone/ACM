
//HDU 4738
//这题就是求出所有的桥，然后输出桥的权值的最小值。
//转的居然还是WA的我真是服了。。。。。
//
//这道题转自http://blog.csdn.net/yankunhaha/article/details/11770707
//题不难，就是题意坑比较大。

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <cmath>
using namespace std;

const int N=1010;
const int M=N*N;
const int INF = 99999999;

struct node{
	int to;
	int next;
	int c;
	int id;
}edge[M];

int dfn[N],low[N];
int head[N];
int timeCnt,edgeCnt;
int ans;
int vertexs,edges;

void tarjan(int u,int fa){

	dfn[u] = low[u] = ++timeCnt;

	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].to;
		int id=edge[i].id;
		if(fa==id) continue;
		if(!dfn[v]){
			tarjan(v,id);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v]){
				ans=min(ans,edge[i].c);
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}

void add(int u,int v,int c,int id){
	edge[edgeCnt].c=c;
	edge[edgeCnt].to=v;
	edge[edgeCnt].id=id;
	edge[edgeCnt].next=head[u];
	head[u]=edgeCnt++;
}

void init()
{
	edgeCnt = timeCnt = 0;
	ans = INF;
	memset(head,-1,sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(dfn,0,sizeof(dfn));
	memset(low, 0, sizeof(low));
}

int main()
{
	while(cin>>vertexs>>edges,vertexs||edges){
		init();
		for(int i=1;i<=edges;i++){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			add(u,v,c,i);
			add(v,u,c,i);
		}
		
		int ok = 0;
		for(int i=1;i<=vertexs;++i){
			if(!dfn[i]){
				ok++;
				tarjan(i,0);
			}
		}

		if(ans == 0) ans = 1;
		if(ans == INF) ans = -1;
		if(ok>1) ans = 0;
		for(int i=1;i<=vertexs;++i){
			cout<<dfn[i]<<"    "<<low[i]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}