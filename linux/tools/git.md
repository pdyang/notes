# Git Learning

## 一、什么是git

git是一个分布式版本控制系统

## 二、创建版本库

1.	选择一个文件夹作为版本库, 如 `learngit/`

	`$ git init`

	将目录 learngit/ 初始化为git管理的仓库，初始化操作在 `learngit/` 中创建了一个目录 `.git/` 里边是git管理版本库需要用到的文件

3.  配置用户信息

    用户配置文件有三级
    1. 所有用户级 `/etc/gitconfig`
    2. 个人用户 `~/.gitconfig`
    3. 仓库级 `.git/config`

    `git config --global/--system xxx` 分别配置个人级, 所有用户级配置文件.

		$ git config --global user.name pdyang
    	$ git config --global usre.email xxx@xxx.com
    	$ git config --global core.editor vim, 设置git默认编辑器
    	$ git config --list, 查看配置信息

4.  添加文件

	`$ git add "newfile"`

	把文件添加到暂存区, 即index中(暂存区, 用于暂时存储修改或添加的文件)

	`$ git commit -m "所做操作说明"`

## 三、时光穿梭

1.	查看文件状态

	`git status` (展示文件状态)

	`git diff "newfile"` (展示所做的修改, add/commit之前才能查看)

2.	查看文件变更历史

	`$ git log`

3.	回退与回退

	`$ git reset --hard HEAD^` (回到上一版本)

	`$ git reflog` (查看命令历史, 查找最新一次的ID)

	`$ git reset --hard ID` (回到Id对应的版本)

4.	删除文件

	`$ rm file`

	`$ git rm file`  (此时操作存于缓存区)

	`$ git commit -m "comment"` (提交缓存区删除操作)

	`$ git checkout -- file` (将操作加入缓存区前恢复文件)

	`$ git reset HEAD file` (操作加入缓存区后恢复文件)

	`$ git reset --hard ID` (提交后恢复, 但是会丢失更改)

## 四、远程仓库

1.	生成ssh密匙

	*	`ssh-keygen -t rsa -C "impdyang@163.com"`
	*	Add this key to github.

2.	添加远程仓库

	*	将本地仓库与远程仓库关联
		1.	创建远程仓库
		2.	关联
			```shell
			$ git remote add origin git@github.com:pdyang/learngit.git # 关联远程库
			$ git push -u origin master
			# 如果创建远程库时添加了README.md, 则需
			$ git pull --rebase origin master # 将远程库合并到本地
			$ git push origin master
			```

	*	从远程库克隆
		1.	在github上创建仓库
		2.	`git clone git@github.com:pdyang/xxx.git`

## 五、分支管理

### 1、流程

1.	创建分支

	`$ git checkout -b dev` (创建+切换分支)

    `$ git branch dev` (创建分支)

2.	查看分支

	`$ git branch`

3.	切换分支

	`$ git checkout dest-branch`

4.	合并分支

	`git merge merged-branch` (合并某分支到当前分支)

5.	删除分支

	`$ git branch -d xxx` (删除分支)

### 2、解决冲突
