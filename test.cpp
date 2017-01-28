/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-28 19:07:35
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

const int N = 10100;
//
//今天是新春大作战专场
//
string s;
int main()
{
	int n,p,q;  
    cin>>n>>p>>q;  
    cin>>s;  
    for(int i=0;i<150;i++)  
    {  
        for(int j=0;j<150;j++)  
        {  
            if(i*p+j*q==s.size())  
            {  
                cout<<i+j<<endl;  
                for(int k=0;k<i;k++)  
                {  
                    for(int t=0;t<p;t++)  
                        cout<<s[k*p+t];  
                    cout<<endl;  
                }  
                for(int k=0;k<j;k++)  
                {  
                    for(int t=0;t<q;t++)  
                        cout<<s[i*p+k*q+t];  
                    cout<<endl;  
                }  
                return 0;  
            }  
        }  
    }  
    return puts("-1"); 
}