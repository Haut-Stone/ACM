//题目来自白书 P51

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 100;
int dp[N][N];
int weight[N];//单个的重量
int value[N];//单个的价值
int num;
int maxCapacity;
int ans;

int package(int index, int maxCapacity)
{   
    for(int i=0;i<=maxCapacity;i++){
        dp[num][i] = 0;//将从最后一个物品过后的继续挑选的过程，初始化价值为0
    }
    for(int i=num-1;i>=0;i--){//表示从第i个开始装的状态
        for(int j=0;j<=maxCapacity;j++){
            if(weight[i] > j){
                dp[i][j] = dp[i+1][j];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i+1][j-weight[i]] + value[i]);
            }
        }
    }
    return dp[index][maxCapacity];
}

int main(void)
{
    INPUT_TEST;
    scanf("%d %d", &num, &maxCapacity);
    for(int i=0;i<num;i++){
        scanf("%d %d", &weight[i], &value[i]);
    }
    memset(dp, 0, sizeof(dp));
    ans = package(0, maxCapacity);
    printf("%d\n", ans);
    return 0;
}

