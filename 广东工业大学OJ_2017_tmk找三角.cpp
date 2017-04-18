/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-12 22:24:26
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-15 13:31:29
*/

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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)


const int N  = 100;
int vis[N];
int numberOfPoint;
int numberOfEdge;
int beginPos;
int endPos;
int callNumber;
int edgeQueue[N];
int queuePtr;


struct Node
{   
    int with;
    int distance;
};


vector<Node> a[N];
stack<int> S;

void read()
{
    Node solo;

    cin>>numberOfPoint;
    numberOfEdge = numberOfPoint - 1;

    for(int i=0;i<numberOfEdge;i++){
        scanf("%d%d%d", &beginPos, &endPos, &solo.distance);
        solo.with = endPos;
        a[beginPos].push_back(solo);
        solo.with = beginPos;
        a[endPos].push_back(solo);
    }
}
void dfs(int begin, int end)
{
    if(begin == end){
        return;
    }

    for(int i=0;i<a[begin].size();i++){
        if(!vis[a[begin][i].with]){//如果该点没有被走过
            vis[a[begin][i].with] = 1;
            S.push(a[begin][i].distance);
            dfs(a[begin][i].with, endPos);
            vis[a[begin][i].with] = 0;
            S.pop();
        }   
    }
    return;
}

int findTriangle()
{
    return 0;
}

int main(void)
{
    INPUT_TEST;

    int T;
    cin>>T;
    while(T--){
        read();

        scanf("%d", &callNumber);
        for(int i=0;i<callNumber;i++){
            scanf("%d %d", &beginPos, &endPos);
            vis[beginPos] = 1;
            dfs(beginPos, endPos);
            printf("%d\n", S.size());
            // findTriangle();
        }
    }
    return 0;
}   