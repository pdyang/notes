CSS学习笔记
===========

## 语法

`选择器 { 属性: 值; 属性: 值; }`

```
demo {
	color: red;
	text-align: center;
	// 注释
}
```

## 选择器

* Id选择器

	```
	#Id {
		// HTML元素以id属性来设置id选择器
	}
	```

* Class选择器

	```
	.Class {
		// class 选择器在HTML中以class属性表示 , class可以在多个元素中使用
	}
	p.Class {
		// 也可以指定特定的HTML元素使用class
	}
	```

## 多重样式表

* 外部样式表
* 内部样式表
* 内联样式表

`优先级` : （内联样式）Inline style > （内部样式）Internal style sheet >（外部样式）External style sheet > 浏览器默认样式