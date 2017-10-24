/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-24 21:52:55
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-24 21:55:01
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define LL long long
#define INPUT_TEST freopen("/home/parallels/Desktop/INPUT", "r", stdin)
using namespace std;

const int N = 50050;

struct Node
{
    int id;
    int value;
}query[N], a[N];

int flag[N];
int res[N];

bool cmp(const Node &a, const Node &b)
{
    return a.value < b.value;
}

int main(void)
{
	//INPUT_TEST;
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i].value);
        a[i].id = i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d", &query[i].value);
        query[i].id = i;
    }

    //从小到大排序
    sort(a+1, a+1+n, cmp);
    sort(query+1, query+1+m, cmp);


    memset(res, 0, sizeof(res));
    int ans = 1;
    int left = 1;
    for(int i=1;i<=m;i++){
        while(a[left].value <= query[i].value && left <= m){
            if(a[left].id == 1){
                //is first
                if(flag[2]){
                    ans--;
                }
            }else if(a[left].id == n){
            	//is last
                if(flag[n-1]){
                    ans--;
                }
                //middle
            }else{
                if(flag[a[left].id-1] && flag[a[left].id+1]){
                    ans--;
                }else if(!flag[a[left].id-1] && !flag[a[left].id+1]){
                    ans++;
                }
            }
            //this point is under water
            flag[a[left].id] = 1;
            left++;
        }
        res[query[i].id] = ans;
    }
    for(int i=1;i<=m;i++){
        printf("%d\n", res[i]);
    }
}