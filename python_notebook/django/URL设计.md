## URL设计 ##

[https://docs.djangoproject.com/en/1.9/topics/http/urls/#views-extra-options](https://docs.djangoproject.com/en/1.9/topics/http/urls/#views-extra-options)

**例子：**

（1）

    from django.conf.urls import url
    from . import views  
    urlpatterns = [
    url(r'^articles/2003/$', views.special_case_2003),
    url(r'^articles/([0-9]{4})/$', views.year_archive),
    url(r'^articles/([0-9]{4})/([0-9]{2})/$', views.month_archive),
    url(r'^articles/([0-9]{4})/([0-9]{2})/([0-9]+)/$', views.article_detail),
    ]

**上面的例子描述的是：**<br />
1. 需要从URL中捕获一个参数值，只需要在参数周围加上圆括号'()'`parenthesis` ;<br />
2. 不需要加上前导的'/'( `leading slash`),使用`^articles/`而不是`^/articles/`;<br />
3. 每个正则表达式字符串前面的'r'是可选的，但推荐使用；

**解析例子：**<br />
1. 一个`/articles/2005/03/`将会匹配第三个url正则表达式，视图函数为：`views.month_archive(request, '2005', '03')`；<br />
2. 一个`articles/2005/3`将不会匹配任何url正则表达式，因为月份需要两个数字；<br />
3. 一个`/articles/2003/`将会匹配第一个url正则表达式，视图函数为：`views.special_case_2003(request)`<br />
4. 一个`/articles/2003`将不会匹配任何url正则表达式，因为2003后面没有匹配到一个结尾的`'/'`<br />
5. 一个`/articles/2003/03/03`将会匹配最后一个url正则表达式，视图函数为： `views.article_detail(request, '2003', '03', '03')`

**有名组：**<br />
上面的例子用了一个简单的，没有命名规则的组去捕获URL中的参数，并通过位置参数传送个视图函数，`这里有一种更高级的用法`，运用有名的规则表达式获取URL中的参数，并将他们通过键值传送给视图函数；<br />
这里使用`（？P<name>pattern）`来进行参数匹配，`pattern`是正则表达式部分，`name`是参数键字符串；<br />


    from django.conf.urls import url
    from . import views

    urlpatterns = [
    url(r'^articles/2003/$', views.special_case_2003),
    url(r'^articles/(?P<year>[0-9]{4})/$', views.year_archive),
    url(r'^articles/(?P<year>[0-9]{4})/(?P<month>[0-9]{2})/$', views.month_archive),
    url(r'^articles/(?P<year>[0-9]{4})/(?P<month>[0-9]{2})/(?P<day>[0-9]{2})/$', views.article_detail),
    ]

这个例子是上面例子的完成相同功能的另外一种写法：<br />
1. 一个`/articles/2005/03/`将会调用`iews.month_archive(request, year='2005', month='03')`而不是`views.month_archive(request, '2005', '03').`<br />
2. 一个`/articles/2003/03/03/`将会调用`views.article_detail(request, year='2003', month='03', day='03')`<br />

**注意：**匹配得到的是字符串，而不是数字类型，只是数字字符串罢了！


### 为视图指定缺省的参数 ###


----------

### include其他的URLconfs ###


----------

### 从父URLconfs接收任何捕捉到的参数 ###


----------

### 参数的嵌套 ###


----------

### 为视图函数传递额外的选项 ###


----------


### 传递额外的选项到include() ###


----------

**网页有三种方式向服务器传递参数：**<br />
1. 利用表单或者是Ajax的get方法,最大支持字节数2048bytes，这种方法只需要使用request.GET.get()来获得所需要的参数，`http://www.example.com/?color=#fff`，这种提交方式不太安全！<br />
2. 利用表单或者是Ajax的post方法,最大支持字节数2GB，这种方法只需要使用request.POST.get()来获得所需要的参数，`http://www.example.com/`，推荐这种方式！<br />
3. 利用表单或者是Ajax的动态action的方法，这种方法传递的参数，服务器需要利用最上面所讲的参数捕捉方法来弄，`http://www.example.com/#fff/`,**不知道这个#会不会有影响**，这个用法介于GET和POST之间，选择性使用；

### GET与 POST方法的区别 ###

1. get是从服务器上获取数据，post是向服务器传送数据。
2. get是把参数数据队列加到提交表单的ACTION属性所指的URL中，值和表单内各个字段一一对应，在URL中可以看到。post是通过HTTP post机制，将表单内各个字段与其内容放置在HTML HEADER内一起传送到ACTION属性所指的URL地址。用户看不到这个过程。
3. 对于get方式，服务器端用Request.QueryString获取变量的值，对于post方式，服务器端用Request.Form获取提交的数 据。
4. get传送的数据量较小，不能大于2KB。post传送的数据量较大，一般被默认为不受限制。但理论上，IIS4中最大量为80KB，IIS5中为 100KB。
5. get安全性非常低，post安全性较高。