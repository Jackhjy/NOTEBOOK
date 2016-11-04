# Git技巧汇总 #

## git使用ssh密钥 ##

**注意：git使用https协议，每次pull，push都要输入密码，相当的繁琐，使用git协议，然后使用ssh密钥，这样就可以省去每次都输密码。**

1. 先生成密钥对：
	1. `ssh-keygen -t rsa -C "cag125@qq.com"`；
	2. 接连敲三次回车，保持默认设置，如果要修改也可以修改之后再回车；
	3. windows默认存储ssh在`C:\Users\Administrator\.ssh`文件夹下。
2. 添加公钥到github账户：
	1. 登陆你的github帐户。然后 Account Settings -> 左栏点击 SSH Keys -> 点击 Add SSH key；
	2. 然后你复制id_rsa.pub里面的公钥内容，粘贴进“Key”文本域内。 title域，你随便填一个都行；
	3. 完了，点击 Add key。
	4. 验证一下这个key是否正常工作：`ssh -T git@github.com`。
3. 在github上新建一个仓库，设置相应的参数；
4. `git clone https://github.com/Jackhjy/xb.git`克隆该仓库
6. 修改远程主机的值：`git remote rm origin`;`git remote add origin git@github.com:Jackhjy/xb.git`,使用ssh方式，这样在添加代码的时候就不用输入密码账号啦！;
7. 验证远程主机：`git remote -v` 得到其远程主机的值；
8. 至此就能在本地添加代码后，push到远程主机的仓库里面啦！



## fit添加远程仓库 ##

- `git remote add  origin git@github.com:Jackhjy/iots-rest.git`:添加远程仓库 origin
- `git remote rm origin` :删除远程仓库origin
	
