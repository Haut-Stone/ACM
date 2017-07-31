<p align="center">
  <a href="http://shallweitalk.com">
    <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/me.png" width=220 height=220>
  </a>
  <h3 align="center">Stone</h3>
  <p align="center">
    <a href="http://shallweitalk.com">
      <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/CodeChangeWorld.png" width=300 height=40>
    </a>
  </p>
</p>
<br>

## 题目

>[这里是题目哦](http://acm.hdu.edu.cn/showproblem.php?pid=3746)

## 题解

>[这里是题解哦](http://blog.csdn.net/raalghul/article/details/51097725)

## 思路

其实这道题很考验对next数组的理解，比如ABCCCCABC,其中：

```
___   ___
ABCCCCABC  
  ^-----^
012345678

next数组中next[8]记录的便是ABC上一次出现的位置的尾坐标。
```
也就是说这个next数组记录的是，已经匹配好的序列的上一次出现的位置。而ABC前的序列ABCCCC正好就是
一个循环节的最小单位。所以再添上中间没有被匹配到的字符的数量就好了

```
例如

            ___   ___
ABCCCCABCCCCABCCCCABC
              ^-----^

这里  cir = len - (iNext[len-1] + 1);
      |                 | 
      |                 ^
      ^               消除下标带来的影响
   循环节长度

```

cir = 6那么要添加的字符数就是：`cir - (len - (len / cir) * cir)`

这个就很好理解了。

## 总结

	wait...... 