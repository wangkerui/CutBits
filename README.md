CutBits
=======

Split hundreds of binary bits into integers by specific size.

把一长串二进制位按照特定的位数分组，并转换为整数。

###Input/输入

十六进制字符表示的二进制位，或160位，或224位。

###Output/输出

或23位或24位一组的整数列表。输出十六进制格式的整数。

###Usage/用法

<pre>
$> gcc -o cutbits main.c
$> ./cutbits HEX_STRING
</pre>

HEX_STRING是二进制位的十六进制表示，如DFBAC841A5B6C6E9587ABB7323696BCBEE017B0EA4B184DADD89E756。

###Example/示例

输入
<pre>DFBAC841A5B6C6E9587ABB7323696BCBEE017B0EA4B184DADD89E756</pre>
（224位）

输出<pre>
9e756
9b5bb
3a92c6
700bd8
16bcbe
6e646d
561eae
5b6374
4841a5
1bf75
</pre>
（23位一组）
