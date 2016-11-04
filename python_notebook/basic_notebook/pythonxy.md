# Python(x,y)学习 #

## 程序问题汇总 ##

1.**运行程序出现错误**：`TTLibError: Not a TrueType or OpenType font (bad sfntVersion)`，参考了相关网站的解决方法：`http://blog.gmane.org/gmane.comp.python.epd.user/month=20120601`，具体方法是：

			
- 在相关的运行文件中添加：`from enthought.chaco.chaco_plot_editor import ChacoPlotItem`
- 修改：`C:\Python27\Lib\site-packages\kiva\fonttools\font_manager.py`文件：
		
		(1)修改在line59行包含TTLibError:59: from kiva.fonttools.fontTools.ttLib import TTFont, TTLibError
		(2)在line692行附近添加：
			except TTLibError:
    			verbose.report("Cannot read find %s", %fpath)
    			continue
这个问题基本就解决啦！2016-04-21 10:54:34 


2.**matplotlib的中文显示问题**：

		1.修改matplotlibrc文件：
			进入Python安装目录下的Lib\site-packages\matplotlib\mpl-data目录，
			打开matplotlibrc文件，删除font.family和font.sans-serif两行前的#，
			并在font.sans-serif后添加微软雅黑字体（Microsoft YaHei），代码如下：

			font.family         : sans-serif
			font.sans-serif     : Microsoft YaHei, Bitstream Vera Sans, Lucida Grande, Verdana, Geneva, Lucid, Arial, Helvetica, Avant Garde, sans-serif
		
		2.代码中别忘了unicode编码

		3.如果还不起作用，可以将 C:/Windows/Fonts/ 目录下的Microsoft YaHei字体文件拷贝到 [python_install_dir]/Lib/site-packages/matplotlib/mpl-data/fonts/ttf/ 目录下
		
		4.运行：
			>>>from matplotlib.font_manager import _rebuild
			>>>_rebuild()