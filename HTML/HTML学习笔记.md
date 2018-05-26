HTML学习笔记
============

## 一. 基本概念

### HTML标签

由尖括号包围的关键词, 不同标签有不同功能.

* 头部标签

<table>
	<tr>
		<th>头部标签</th>
		<th>用途</th>
	</tr>
	<tr>
		<td> &lt;title&gt; &lt;/title&gt; </td>
		<td>定义文档标题</td>
	</tr>
	<tr>
		<td> &lt;base&gt; </td>
		<td>定义了页面链接标签的默认链接地址</td>
	</tr>
	<tr>
		<td> &lt;link&gt; </td>
		<td>定义了文档与外部资源之间的关系, 通常用于链接到样式表</td>
	</tr>
	<tr>
		<td> &lt;meta&gt; </td>
		<td>定义了HTML文档中的元数据通常用于指定网页的描述，关键词，文件的最后修改时间，作者，和其他元数据.</td>
	</tr>
	<tr>
		<td> &lt;style&gt; &lt;/style&gt; </td>
		<td>定义了HTML文档的样式文件</td>
	</tr>
</table>

### HTML元素

HTML元素包含开始标签、元素内容及结束标签. 例: `<html>something</html>`

* 区块元素

	`块级元素`: 块级元素在浏览器显示时，通常会以新行来开始（和结束）
	`内联元素`: 内联元素在显示时通常不会以新行开始

<table>
	<tr>
		<th>元素</th>
		<th>功能</th>		
	</tr>
	<tr>
		<td>&lt;div&gt; &lt;/div&gt;</td>
		<td>
			块级, 可用于组合其他 HTML 元素的容器, 没有特定的含义, 可对整个块设置样式属性, 多用于文档布局
		</td>
	</tr>
		<tr>
		<td>&lt;span&gt; &lt;/span&gt;</td>
		<td>
			内联, 可用作文本的容器, 没有特定的含义, 可用于为部分文本设置样式属性
		</td>
	</tr>
</table>

### HTML属性

用于定义HTML元素的外观等. 一般描述于开始标签, 以名称/值对的形式出现.

### HTML注释

`<!-- This is a comment -->`

### HTML样式-CSS

如何使用CSS

* 内联样式	: 在HTML元素中使用style属性
* 内部样式表: 在HTML文档头部 &lt;head&gt; 区域使用 &lt;style&gt; 元素来包含CSS
* 外部引用	: 使用外部 CSS 文件

