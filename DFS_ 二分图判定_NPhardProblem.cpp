/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-17 10:47:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-19 23:03:02
*/

//http://vj.sdutacm.org/contest/view.action?cid=62932#problem/J
//第一次做关于图的问题，有些懵逼。。。。
//自己不会写，只要研究一下大神的代码。

#include <cstdio>  
#include <stack>  
#include <queue>  
#include <cmath>  
#include <vector>  
#include <cstring>  
#include <algorithm>  
#include <iostream>
using namespace std;

const int N = 100007;//最大数值

vector<int> Imap[N];//这其实是一个向量数组。
vector<int> ans[2];//答案数组
int n,m;//点数和边数
int vis[N];//访问标记
int flag;
int type[N];//类型标记数组

void dfs(int x,int f,int ty){
    ans[ty].push_back(x);
    type[x]=ty;//标记该点所属的阵营
    vis[x]=1;//标记此点
    for(int i=0;i<Imap[x].size();i++){
        if(Imap[x][i]==f) continue;
        if(vis[Imap[x][i]]&&type[x]==type[Imap[x][i]]) flag=1;//这里同样是先行后列
        if(vis[Imap[x][i]]) continue;
        dfs(Imap[x][i],x,1-ty);
    }
}
int main(){
    scanf("%d%d",&n,&m);//读入点数，边数。
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);//读入一条边的起始位置
        Imap[a].push_back(b);//表示两边相连，貌似有点邻接表的意思。
        Imap[b].push_back(a);
    }
    for(int i=1;i<=n;i++){//遍历点
        if(flag) break;//如果已经不符合条件，就直接退出循环。
        if(!vis[i]) dfs(i,-1,0);//当该点未被询问时，搜索。
    }
    if(flag==1){//如果不成立，输出-1.
    	printf("-1\n");
    	return 0;
    }
    cout<<ans[0].size()<<endl;
    for(int i=0;i<ans[0].size();i++){
    	cout<<ans[0][i]<<" ";
    }   
    cout<<endl;
    cout<<ans[1].size()<<endl;
    for(int i=0;i<ans[1].size();i++){
    	cout<<ans[1][i]<<" ";
    }
    cout<<endl;
}