/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-02-07 16:02:54
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-02 21:43:42
*/

/*
题意部分：
	奶牛们买了一个酸奶工厂，制造世界著名的酸奶。
	在之后的N周里，牛奶喝劳工的价格会不停的每周波动。
	所以，每周酸奶的生产单价c_i会改变。
	有一个仓库可以美周以S的单价存储单位数量的酸奶。
	向客户每周交付的酸奶量y_i
	求最小化的成本。
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 10011;

int fee[N];
int number[N];

//其实就是比较一下，加上储藏费用后，有没有下一周再买划算。
int main(void)
{
	int n = 0;
	int peerFee = 0;
	long long ans = 0;
	while(scanf("%d%d", &n, &peerFee) != EOF){
		ans = 0;
		for(int i=0;i<n;++i){
			scanf("%d%d", &fee[i], &number[i]);
		}
		for(int i=1;i<n;i++){
			fee[i] = min(fee[i-1]+peerFee, fee[i]);
		}
		for(int i=0;i<n;i++){
			ans+=fee[i]*number[i];
		}
		printf("%lld\n", ans);
	}
    return 0;
}