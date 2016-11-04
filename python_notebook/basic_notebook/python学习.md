# Python 学习汇总 #

## （1）编码问题 ##

### 1.经验法则###

1. `decode early`:在输入或者声明字符串的时候，尽早地使用decode方法将字符串转化成Unicode编码格式
2. `unicode everywhere`：在程序内使用字符串的时候统一使用Unicode格式进行处理，比如字符串拼接、字符串替换、获取字符串的长度等操作
3. `encode late`:在输出字符串的时候（控制台/网页/文件），通过encode方法将字符串转化为你所想要的编码格式，比如utf-8等。

### 2.解决办法 ###

1. 用u'中文'代替'中文'：指定编码格式为Unicode；
2. 遵循PEP0263法则，声明编码格式：
	
	`#-*- coding : <encoding name> -*-`

3.Reset默认编码：
	
	import sys
	sys.setdefaultencoding('utf-8')

2016-04-11 14:12:42 