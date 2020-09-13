# getline
cin.getline 将istream输入读取到字符数组中，需要指定长度，遇到超长字符串会出错。

getline 将istream输入读取到string对象中，可以读取超长字符串，遇到换行符停止，且丢弃换行符。

# Tip
1、windows下：输入流对象cin输入的结束符在windows下是ctrl+z，所以，按下ctrl+z，然后回车，程序就正常跳出循环了。
2、UNIX/Linux下：UNIX/Linux模拟流/文件结束标志为CRTL+D