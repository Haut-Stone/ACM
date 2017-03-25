/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-03-03 17:24:43
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-03-25 20:48:36
 */

//http://vj.sdutacm.org/contest/view.action?cid=62898#problem/C

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int N = 35;
char Imap[N][N][N];
int vis[N][N][N];//标记数组，看来还是蛮重要的呢
int k, n, m, beginX, beginY, beginZ, endX, endY, endZ;
int to[6][3] = {{0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1, 0,0}};

struct node
{
    int x;
    int y;
    int z;
    int step;
};

int check(int x, int y, int z)
{
    //返回1则说明不符合条件
    if(x<0 || y<0 || z<0 || x>=k || y>=n || z>=m){
        return 1;
    }else if(Imap[x][y][z] == '#'){
        return 1;
    }else if(vis[x][y][z]){
        return 1;
    }
    return 0;
}


int bfs()
{
    node a, next;
    queue<node>Q;
    a.x = beginX;
    a.y = beginY;
    a.z = beginZ;
    a.step = 0;
    vis[beginX][beginY][beginZ] = 1;
    Q.push(a);
    while(!Q.empty()){
        a = Q.front();
        Q.pop();
        if(a.x == endX && a.y == endY && a.z == endZ){
            return a.step;
        }
        for(int i=0;i<6;i++){
            next = a;
            next.x = a.x + to[i][0];
            next.y = a.y + to[i][1];
            next.z = a.z + to[i][2];
            if(check(next.x, next.y, next.z)) continue;
            vis[next.x][next.y][next.z] = 1;
            next.step = a.step + 1;
            Q.push(next);
        }
    }
    return 0;
}



int main(void)
{
    while(scanf("%d%d%d", &k, &n, &m), n+m+k){
        //搞明白层次顺序还是比较重要的
        
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                scanf("%s", Imap[i][j]);
                for(int r=0;r<m;r++){
                    if(Imap[i][j][r] == 'S'){
                        beginX = i;
                        beginY = j;
                        beginZ = r;
                    }else if(Imap[i][j][r] == 'E'){
                        endX = i;
                        endY = j;
                        endZ = r;
                    }
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        int ans;
        ans = bfs();
        if(ans){
            printf("Escaped in %d minute(s).\n", ans);
        }else{
            printf("Trapped!\n");
        }
    }
    return 0;
}