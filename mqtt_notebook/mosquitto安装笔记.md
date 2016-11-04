# (1)Mosquitto安装笔记 #

1. `wget http://mosquitto.org/files/source/mosquitto-1.4.8.tar.gz`
2. `tar -zxvf mosquitto-1.4.8.tar.gz`
3. `cd mosquitto-1.4.8`
4. `sudo apt-get install libssl-dev`
5. `sudo apt-get install libc-ares-dev`
6. `sudo apt-get install uuid-dev`
7. `sudo make install`
8. `mosquitto`
9. `sudo ln -s /usr/local/lib/libmosquitto.so.1  /usr/lib/libmosquitto.lib.so.1`
10. `sudo ldconfig`

## 问题1                       ##

我想在Ubuntu中开机自运行我的mosquitto程序，然后修改了/etc/rc.local文件，将其程序添加到该文件的exit 0之前，但是经过几次启动Ubuntu都未运行，查询了一下发现是shell的问题，Ubuntu默认的shell是dash,而不是bash，我需要的是bash。

解决方法是：
- 第一种方法：在终端执行`dpkg-reconfigure dash`,接着选择no;
- 第二种方法：`rm /bin/sh`,`ln -s /bin/bash  /bin/sh`

## (2)Django1.8安装汇总 ##
- `sudo apt-get install build-essential python-dev libffi-dev`
- `sudo apt-get install python-pip`
- `sudo pip install -U setuptools`
- `sudo pip install pyopenssl ndg-httpsclient pyasn1`
- `sudo pip --default-timeout=100 install Django==1.8`
- 进入虚拟空间
- _1,`pip install django-suit==0.2.15`


## (3)安装Django1.8 python 的mysql支持组件 ##
- `sudo apt-get install libmysqld-dev`
- `sudo apt-get install libmysqlclient-dev`
- `sudo apt-get install python-dev`
- `sudo pip install MySQL-python`

## (4)安装nginx ##
最重要的是nginx的配置：
安装nginx:
**注意**
nginx安装依赖一下模块：

- gzip模块需要zlib库 `sudo apt-get install zlib1g-dev`
- rewrite模块需要pcre库 `sudo apt-get install libpcre3 libpcre3-dev `
- ssl功能需要openssl库 `sudo apt-get install openssl libssl-dev`

1. wget http://nginx.org/download/nginx-1.9.8.tar.gz
2. tar -zxvf nginx-1.9.8.tar.gz
3. cd nginx-1.9.8
4. ./configure
5. sudo make
6. sudo make install

**注意一定要在root下操作**

7. `apt-get install nginx-core`
8. `apt-get install nginx-extras`
9. `apt-get install nginx-full`
10. `apt-get install nginx-light`
11. `apt-get install nginx-naxsi`
12. `/usr/local/nginx/sbin/nginx` 运行服务器
13. 有一个非常有用的命令：`netstat tunlp` 查看端口的占用情况
14. `killall nginx`
15. `/usr/local/nginx/sbin/nginx -t -c /usr/local/nginx/conf/nginx.conf`,测试配置文件格式是否正确
16. `/usr/local/nginx/sbin/nginx -c /usr/local/nginx/conf/nginx.conf`，启动nginx
17. 网页中输入mqtt.smartznetwork.cn访问，检查是否启动成功

**-s reload是重载服务器命令**

**nginx的配置**
以后再说

## （5）Git的安装 ##
    sudo apt-get install git
`我是在jack用户下创建的`：

- 首先在网页上创建一个属于自己的仓库；
- 在自己主机上运行：`ssh-keygen -C 'cag125@qq.com' -t rsa`;
- 这样就会在本用户的根文件夹下生成一个.ssh的文件，里面有一个id_rsa.pub文件，复制里面的内容添加到网页上的SSH keys中，生成一个SSH；
- 验证该秘钥是否起作用：`ssh -T git@github.com`
- 接下来就创建一个本地仓库，(1)`git init`;	(2)`git add xxx.txt` ;	(3)`git commit -m 'My first commit'`;	(4)`git remote add origin git@github.com:Jackhjy/SZW.git`添加一个远程仓库地址;	(5)`git push -f origin master`强行（`-f`）推送本地仓库的更新到远程仓库;
- 注意第4步和第5步
## （6）安装virtualenv ##
    sudo pip install virtualenv

切换到root模式，添加django用户

在django用户根目录下执行一下命令：

- `mkdir virtual_1`
- `virtualenv --distribute virtual_1`
- `cd virtual_1`
- 检查是否创建成功
- `source bin/activate`,进入虚拟环境
- `deactivate`,离开虚拟环境

