/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-08 20:38:34
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-08 20:39:52
*/

//题目:https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1284
//关于容斥原理:http://www.cppblog.com/vici/archive/2011/09/05/155103.html
//题解:http://blog.csdn.net/u012773338/article/details/40077107

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
 
int main()  
{  
    long long n;  
    scanf("%lld",&n);  
    printf("%lld",n-(n/2+n/3+n/5+n/7-n/6-n/10-n/14-n/15-n/21-n/35+n/30+n/42+n/70+n/105-n/210));  
    return 0;  
}  