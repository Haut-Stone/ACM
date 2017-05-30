/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-05-27 19:44:54
 */

//Memory Time 
//252K   16MS 

#include <iostream>
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

double dis[101];  //s到各点的权值
int vertex;     //货币种数
int eeges;  //边总数
int temp;     //兑换点数量
int rowMonryKind;     //持有第s种货币
double rowMonryValue;  //持有的s货币的本金

class exchange_points
{
public:
	int u;      //货币a
	int v;      //货币b
	double rate;   //rate
	double fee;   //手续费
}exc[202];

bool bellman(void)
{
	memset(dis,0,sizeof(dis));      //这里与bellman的目的刚好相反。初始化为源点到各点距离无穷小
	dis[rowMonryKind]=rowMonryValue;                       //即bellman本用于找负环，求最小路径，本题是利用同样的思想找正环，求最大路径

	/*relax*/

	bool flag;
	for(int i=1;i<=vertex-1;i++)
	{
		flag=false;
		for(int j=0;j<eeges;j++)
			if(dis[exc[j].v] < (dis[exc[j].u] - exc[j].fee) * exc[j].rate)         //寻找最长路径
			{                                                                 //进行比较的是"某点到自身的权值"和"某点到另一点的权值"
				dis[exc[j].v] = (dis[exc[j].u] - exc[j].fee) * exc[j].rate;
				flag=true;
			}
		if(!flag)
			break;
	}

	/*Search Positive Circle*/

	for(int k=0;k<eeges;k++)                                          
		if(dis[exc[k].v] < (dis[exc[k].u] - exc[k].fee) * exc[k].rate)           //正环能够无限松弛
			return true;

	return false;
}

int main(void)
{
	
	INPUT_TEST;

	int u,v;
	double rateAToB,feeAToB,rateBToA,feeBToA;   //临时变量

	while(cin>>vertex>>temp>>rowMonryKind>>rowMonryValue)
	{
		eeges=0;    //注意初始化
		for(int i=0;i<temp;i++)
		{
			cin>>u>>v>>rateAToB>>feeAToB>>rateBToA>>feeBToA;
			exc[eeges].u=u;
			exc[eeges].v=v;
			exc[eeges].rate=rateAToB;
			exc[eeges++].fee=feeAToB;
			exc[eeges].u=v;
			exc[eeges].v=u;
			exc[eeges].rate=rateBToA;
			exc[eeges++].fee=feeBToA;
		}

	    /*Bellman-form Algorithm*/

	    if(bellman())
	    	cout<<"YES"<<endl;
	    else
	    	cout<<"NO"<<endl;
	}
	 	
	return 0;
}