**--distribute 选项使virtualenv使用新的基于发行版的包管理系统而不是 setuptools 获得的包。 你现在需要知道的就是 --distribute 选项会自动在新的虚拟环境中安装 pip ，这样就不需要手动安装了。 当你成为一个更有经验的Python开发者，你就会明白其中细节。**

- `sudo pip install pyopenssl ndg-httpsclient pyasn1`
- `sudo pip --default-timeout=100 install Django==1.8.8`

**由于是另外一个虚拟环境，所以要重新安装上面的django和其他扩展库**

2016-03-24 20:30:18 

## (7)Gunicorn安装 ##

进入虚拟的virtual_1环境：

- `pip install gunicorn`
- 无意中发现有个这个东西，`pip install dreipol-django-fagungis`,这个软件包的描述是：`DJANGO + FAbric + GUnicorn + NGInx + Supervisor deploy for dreipol`,听起来很强大的样子，有机会测试一下！

## （8）安装supervisor ##

- `sudo pip install supervisor`
- `echo_supervisord_conf`：测试安装是否成功。

**supervisor 有两个可执行程序 -supevisord和supervisorctl**

- `supervisord` 是后台管理服务器，用来依据配置文件的策略管理后台守护进程，它会随系统自动启动。
- `supervisorctl`用于管理员向后台管理程序发送启动/重启/停止等指令。

**主配置文件**

- `mkdir -m 755 -p /etc/supervisor/`：创建supervisor配置文件目录/etc/supervisor/
- `echo_supervisord_conf > /etc/supervisor/supervisord.conf`：创建主配文件supervisord.conf
- `mkdir -m 755 conf.d`：创建项目配置文件目录；


主配置文件的路径位于：/etc/supervisor/supervisor.conf,主配置文件中的末尾两行文本：

    [include] 
    files = ./conf.d/*.conf

指明了supervisor会去/etc/supervisor/conf.d/目录下查找以.conf结尾的自配置文件，也就是/etc/supervisor/conf.d/目录下为每个后台应用而建的一个配置文件。

**子配置文件**

具体的官网配置描述在：`http://supervisord.org/configuration.html#program-x-section-settings`

子配置文件实例：

    [program:cat]
    command=/bin/cat
    process_name=%(program_name)s
    numprocs=1
    directory=/tmp
    umask=022
    priority=999
    autostart=true
    autorestart=unexpected
    startsecs=10
    startretries=3
    exitcodes=0,2
    stopsignal=TERM
    stopwaitsecs=10
    stopasgroup=false
    killasgroup=false
    user=chrism
    redirect_stderr=false
    stdout_logfile=/a/path
    stdout_logfile_maxbytes=1MB
    stdout_logfile_backups=10
    stdout_capture_maxbytes=1MB
    stdout_events_enabled=false
    stderr_logfile=/a/path
    stderr_logfile_maxbytes=1MB
    stderr_logfile_backups=10
    stderr_capture_maxbytes=1MB
    stderr_events_enabled=false
    environment=A="1",B="2"
    serverurl=AUTO

- `supervisord -c /etc/supervisor/supervisord.conf`：配置后运行supervisor;
- `cat /tmp/supervisord.log`:可以查看其启动的情况


**控制守护进程**

    //使得新配置生效
    supervisorctl update
    
    //控制所用进程
    supervisorctl  start all
    supervisorctl  stop all
    supervisorctl  restart all
    
    //定向控制指定进程
    supervisorctl  start xxx
    supervisorctl  stop xxx
    supervisorctl  restart xxx

**supervisorctl 子命令**
    
    #supervisorctl help
    
    default commands (type help <topic>):
    =====================================
    addclear  fgopen  quitremove  restart   start   stop  update
    avail  exit   maintail  pid   reload  reread  shutdown  status  tail  version

**问题1**

在我使用service supervisor start启动服务的时候，提示没有该服务，查阅了相关资料之后发现是我用pip安装的supervisor默认是没有添加进service中的，我后面运行了apt-get install supervisor后就可以使用service来控制supervisor了！如果要利用service命令来控制相关进程，就必须编写相关的启动脚本，并把它放到/etc/init.d文件夹中，才能使用！不过只要supervisor能够使用的话，我们直接使用supervisor就OK啦！


## git 相关使用攻略 ##

- `find . -name | xargs rm -rf`:'.'表示当前跟踪的项目的顶目录，作用是删除原始的git跟踪


## （9）tornado安装 ##

**进入mqtt用户：**

来到本用户根文件夹，执行一下操作：

- mkdir tornado
- virtualenv --distribute tornado
- cd ./tornado
- source ./bin/activate
- pip install tornado
- pip install torndb
- pip insall MySQL-python
- git clone https://github.com/Jackhjy/iots1.git


## (10)安装PIL库 ##

**是一个图片处理库**

- pip install Pillow

