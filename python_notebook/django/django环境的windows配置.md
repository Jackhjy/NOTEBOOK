# windows7下django环境的配置 #

## (1)安装python ##

- 登录https://www.python.org/下载相应的版本：我在这里下载的是Windows x86-64 MSI installer;
- 点击安装之后是要添加相应的环境变量，修改环境变量Path,添加python.exe所在的文件夹；
- 打开cmd，运行python，检查环境变量是否生效；
## （2）安装pip ##
- 首先先去安装文件夹里面的Scripts脚本文件夹里面看是否已经有相应的pip安装了，在python2.7.12版本里面，已经默认安装了该程序，只需要再一次添加相关的环境变量即可；

## （3）安装virtualenv ##
- pip install virtualenv

## (4)安装supervisor ##
- 这里要注意啦！supervisor是基于linux的所以不能对其进行安装；

## （5）创建django虚拟环境 ##
- 首先在需要的位置创建相关的文件夹来安装虚拟环境；
- `cd /d d`:
- `mkdir djangoproject`；
- `cd djangoproject`;
- `mkdir run_env`;
- `virtualenv  --distribute run_env`：生成相关的运行环境;
- `run_env\Scripts\activate`:激活运行环境；
- `pip install Django==1.8.8`;
- pip install MySQL-python:这个时候发生了错误：Failed building wheel for MySQL-python(在windows上安装真麻烦)
- 解决办法：登录：**http://www.lfd.uci.edu/~gohlke/pythonlibs/#pyopengl**，查找相应的`MySQL-python-1.2.5-cp27-none-win amd64.whl`文件；
- 在终端输入`pip install xxxxx.whl` 即可安装完成所需的包，这个以后要学习一下！


## （6）安装git ##
- 上相关的git网站下载git安装包；

## (7)安装PIL库 ##

**是一个图片处理库**

- pip install Pillow


## （8）clone相应的程序库 ##
- `git clone https://github.com/Jackhjy/SZW.git`


## （9）安装notepad编辑器 ##
- 下载程序自行安装



## （10）运行django ##
- python .\manage.py runserver :注意一定要加python且是在安装的虚拟环境中；


## (11) 安装gunicorn##
- 在windows上部署就是麻烦，坑爹！不支持windows;