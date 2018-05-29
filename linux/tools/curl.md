curl: Command Line URL Viewer.

#　所下载文件内容默认写入stdout.
基本命令形式: curl URL

选项:

1. -o/--output <file> 将输出写到文件

        $ curl -o baidu.html www.baidu.com

2. -O/remote-name 直接将文件下载到本机, 而非内容

        $ curl -O http://ocs628urt.bkt.clouddn.com/table_1.1.png

        ＃　下载多个文件
        $ curl -O http://ocs628urt.bkt.clouddn.com/table_1.1.png -O http://ocs628urt.bkt.clouddn.com/table_java_2.png

3. -s/--silence 静默模式
4. -f/--fail 失败时不显示http错误
5. -C/--continue-at <offset> 断点续传

        # 让curl自动推断出正确的续传位置使用-C -
        curl -C - -O http://www.gnu.org/software/gettext/manual/gettext.html
