# 学习笔记 #

## contiki的安装 ##

- 首先是安装相应的开发环境，下载InstantContiki3.0的Ubuntu安装包，该系统已经详细配置完所需的全部开发环境，安装后即可使用；
- 进入系统的默认密码是user;
- 更新系统内默认的contiki，登录github，查找相应的软件仓库，在其/home/Instant Contiki/文件夹下备份老的contiki,从github上克隆想要的版本，这里克隆了最新的版本，`git clone https://github.com/contiki-os/contiki.git`(这里要注意的是其克隆主仓库的时候其里面引用的其它的库的时候，其库不会自动被克隆过来，需要进行手动克隆，不然在编译某一个目标工程的时候会提示某个文件无法找到)，这里是cc13xx的工程，在这里在contiki/cpu/cc26xx-cc13xx/lib/克隆其cc13xxware库，`git clone https://github.com/contiki-os/cc13xxware.git `


## 程序的编译 ##

- 进入contiki/examples/rime/文件夹，运行其指令make TARGET=srf06-cc26xx  BOARD=srf06/cc13xx
- 这样就在其该文件夹下生成了需要的.hex文件，等待烧写；




## contiki编译环境安装 ##

**主要安装在我的ubuntu的电脑上，非虚拟机**

**源代码准备**

- 进入root用户
- `adduser contiki`新建一个用户；
- 密码：123；
- 设置为有超级用户权限；
- 进入contiki用户根目录，`mkdir contiki`新建一个文件夹；
- 进入contiki文件夹；
- `git clone https://github.com/contiki-os/contiki.git`;
- `cd contiki/cpu/cc13xx/lib`;
- `rm -rf cc13xxware/ `;
- `git clone https://github.com/contiki-os/cc13xxware.git`,至此代码下载完成；

**编译环境准备**

- 登录https://launchpad.net/gcc-arm-embedded;
- 选择gcc-arm-none-eabi-4_9-2015q2-20150609-linux.tar.bz2;
- `sudo tar -jxvf  gcc-arm-none-eabi-4_9-2015q2-20150609-linux.tar.bz2  -C ~/contiki/toolchain/`;
- `sudo vi ~/.bashrc`;
- 在里面添加如下内容：(1)`export CC1310_TOOLCHAIN_HOME=~/contiki/toolchain/gcc-arm-none-eabi-4_9-2015q2`  (2)`export PATH=${CC1310_TOOLCHAIN_HOME}/bin:$PATH`;
- 重启终端检查工具链：`arm-none-eabi-gcc -v`;
- 大功告成！

## 安装cooja仿真器 ##

- `sudo apt-get install ant`:Apache Ant,是一个将软件编译、测试、部署等步骤联系在一起加以自动化的一个工具,大多用于Java环境中的软件开发。
- `cd contiki/tools/cooja/`
- `git submodule update  --init`
- `ant run`


## 下载器wget ##
Windows下的下载工具--迅雷，之所以下载速度快，乃是它能搜索资源、为己所用，而不是仅仅从原始地址这单一资源处下载。

Ubuntu下也有类似的工具，那就是aira2。
aira2是一个命令行下载工具，可以配合其他图形界面的下载软件使用。我用的是uget+aria2。uget本身是一个小巧实用的多线程下载工具，加上aria2作为插件，下载速度有明显提高。

一、安装。
uget和aria2都可以在“软件中心”中安装，但是版本太老啦，无法发挥作用，所以最好还是在终端中添加ppa进行安装：
1.uget的安装：
sudo add-apt-repository ppa:plushuang-tw/uget-stable
sudo apt-get update
sudo apt-get install uget
2.aria2的安装：
sudo add-apt-repository ppa:t-tujikawa/ppa
sudo apt-get update
sudo apt-get install aria2
安装完aria2后，可以在终端中运行aria2 -v，查看版本和支持的特性。需要1.10以上的版本才能支持资源搜索。


**学习网址是http://tieba.baidu.com/p/2041272976**