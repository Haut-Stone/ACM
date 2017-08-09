/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-09 18:11:29
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-09 18:13:17
*/

//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1133
//先右端点升序，再左端点降序

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

typedef struct Node{
    int l;
    int r;
}Node;

bool cmp(Node x, Node y)
{
    if(x.r == y.r) return x.l > y.l;
    return x.r < y.r;
}

int main()
{
    Node a[10010];
    int n;
    int ans = 0;
    int r = -1e9-100;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
    }
    
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        if(a[i].l >= r){
            ans++;
            r = a[i].r;
        }
    }
    cout<<ans<<endl;
    return 0;
}