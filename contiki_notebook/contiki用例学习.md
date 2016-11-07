## 学习例程 ##

这里主要有两块开发板，型号相同：

- 编号1板子：MAC地址为：00 12 4b 00 0c 51 1f 1b
- 编号2板子：MAC地址为：00 12 4b 00 0c 51 1e 7b

在后面的试验中统一使用1号和2号板来描述；

这是我的全套家伙：

![](picture\hardware.jpg)

### 例程1  ###

#### 例程源代码 ####

- 1号板子使用的代码是：/contiki/examples/ipv6/rpl-board-router例程
- 2号板子使用的代码是：/contiki/examples/cc26xx/cc26xx-web-demo.c例程

#### 试验过程 ####

1. 编译1号板子的程序：进入相应例程的文件夹，运行`make TARGET=srf06-cc26xx BOARD=srf06/cc13xx`;
2. 利用SmartRF Flash Programmer 2+ XDS100V3进行软件烧写；
3. 将烧写好程序的1号板子利用一根USB线插入运行有Ubuntu的Thinkpad X220的机子上；如图所示：
	![](picture\case1-1.jpg)

4. 在X220上进入/contiki/tools目录编译`make tunslip6`;
5. 运行sudo ./tunslip6   aaaa::1/64  -s  /dev/ttyUSB0,如图所示：
	![](picture\case1-2.PNG)
6. 在ubuntu系统上通过浏览器查看网关节点，如图所示：
	![](picture\case1-3.PNG)
7. 如图所示还没有相应节点加入进来；
8. 编译2号板子的程序：进入相应例程的文件夹，运行`make TARGET=srf06-cc26xx BOARD=srf06/cc13xx`，将其下载到2号板子内，重启2号板子，其蓝色的led灯会快速闪烁，表明正在寻找父节点，找到之后蓝色灯慢闪烁；
9. 这个时候刷新网页可得到其子节点的IPV6的链路地址，如图所示：
   ![](picture\case1-4.PNG)
10.至此本试验结束；


#### 试验随想 ####


1. **疑惑**：感觉2号板子初次连接1号板子的时候需要和1号板子靠得很近，但将2号板子和1号板子间隔一定距离的时候再次断电连接的时候（1号板子保持不断电），确能正常连接；
2. **说明**：该试验只是一开始的一个了解性质的试验，后续会从基本的原理试验出发，慢慢去理解其实现过程；

2016-11-07 20:50:45 