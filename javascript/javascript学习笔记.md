JavaScrip学习笔记
=================

## 一. 数据类型和变量

### 数据类型

#### Number

```JavaScript
134; 		// 整数
0.13; 		// 浮点数
1.23e3; 	// 科学记数法 1.23 * 1000
NaN; 		// not a number 当无法计算结果时用NaN表示
Infinity; 	// 表示无限大，当数值超过了JavaScript的Number所能表示的最大值时，就表示为Infinity
```

#### 字符串
	
`''` 与 `""` 之间的任意文本

* 特殊字符

	用转义字符\来标识

* 多行字符串

	用反引号 \`\` 表示

* 字符串连接 

	利用 `+` , 或者变量替换的方式

	```JavaScript
	var name = '小明';
	var age = 20;
	var message = '你好, ' + name + ', 你今年' + age + '岁了!';
	var message2 = `你好, ${name}, 你今年${age}岁了!`; // 注意反双引号与 ${} 共用
	```

* 操作字符串

	```JavaScript
	var s = 'hello world';
	s[0];		// 返回h, 获取字符串某个指定位置的字符，使用类似Array的下标操作，索引号从0开始
	s[0] = 'X';	// false, 字符串是不可变的，如果对字符串的某个索引赋值，不会有任何错误，但是，也没有任何效果

	// JavaScript为字符串提供了一些常用方法，注意，调用这些方法本身不会改变原有字符串的内容，而是返回一个新字符串
	s.toUpperCase(); // 返回'HELLO'
	var lower = s.toLowerCase(); // 返回'hello'并赋值给变量lower
	s.indexOf('world'); // 返回7, indexOf()会搜索指定字符串出现的位置
	s.substring(0, 5); // 从索引0开始到5（不包括5），返回'hello'. substring()返回指定索引区间的子串
	```

#### 布尔值
	
true 和 false

* 比较运算

	`==` : 它会自动转换数据类型再比较，很多时候，会得到非常诡异的结果
	`===`: 它不会自动转换数据类型，如果数据类型不一致，返回false，如果一致，再比较

	```JavaScript
	NaN === NaN; 			// false, NaN这个特殊的Number与所有其他值都不相等，包括它自己
	isNaN(NaN); 			// true

	1 / 3 === (1 - 2 / 3); 				// false, 浮点数相等比较
	Math.abs(1 / 3 - (1 - 2 / 3)) < 0.0000001; 	// true, 浮点数在运算过程中会产生误差，因为计算机无法精确表示无限循环小数. 要比较两个浮点数是否相等，只能计算它们之差的绝对值，看是否小于某个阈值
	```

#### 数组

* 创建数组

	```JavaScript
	[1, 2, 3.14, 'Hello', null, true]; // 数组可以包含任何类型
	new Array(1, 2, 3); // 创建了数组[1, 2, 3]
	```

* 数组的大小

	```JavaScript
	var arr = [1, 2, 3];
	arr.length; // 3

	arr.length = 6; // 直接给Array的length赋一个新的值会导致Array大小的变化
	arr; // arr变为[1, 2, 3, undefined, undefined, undefined]
	arr.length = 2;
	arr; // arr变为[1, 2]

	arr[5] = 'x';
	arr; // arr变为[1, 2, undefined, undefined, undefined, 'x']
	```

* 操作
	
	* indexOf()

		```JavaScript
		var arr = [10, 20, '30', 'xyz'];
		arr.indexOf(10); // 元素10的索引为0
		arr.indexOf(20); // 元素20的索引为1
		arr.indexOf(30); // 元素30没有找到，返回-1
		arr.indexOf('30'); // 元素'30'的索引为2
		```

	* slice()

		```JavaScript
		var arr = ['A', 'B', 'C', 'D', 'E', 'F', 'G'];
		arr.slice(0, 3); // 从索引0开始，到索引3结束，但不包括索引3: ['A', 'B', 'C']
		arr.slice(3); // 从索引3开始到结束: ['D', 'E', 'F', 'G']

		// 如果不给slice()传递任何参数，它就会从头到尾截取所有元素。
		```

	* push和pop
	



#### 对象

JavaScript的对象是一种无序的集合数据类型，它由若干键值对组成。

```JavaScript
var person = {
    name: 'Bob',
    age: 20,
    tags: ['js', 'web', 'mobile'],
    city: 'Beijing',
    hasCar: true,
    zipcode: null
};	// 不要忘了 ;
person.name // 返回Bob

var xiaohong = {
    name: '小红',
    'middle-school': 'No.1 Middle School'
};
xiaohong['middle-school']; // 'No.1 Middle School'. xiaohong的属性名middle-school不是一个有效的变量，就需要用''括起来. 访问这个属性也无法使用.操作符，必须用['xxx']来访问.
```

实际上JavaScript对象的所有属性都是字符串，不过属性对应的值可以是任意数据类型。
JavaScript规定，访问不存在的属性不报错，而是返回 `undefined`

* 添加与删除属性

	```JavaScript
	var xiaoming = {
	    name: '小明'
	};
	xiaoming.age; // undefined
	xiaoming.age = 18; // 新增一个age属性
	xiaoming.age; // 18
	delete xiaoming.age; // 删除age属性
	xiaoming.age; // undefined
	delete xiaoming['name']; // 删除name属性
	xiaoming.name; // undefined
	delete xiaoming.school; // 删除一个不存在的school属性也不会报错
	```

* 检测对象是否拥有某一属性

	* `in` 操作符

		利用 in 判断的属性有可能是继承来的
		`'name' in xiaoming; // true`
		`'grade' in xiaoming; // false`

	* `hasOwnProperty()` 方法

		判断一个属性是否是对象自身的

#### 其他

* null

	表示一个“空”的值，它和0以及空字符串''不同，0是一个数值，''表示长度为0的字符串，而null表示“空”

* undefined

	表示值未定义, 仅仅在判断函数参数是否传递的情况下有用

### 变量

变量名是大小写英文、数字、$和_的组合，且不能用数字开头

如果一个变量没有通过var申明就被使用，那么该变量就自动被申明为全局变量. 在strict模式下运行的JavaScript代码，强制通过var申明变量，未使用var申明变量就使用的，将导致运行错误。

```JavaScript
'use strict'; // 启用strict模式的方法是在JavaScript代码的第一行写上
```
