/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-27 21:48:03
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-28 09:15:42
*/

//二维费用背包的裸题

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1010;

int dp[N][N];

int neededPokemonBall[N];
int reducedEnergy[N];
int allPokemonBall;
int allEnergy;
int pokemonNumber;

int main(void)
{
	while(~scanf("%d%d%d", &allPokemonBall, &allEnergy, &pokemonNumber)){
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=pokemonNumber;i++){
			scanf("%d%d", &neededPokemonBall[i], &reducedEnergy[i]);
		}
		for(int k=1;k<=pokemonNumber;k++){
			for(int i=allPokemonBall;i>=neededPokemonBall[k];i--){
				for(int j=allEnergy;j>=reducedEnergy[k];j--){
					dp[i][j] = max(dp[i][j], dp[i-neededPokemonBall[k]][j-reducedEnergy[k]] + 1);
				}
			}
		}
		int power = allEnergy;
		int ans = 0;
		for(int i=1;i<=allEnergy;i++){
			if(dp[allPokemonBall][i] > ans){
				ans = dp[allPokemonBall][i];
				power = allEnergy - i;
			}
		}
		printf("%d %d\n", ans, power);
	}
	return 0;
}
