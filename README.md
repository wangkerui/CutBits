CutBits
=======

Split hundreds of binary bits into integers with specific bit width. (把一长串二进制位按照特定的位数分组，并转换为整数。)

本项目是为了帮助朋友批量处理一些二进制位（十六进制形式的字符表示）。待处理的数据包括160位版本和224位版本，160位要求每24位分割成一个整数，224位要求每23位分隔成一个整数，并分别按照两种格式输出。格式参考<code>data/output_160_1.txt</code>和<code>data/output_160_2.txt</code>。

###文件（夹）说明

data: 输入文件和输出文件示例

&nbsp;&nbsp;-input_160.txt: 160位，按照24位分割

&nbsp;&nbsp;-input_224.txt: 224位，按照23位分割

&nbsp;&nbsp;-output*: 输出文件

rls:  可执行文件

&nbsp;&nbsp;-CutBits_24_160_format1.exe: 输入160位文件，输出格式1

&nbsp;&nbsp;-CutBits_24_160_format2.exe: 输入160位文件，输出格式2

&nbsp;&nbsp;-CutBits_23_224_format1.exe: 输入224位文件，输出格式1

&nbsp;&nbsp;-CutBits_23_224_format2.exe: 输入224位文件，输出格式2

*.h, *.c: 源文件

###Usage/用法

示例：CutBits_24_160_format2.ext <input_160.txt >output_160_2.txt
