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

## 题意

3000组样例，给你一个数字a，你需要找一个大于等于a，并且离a最近的数字t，并同时符合以t-1， t， t+1为三边所构成的三角形的面积为一个整数。a的范围是1->10^30。数据相当的大。

## 样例输入

```cpp
4 //样例数
1 //每个a
2
3
4
```
## 样例输出

```cpp
4 //每个t
4
4
4
```

## 思路

这题首先通过打表，找出较小的符合条件的t，打表之后发现有一个递推式`f[i] = 4*f[i-1] - f[i-2]`然后用大数类来打一张表。遍历打好的表，遇到大于a的第一个数字就输出

## 总结

很坑，现场赛的时候， 由于没有准备好大数模版，最后时间不够了没有敲出来，还是java大法好啊，自带大叔类，对于java来说只需要找出递推式就好了，省去了C++处理大数据所需要浪费的很多时间。看来准备`充足的大数模版还是很有必要的啊！！`