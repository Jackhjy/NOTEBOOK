# 问题汇总 #

## 问题1 ##

当我把 DEBUG = True设为False的时候运行 python manage.py runserver 的时候报错  ：   `CommandError: You must set settings.ALLOWED_HOSTS if DEBUG is False.`

解决方案：`ALLOWED_HOSTS = [‘127.0.0.1‘, ‘localhost‘]`

2016-09-21 10:22:18 
