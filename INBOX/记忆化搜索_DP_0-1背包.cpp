//用不优雅的dp优化的记忆化搜索，01背包
//例子见白书 P51

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 100;

int n = 4;//物品的个数
int weight[N] = {2, 1, 3, 2};
int value[N] = {3, 2, 4, 2};
int maxStorge = 5;


int dp[N][N];

int search(int index, int restStorge)
{
    int ans;
    if(dp[index][restStorge] != 0) return dp[index][restStorge];
    if(index == n){//搜索完了，那么还可继续装 value = 0 的物品 
        ans = 0;
    }else if(weight[index] > restStorge){//装不下
        ans = search(index+1, restStorge);
    }else{
        ans = max(search(index+1, restStorge), search(index+1, restStorge - weight[index]) + value[index]);
    }
    return dp[index][restStorge] = ans;
}

int main(void)
{
    int ans = search(0, maxStorge);
    printf("%d\n", ans);
    return 0;
}