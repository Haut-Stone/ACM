/*
括号配对问题

时间限制：3000 ms  |  内存限制：65535 KB
难度：3
描述

现在，有一行括号序列，请你检查这行括号是否配对。
输入
第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度小于10000，且S不是空串），测试数据组数少于5组。数据保证S中只含有"[","]","(",")"四种字符
输出
每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No

样例输入

3
[(])
(])
([[]()])

样例输出
No
No
Yes
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {    
        vector<char> vec;
        string ch;
        vec.push_back(' ');
        cin>>ch;
        for(int i=0;i<ch.length();i++)
        {
            vec.push_back(ch[i]);
            if( vec.back()-1 == *(vec.end()-2) || vec.back()-2 == *(vec.end()-2))
            {
                vec.pop_back();
                vec.pop_back();
            }
        }
        if(vec.size()==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}