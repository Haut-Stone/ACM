#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxN = 1100000;//最长的长度
int i, j, r, n, m, ansi, ansj, ansr;//传送门的位置？maybe
long long ans;//最后的正确答案
long long p[maxN];//开一个数组模拟长城

inline void make()
{
	long long temp;//临时变量
	ans = p[n];//1到n的距离
	i = j = 1;
	while(i <= n){//枚举第二个传送门的位置
		while(j<i && p[j] <= p[i] - p[j]) j++;//枚举c
		temp = max(p[i] - p[j], p[j-1]);//核心的长度计算。
		temp = max(p[n] - p[i], temp);
		if(temp < ans){
			ans = temp;
			ansi = i;
			ansj = j;
		}
		i++;
	}
}

int main()
{
	int T;
	scanf("%d", &T);//读取数据组数
	while(T--){
		memset(p, 0, sizeof(p));//长城的初始化
		scanf("%d", &n);
		for(i=2;i<=n;i++){
			scanf("%lld", &p[i]);//读入长城的长度
			p[i] += p[i-1];//每个小格子里存的是当前点距1的距离
		}
		make();
		printf("%lld\n", ans);
	}
	return 0;
}