/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-22 19:25:30
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-23 19:52:07
*/

//这里是校赛的补题。http://218.28.220.249:50015/JudgeOnline/contest.php?cid=1020
#define A false
#define B false
#define C false
#define D false
#define E false
#define F false
#define G false
#define H false
#define I false
#define J true
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 1010;
const int INF = 99999999;

#if A

#endif

#if B

#endif

#if C

#endif

//rqy的键盘
#if D

#endif
//某科学的打麻将
#if E

#endif
//Hmz的女装
#if F

#endif

//最大子段和____模版 + 思维
#if G
//数据
/*
10
4
1 2 3 4
6
3 -1 -2 1 2 3
4
4 3 2 1
6
-2 4 1 2 3 -10
7
13 3 -1 -2 1 2 3
1
-12
4
-3 -5 -3 -9
5
1 2 3 4 5
6
10 -20 1 2 3 4
6
20 -20 10 5 4 2
*/

int n;
int a[N];
int l;//区间起点
int r;//区间终点

int onLine()
{
	l = 0;
	int thisSum, maxSum;
	thisSum = 0;
	maxSum = -INF;
	for(int i=0;i<n;i++){
		thisSum += a[i];//累加
		r = i;

		if((r-l)%2 == 1){
			int temp1 = thisSum - a[l];
			int temp2;

			if(l != 0){
				temp2 = thisSum + a[l-1];
			}else{
				temp2 = -INF;
			}
			thisSum = max(temp1, temp2);
			if(thisSum == temp1) l++;
			if(thisSum == temp2) l--;
		}

		if(thisSum > maxSum){
			maxSum = thisSum;//更新结果
		}else if(thisSum < 0){
			thisSum = 0;//如果有负的则抛弃掉
			l = i+1;
		}
	}
	return maxSum;
}

int main(void)
{
	INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans = onLine();
		
		cout<<ans<<endl;
	}
	return 0;
}

#endif

//ch追妹____dij + 路径记录
#if H
/*
2
2 1 1 2
1 2
3 2 1 3
1 2
2 3
 */

//仅dijkstra中用到的
int vis[N];
int dis[N];
int pre[N];
int iMap[N][N];
int vertexs;
int edges;//这里有个玄学问题，如果edges 放在vis[N],之前的话程序无法运行。。
int u, v;
int beginX;
int endX;

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}


int dijkstra(int beginX, int endX)
{	
	int min;
	int minVertex = 0;

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
		pre[i] = dis[i] != INF && i != beginX ? beginX : -1;//想将所有有链接的点的前一个点，设为出发点
	}

	dis[beginX] = 0;
	vis[beginX] = 1;

	for(int i=1;i<=vertexs-1;i++){//搜遍所有的点
		min = INF;
		for(int j=1;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] < min && !vis[j]){
				min = dis[j];
				minVertex = j;
			}
		}
		if(min == INF) break;//如果没有更小的点了，直接退出。
		vis[minVertex]  = 1;

		int u = minVertex;
		for(int v=1;v<=vertexs;v++){
			if(iMap[u][v] < INF){
				if(dis[u] + iMap[u][v] < dis[v]){
					 dis[v] = dis[u] + iMap[u][v];
					 pre[v] = u;
				}
			}
		}
	}
	return dis[endX];
}

void read()
{
	for(int i=1;i<=edges;i++){
		cin>>u>>v;
		iMap[u][v] = iMap[v][u] = 1;
	}
}

int main(void)
{
	// INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		cin>>vertexs>>edges>>beginX>>endX;
		init();
		read();
		while(1){
			if(beginX == endX){
				cout<<"chhappy"<<endl;
				break;
			}
			int ans = dijkstra(beginX, endX);
			if(ans == INF){
				cout<<"chsad"<<endl;
				break;
			}
			int now = pre[endX];
			iMap[now][endX] = INF;//切断路径
			if(now == beginX){
				beginX = endX;
				continue;
			}
			while(1){
				if(pre[now] == beginX) break;
				now = pre[now];
			}
			beginX = now;//更换起点
		}
	}
	return 0;
}
#endif

