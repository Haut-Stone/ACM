/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-16 15:06:41
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-17 10:25:30
*/
#include <cstdio>  
#include <stack>  
#include <queue>  
#include <cmath>  
#include <vector>  
#include <cstring>  
#include <algorithm>  
#include <iostream>
using namespace std;

const long long N = 5050;
const long long INF = 10000000000;//这里开始给小了，wa了好几次
struct Node
{   
    long long x;
    long long a;
    long long b;
    long long c;
    long long d;
};

Node point[N];
long long Inext[N];//后继数组

long long jumpDistance(Node a, Node b)//计算两点间距离
{
    if(b.x < a.x){
        return abs(a.x-b.x) + a.c + b.b;
    }else{
        return abs(a.x-b.x) + a.d + b.a;
    }
}

int main(void)
{
    long long n;
    long long start;
    long long end;
    long long oldPoint;

    scanf("%lld%lld%lld", &n, &start, &end);//数据的读入
    for(int i=1;i<=n;i++){
        scanf("%lld", &point[i].x);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld", &point[i].a);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld", &point[i].b);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld", &point[i].c);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld", &point[i].d);
    }
    long long ans  = jumpDistance(point[start], point[end]);
    Inext[start] = end;//表示直接从a跳到b,用数组模拟链表
    for(int i=1;i<=n;i++){
        if(i == start || i == end){
            continue;
        }
        long long k = INF;
        for(int j=start;j!=end;j=Inext[j]){
            long long distance = jumpDistance(point[j], point[i]) + jumpDistance(point[i], point[Inext[j]]) - jumpDistance(point[j], point[Inext[j]]);
            if(distance < k){
                k = distance;
                oldPoint = j;
            } 
        }
        ans += k;
        Inext[i] = Inext[oldPoint];
        Inext[oldPoint] = i;
    }
    printf("%lld\n", ans);
    return 0;
}