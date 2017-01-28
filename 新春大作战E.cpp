/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-28 18:44:19
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-28 18:50:12
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int Min = 1e9+5,ans=0;
int a[200005];
vector<int>P;

//http://codeforces.com/problemset/problem/610/B

int main(void)
{
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(Min>=a[i])
        {
            Min = a[i];
            ans = i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==Min)
            P.push_back(i);
    }
    P.push_back(P[0]+n);
    long long tmp = 0;
    for(int i=1;i<P.size();i++)
        tmp = max(tmp,1LL*P[i]-1LL*P[i-1]-1LL);
    printf("%lld\n",1LL*n*Min+1LL*tmp);
    return 0;
}