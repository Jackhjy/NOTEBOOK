# Mosquitto使用笔记 #


## 运行Mosquitto服务 ##
- mosquitto -v:启动代理服务器，参数-v的意思是打印更多调试信息；
- mosquitto_sub -v -t sensor:-t表示指定主题，此处为sensor,-v表示打印更多调试信息（订阅主题）；
- mosquitto_pub -t sensor -m 12:-t表示指定主题，-m表示指定消息内容（发布主题）；

## 运行Mosquitto服务（利用supervisor） ##
- 编写相关的配置文件，将其放在conf.d文件夹中，更新其supervisor的配置文件，即可完成；


## 安装Mosquitto-Auth-Plugin ##

2016-08-19 15:26:52 

这是一个验证后端，具体的安装方式见`http://www.360doc.com/content/15/1208/15/597197_518765114.shtml`

- git clone `https://github.com/jpmens/mosquitto-auth-plug.git`
- 配置相应的编译文件cp config.mk.in  config.mk；
- `vi config config.mk`;
	- `BACKEND_SQLITE ?= yes`;
	- `MOSQUITTO_SRC = /home/jack/myprojects/mqttproject/downlowd/mosquitto-1.4.8`;
	- `OPENSSLDIR = /usr/lib/ssl`;
	- 前提就是需要安装sqlite3的库和openssl,切记。
- `make`;
- 得到库文件`auth-plug.so`；
- sudo cp auth-plug.so  /etc/mosquitto/
- vi /etc/mosquitto/mosquitto.conf
- 添加下面几行到配置文件的末尾：
	- `auth_plugin  /etc/mosquitto/auth-plug.so`;
	- `auth_opt_backends  sqlite`;
	- `auth_opt_dbpath /etc/mosquitto/pw.db`;
	- `auth_opt_sqliteuserquery SELECT pw  FROM users  WHERE  username='%s'` ;
- 未完待续。。。。。2016-08-19 16:36:35 


## 安装openssl ##
2016-08-19 15:40:50 

- 检查是否安装openssl:`openssl version -a`;
- 安装了的话会显示详细的安装信息；
- 未安装的话参考`http://www.111cn.net/sys/linux/55787.htm`进行安装；
- 我的默认安装了1.0.1f版本；


## 安装sqlite3 ##

第一种安装方式：apt-get 安装

- `sudo apt-get install sqlite3  libsqlite3-dev`;

第二种安装方式:源码编译安装

- 登录`http://www.sqlite.org/download.html`，选择`Source Code---> sqlite-autoconf-3140100.tar.gz`;
- `tar -zxvf sqlite-autoconf-3140100.tar.gz`
- 进入解压缩的文件夹；
- `./configure`；
- `make`;
- `sudo make install`。

详细的安装方式见：`http://blog.csdn.net/u013539183/article/details/38383939`