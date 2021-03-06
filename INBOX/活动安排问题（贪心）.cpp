/*
有若干个活动，第i个开始时间和结束时间是[Si,fi)，只有一个教室，活动之间不能交叠，求最多安排多少个活动？

分析： 我们就是想提高教室地利用率，尽可能多地安排活动。
考虑容易想到的几种贪心策略：

（1） 开始最早的活动优先，目标是想尽早结束活动，让出教室。
然而， 这个显然不行，因为最早的活动可能很长，影响我们进行后面的活动。例如活动开始和结束时间分别为[0, 100), [1,2) ,[2, 3), [3, 4),[4,5]，安排［0，100)的这个活动之后，其他活动无法安排，可是最优解是安排除它外的4个活动。

（2） 短活动优先， 目标也是尽量空出教室。但是不难构造如下反例： [0,5) [5,10) [3, 7), 这里[3,7)最短，但如果我们安排了[3,7)，其它两个无法安排了。但是最优解显然是安排其它两个，而放弃[3,7)，可见这个贪心策略也是不行的。

（4） 看似最不对的策略——结束时间越早的活动优先。这个策略是有效的，我们可以证明。假设最优解OPT中安排了m个活动，我们把这些活动也按照结束时间由小到大排序，显然是不冲突的。假设排好顺序后，这些活动是a(1) , a(2), a(3)….am

假设按照我们的贪心策略，选出的活动自然是按照结束时间排好顺序的，并且也都是不冲突的，这些活动是b(1), b(2) …b(n)

问题关键是，假设a(1) = b(1), a(2) = b(2)…. a(k) = b(k)，但是a(k+1) != b(k+1)，回答几个问题：

(1)b(k+1)会在a(k+2), a(k+3), …. a(m)中出现么？
不会。因为b(k+1)的结束时间是最早的，即f(b(k+1)) <= f(a(k+1)),而a(k+2), a(k+3), …. a(m)的开始时间和结束时间都在f(a(k+1))之后，所以b(k+1)不在其中。

(2)b(k+1)和a(1), a(2), …. a(k) 冲突么？
不冲突，因为a(1), a(2), …. a(k)就是b(1), b(2), …. b(k)

(3)b(k+1)和a(k+2), a(k+3), …. a(m)冲突么？
不冲突，因为f(b(k+1)) <= f(a(k+1))，而a(k+2), a(k+3), …. a(m)的开始时间都在f(a(k+1))之后，更在f(b(k+1))之后。

因此我们可以把a(k+1) 换成b(k+1)， 从而最优解和我们贪心得到的解多了一个相同的，经过一个一个替换，我们可以把最优解完全替换成我们贪心策略得到的解。 从而证明了这个贪心策略的最优性。

最后，我们来提供输入输出数据，由你来写一段程序，实现这个算法，只有写出了正确的程序，才能继续后面的课程。

输入

第1行：1个数N，线段的数量(2 <= N <= 10000)
第2 - N + 1行：每行2个数，线段的起点和终点(-10^9 <= S,E <= 10^9)

输出

输出最多可以选择的线段数量。

输入示例

3
1 5
2 3
3 6

输出示例

2
 */
//
//  main.c
//  贪心练习2
//
//  Created by Jack Lee on 2016/11/30.
//  Copyright © 2016年 SJH. All rights reserved.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node{
    int start;
    int end;
}Node;

bool cmp(Node x, Node y)
{
    if(x.end < y.end) return true;
    if(x.end == y.end && x.start > y.start) return true;
    return false;
}

int main()
{
    Node a[10010];
    int n;
    int ans = 0;
    int end = -1e9-100;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        cin>>a[i].start>>a[i].end;
    }
    
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        if(a[i].start >= end){
            ans++;
            end = a[i].end;
        }
    }
    cout<<ans<<endl;
    return 0;
}