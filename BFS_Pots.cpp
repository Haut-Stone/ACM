/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-05 12:27:02
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-05 12:28:07
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int maxn=110;

string op[7]={"","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(2,1)","POUR(1,2)"};

int l,r;
int a,b,c;
int vis[maxn][maxn],step[maxn*maxn];

struct node{
    int x,y;
    int opr;
    int pre;
}info[maxn*maxn];

void Solve(int x,int y,int opr){
    if(vis[x][y])
        return ;
    vis[x][y]=1;
    info[r].x=x;
    info[r].y=y;
    info[r].opr=opr;
    info[r].pre=l;
    r++;
}

void Print(){
    int ans=0;
    while(l!=0){
        step[ans++]=info[l].opr;
        l=info[l].pre;
    }
    printf("%d\n",ans);
    for(int i=ans-1;i>=0;i--)
        cout<<op[step[i]]<<endl;
}

void BFS(){
    info[0].x=0;
    info[0].y=0;
    vis[0][0]=1;
    l=0;
    r=1;
    int tx,ty;
    while(l!=r){
        if(info[l].x==c || info[l].y==c){
            Print();
            return ;
        }

        tx=a;
        ty=info[l].y;
        Solve(tx,ty,1);

        tx=info[l].x;
        ty=b;
        Solve(tx,ty,2);

        tx=0;
        ty=info[l].y;
        Solve(tx,ty,3);

        tx=info[l].x;
        ty=0;
        Solve(tx,ty,4);

        tx=info[l].x+min(a-info[l].x,info[l].y);
        ty=info[l].y-min(a-info[l].x,info[l].y);
        Solve(tx,ty,5);

        tx=info[l].x-min(b-info[l].y,info[l].x);
        ty=info[l].y+min(b-info[l].y,info[l].x);
        Solve(tx,ty,6);

        l++;
    }
    if(l>=r)
        printf("impossible\n");
}

int main(){
    while(~scanf("%d%d%d",&a,&b,&c)){
        memset(vis,0,sizeof(vis));
        BFS();
    }
    return 0;
}