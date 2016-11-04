# django_framework学习 #

## 数据库migrate ##

- 对于之前已存在于数据库的表，在新建rest的时候不需要进行migrate,不然会发生错误，其技巧是先将该app包含在`settings.py`的APP设置中，运行`makemigrations`,接着在`migrate`的时候不要把相关app（其数据模型在数据库中已经存在）包含进`settings.py`的app设置项目中，带其它相关的数据模型同步成功后在将该app添加进去，这样就可以直接使用该模型啦！
- 注意其数据库相关模型的表名是其app的小写加上数据模型名称的小写（例如app名字为`IoT`，数据模型名为`DevM`,则对应于数据库的表的名字就是`iot_devm`）2016-08-05 15:40:10 