//小天使改名____模拟
#if I

/*
6
ch
hc
aa
aa
abc
abb
abc
abc
abc
acb
cab
abc
 */
string s1,s2;
int book1[N];
int book2[N];
int main(void)
{
	// INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		memset(book1, 0, sizeof(book1));
		memset(book2, 0, sizeof(book2));
		cin>>s1>>s2;
		int len1 = s1.size();
		int len2 = s2.size();
		int cnt = 0;
		if(len1 != len2){
			cout<<"NO"<<endl;
		}else{
			int same = 1;
			int YseOrNot= 0;
			for(int i=0;i<len1;i++){
				book1[s1[i] - 'a']++;
				book2[s2[i] - 'a']++;
				if(s1[i] != s2[i]){
					 cnt++;
					 same = 0;
				}
			}
			if(same){
				for(int i=0;i<26;i++){
					if(book1[i] >= 2){
						YseOrNot= 1;
					}
				}
				if(YseOrNot){
					cout<<"YES"<<endl;
				}else{
					cout<<"NO"<<endl;
				}
			}else{
				YseOrNot = 1;
				for(int i=0;i<26;i++){ 
					if(book1[i] != book2[i]) YseOrNot = 0;
				}
				if(YseOrNot && cnt == 2){
					cout<<"YES"<<endl;
				}else{
					cout<<"NO"<<endl;
				}
			}				
		}
	}
	return 0;
}	
#endif
//爱看电视的LsF...枚举╮(￣▽￣"")╭（代码丑的我都看不下去了）
#if J
/*
10 1 100
0 1 2 3 4 5 6 7 8 9
9 1 100
0 1 2 3 4 5 6 7 8
 */
int badKeyNumber;
int beginX;
int endX;
int isBadKey[N];
int minDis;

void init()
{
	memset(isBadKey, 0 , sizeof(isBadKey));
	minDis = 0;
}

int main(void)
{
	INPUT_TEST;
	while(~scanf("%d%d%d", &badKeyNumber, &beginX, &endX)){
		init();
		int temp;
		for(int i=0;i<badKeyNumber;i++){
			scanf("%d", &temp);
			isBadKey[temp] = 1;
		}
		minDis = abs(endX - beginX);
		vector <int> key;
		for(int i=0;i<=9;i++){
			if(!isBadKey[i]) key.push_back(i);
		}
		for(int i=0;i<key.size();i++){
			int temp = abs(endX - key[i]) + 1;
			if(temp < minDis) minDis = temp; 
			for(int j=0;j<key.size();j++){
				int temp = abs(endX - (key[i]*10 + key[j])) + 2;
				if(temp < minDis) minDis = temp; 
				for(int k=0;k<key.size();k++){
					int temp = abs(endX - (key[i]*100 + key[j]*10 + key[k])) + 3;
					if(temp < minDis) minDis = temp;
					for(int v=0;v<key.size();v++){
						int temp = abs(endX - (key[i]*1000 + key[j]*100 + key[k]*10 + key[v])) + 4;
						if(temp < minDis) minDis = temp;
						for(int s=0;s<key.size();s++){
							int temp = abs(endX - (key[i]*10000 + key[j]*1000 + key[k]*100 + key[v]*10 + key[s])) + 5;
							if(temp < minDis) minDis = temp;
							for(int b=0;b<key.size();b++){
								int temp = abs(endX - (key[i]*100000 + key[j]*10000 + key[k]*1000 + key[v]*100 + key[s]*10 + key[b])) + 6;
								if(temp < minDis) minDis = temp;
							}
						}
					} 
				}
			}
		}
		cout<<minDis<<endl;
	}
	return 0;
}
#endif
