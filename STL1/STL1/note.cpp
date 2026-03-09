#define _CRT_SECURE_NO_WARNINGS 1


//     记录学习STL过程中的笔记
// 
//                                模板
// 
// 语法： template<typename T> 
//        函数的声明或定义
//		  template --- 声明创建模板
//		  typename --- 可换成class 
//		  T        --- 可换成其他字符 一般是大写
// 
// 注意事项:
//			自动类型推导 数据类型必须一致才可以使用
//			使用模板时 必须明确数据类型
// 
// 普通函数与模板函数的区别
//			普通函数会发生隐式类型转换
//			模板函数 用自动类型推导 不会发生隐式类型转换
//			模板函数 用显示指定类型 会发生隐式类型转换
// 
// 普通函数与模板函数的调用规则
//			1. 如果普通函数与模板函数都可以调用 则优先调用普通函数
//			2. 如果普通函数与模板函数都可以调用 可以通过空模板参数列表强制调用模板函数  myPrint<>(a,b)
//			3. 模板函数可以重载
//			4. 如果模板函数有更好的匹配 则优先调用模板函数
// 
// 模板局限性
//			模板不是万能的 例如不能同时比较自定义类型和内置类型的大小
//			所以可以通过具体化的模板版本 会优先调用具体化的
// 
// 类模板语法
//			template<typename T> 
//			类
// 
// 类模板与函数模板的区别
//			类模板没有参数自动类型推导的方式 只有显示指定类型
//			类模板的模板参数列表可以有默认参数类型
// 
// 类模板成员函数创建时机
//			普通成员函数在一开始创建 类模板成员函数是在调用时创建的( 因为不知道具体的数据类型 )
// 
// 类模板对象做函数参数
//		有三种传入方式
//			1. 指定传入类型  --- 直接显示对象的数据结构
//			2. 参数模板化    --- 将对象中的参数变成模板传入
//			3. 整个类模板化  --- 将这个对象类型模板化传入
// 
// 类模板与继承
//			子类要继承父类 如果父类是一个类模板 子类在声明时 要明确出父类模板中的数据类型  (但这样就起不到通用的效果)
//			所以想要灵活的使用父类模板 子类也需要写成类模板
// 
// 类模板成员函数在类外实现
//			1. 加上template<class T>
//			2. 加上作用域
//			3. 作用域后加上模板参数  
// 
// 类模板分开两个文件(.h .cpp)编写出错原因以及解决方案
//			原因 主文件中包含头文件 头文件只有函数声明 而类模板函数是在调用时创建的 
//			     所以主文件中调用类模板函数时会出现无法解析的外部命令
//			解决方案 1. 主文件中包含 .cpp 文件 因为.cpp 文件中有 .h 头文件 也有函数实现
//			         2. 在头文件中创建一个 .hpp 后缀的文件 将.h 和 .cpp 都写到 .hpp 文件中
// 
// 类模板与友元
//		全局函数类内实现
//				在访问权限上写全局函数 加上friend
//		全局函数类外实现
//					首先加上 <> 证明是类模板全局函数 否则是普通全局函数,会出现无法解析的外部命令的错误
//					函数实现时不需要加 <>
//					因为要提前让编译器知道 所以函数实现要写在声明前面 
//					friend void printPoint2<>(Point<T1, T2>& p);
// 
// 
// 
//                         STL
// string容器
//		构造函数原型
//			string()                    创建一个空的字符串
//			string(const char* str)     使用字符串str初始化
//			string(const string& str)   使用一个string初始化另一个string对象
//			string(int n,char c)        使用n个c初始化string
// 
//		字符串的赋值
//			string& operator=(const char* s);     char* 类型的字符串赋值给当前字符串
//			string& operator=(const string& s);   字符串s赋值给当前字符串
//			string& operator=(char c);            将单个字符赋值给当前字符串
//			string& assign(const char* s);        字符串s赋值给当前字符串
//			string& assign(const char* s,int n);  将字符串s的前n个字符赋值给当前字符串
//			string& assign(const string& s);      将字符串s赋值给当前字符串
//			string& assign(int n,char c);         将n个字符c赋值给当前字符串
// 
//		字符串拼接
//			string& operator+=(const char* s);    将s加到当前字符串后面
//			string& operator+=(const string& s);  将s加到当前字符串后面
//			string& operator+=(char c);			  只加一个字符
//			string& append(const char* s);        将s加到当前字符串后面
//			string& append(const char* s,int n);  将s的前n个字符加到当前字符串后面
//			string& append(const string& s);	  将s加到当前字符串后面
//			string& append(const string& s,int pos,int n);   将字符串s从pos开始的n个字符连接到字符串尾部
// 
//		字符串的查找
//			int find(const string& s,int pos = 0)const;          查找s出现的第一个位置，从pos开始(默认是0)
//			int find(const char* s,int pos = 0)const;			 查找s出现的第一个位置，从pos开始(默认是0)
//			int find(const char* s,int pos,int n)const;			 从pos开始查找s的前n个字符第一次的位置
//			int find(const char c,int pos = 0)const;			 查找字符c第一次出现的位置
//			
//			int rfind(const string& s,int pos = npos)const;      查找s最后一次出现的位置(默认是最后一个开始)
//			int rfind(const char* s,int pos = npos)const;		 查找s最后一次出现的位置(默认是最后一个开始)
//			int rfind(const char* s,int pos,int n)const;		 从pos开始查找s的前n个字符的最后一次位置
//			int rfind(const char c,int pos = npos)const;			 查找字符c最后一次出现的位置
// 
//			find查找是从左往右 rfind是从右往左
//			find找不到返回-1
// 
//		字符串替换
//			string& replace(int pos,int n,const string& s);		替换从pos开始n个字符为s
//			string& replace(int pos,int n,const char* s);		替换从pos开始n个字符为s
//			eg:
//			str1 = "abcdefghi";
//			str1.replace(1,3,"11111");     str1结果为  a11111efghi 字符串会变长
// 
//		字符串比较
//			字符串比较是按照每个字符的ASCII值进行比较
//			= 返回 0   > 返回1  <返回-1
//			int compare(cosnt string& s)const; 
//			int compare(cosnt char* s)const;  
//			
//		字符串的存取
//			char& operator[](int n);     通过[]访问
//			char& at(int n);             通过at方法获取
//			eg;  string str1 = "hello"
//				str1[0]  str1.at(0)都可以访问h  也可以修改
// 
//		字符串的插入与删除
//			string& insert(int pos,const char* s);          在第pos位置插入
//			string& insert(int pos,const string& s);	   在第pos位置插入、
//			string& insert(int pos,int n,char c);		   在第pos位置插入n个字符c
// 
//			string& erase(int pos,,int n = npos);         删除从第pos位置开始的n个字符
// 
// 
// 
// vector容器
//		基本概念
//			vector数据结构和数组相似，也称为单端数组
//			不同之处在于数组是静态空间 vector是可以动态扩展
//			动态扩展并不是在原有基础上接上新的空间 而是先找一个更大的空间 然后将原数据拷贝到新空间  在释放原空间
//			vector的迭代器是支持随机访问的迭代器
//		
//		构造函数  
//			vector<T> v;                        默认构造
//			vector<T> v2(v.begin(),v.end())    将v[v.begin(),v.end())赋值到当前容器
//			vector<T> v3(int n,elem);          将n个elem赋值给当前容器
//			vector<T> v4(const vector& v);   拷贝构造
//			
//		赋值
//			vector& operator=(const vector& vec);      重载=运算符
//			.assign(v.begin(),v.end())                 将[v.begin(),v.end())拷贝到当前容器
//			.assign(n,elem);                        赋值n个elem
// 
//		vector容器的容量与大小
//			empty();         判断容器是否为空
//			capacity();      返回容器的容量
//			size();          返回容器中元素个数
//			resize(int num); 重新指定容器长度为num  如果容器比原来长 则填充默认值  如果比原来短 则末尾超出部分删除
//			resize(int num,elem);   重新指定容器长度为num  如果容器比原来长 则填充elem  如果比原来短 则末尾超出部分删除
// 
//		插入与删除
//				push_back(elem);          尾插法
//				pop_back(elem);           尾删法
//				insert(const_iterator pos,elem);   在指定位置pos插入元素elem   ！！pos是一个迭代器
//				insert(const_iterator pos,int const,elem)    在指定位置pos插入n个元素elem  
//				erase(const_iterator pos)      删除迭代器指向的元素
//				erase(const_iterator start, const_iterator end)   删除迭代器从start到end间的元素
//				clear();                  删除所有元素
// 
//		数据存取
//				at(int index);       返回索引index所指的元素
//				operator[];          返回索引index所指的元素
//				front();             返回数组第一个元素
//				back();				返回数组最后一个元素
// 
//		互换容器
//				swap(vec);          当前容器与传入的容器进行元素互换 本质是头指针的互换
//				用途：  可以用来收缩内存空间
//					v原来容量是13万 大小为10万  resize(3)之后 容量为13万  大小为3
//						vector<int>(v).swap(v);	  先创建一个匿名对象容量和大小都为resize()之后的3  然后再与v进行互换
//						执行完系统会回收匿名对象的空间
// 
//		预留空间
//				reserve(int len);     容器预留出len个元素长度，预留位置不初始化 不可访问
//				作用：  避免内存开辟次数过多
// 
// 
// 
// deque容器
//		基本概念
//			又叫双端数组   可以对头部进行插入删除操作
//		deque与vector的区别
//			vector对头部的插入删除效率比较低  数据量越大 效率越低
//			vector对元素访问比deque快
//		内部结构
//			deque内部有一个中控器 维护每段缓冲区内的元素  缓冲区内存放真实的数据
//			中控器中存放缓冲区的地址
// 
//		构造函数
//			deque<T> d;          默认构造
//			deque<T> d2(d.begin(),d.end())   将d[d.begin(),d.end())区间拷贝给当前容器
//			deque<T> d3(int n,elem);   将n个elem拷贝给当前容器
//			deque<T> d4(d3);          将d3拷贝给d4
// 
//		赋值操作
//			deque& operator=(const deque& d);    重载=运算符
//			assign(d.begin(),d.end())     将d[d.begin(),d.end())区间拷贝给当前容器
//			assign(int n,elem);           将n个elem拷贝给当前容器
// 
//		大小操作
//			与vector一样 只是没有capacity()接口
// 
//		插入与删除
//			push_back(elem);     尾插法
//			push_front(elem);    头插法
//			pop_back();          尾删法
//			pop_front();         头删法
//			insert(pos,elem);         指定pos位置插入elem  ！！pos是一个迭代器        返回新数据的位置
//			insert(pos,n,elem);         指定pos位置插入n个elem  ！！pos是一个迭代器   无返回值
//			insert(pos,d.begin(),d.end());    指定pos位置插入[begin,end)区间的元素    无返回值  都是迭代器
//			erase(pos);              删除pos位置元素        返回下一个数据的位置
//			erase(beg,end);			删除[beg,end)区间的元素  返回下一个数据的位置
//			claear();				清空容器
//			
//		数据存取
//			at(int index)       返回索引为index位置的数据
//			operator[]          返回索引为index位置的数据
//			.back();            返回最后一个数据
//			.front();           返回第一个数据
//		排序
//			sort(d.begin(),d.end());      对区间内数据排序
// 
// 
// stack容器
//	
//		基本概念
//			stack又叫栈  先进后出的数据结构 只有一个出口
//			栈中只有顶端元素才能被访问到   因此栈不允许有遍历的操作
// 
//		构造函数
//			stack<T> s;        默认构造函数
//			stack(const stack& s);     拷贝构造
// 
//		赋值操作
//			stack& operator=(const stack& stk);
// 
//		数据存取
//			push();           入栈
//			pop();			  出栈
//			top();			  返回栈顶元素
// 
//		大小操作
//			empty();		 判断栈是否为空
//			size();			 返回栈内元素个数
// 
// 
// queue容器  队列
// 
//		基本概念
//			队列先进先出  有两个出口
//			一端只能入队  另一端只能出队
//			队列中只有队头和队尾可以被访问 因此不支持遍历操作
// 
//		构造函数
//			queue<T> que;    默认构造
//			queue(const queue& que)   拷贝构造
//			
//		赋值操作
//			queue& operator=(const queue& que);
//	
//		数据存取
//			push(elem)      入队
//			pop()			出队
//			front()			返回队头元素
//			back()			返回队尾元素
// 
//		大小操作
//			empty();        判断是否为空
//			size();			返回队列大小
// 
// 
// 
// list容器      链表
// 
//		基本概念
//			将数据进行链式存储
//			链表由一系列结点组成   结点由数据域和指针域组成  数据域存放数据 指针域存放下一个结点的地址
//			STL中的list是一个双向循环链表   双向指指针域有两个指针prev(指向前一个结点的地址)和next(指向后一个结点的地址)
//											循环指的是第一个节点的prev指向最后一个结点的地址  最后一个结点的next指向第一个结点地址
//			由于链表中存储不是连续的内存空间  所以迭代器只支持前移和后退  属于双向迭代器
//			it++可以       it += 1不可以
//			list优点
//				采用动态内存分配 不会像vector造成空间浪费
//				可以快速的插入和删除操作
//			list缺点
//				因为要存指针 所以空间开销大
//			list中  插入和删除操作不会造成原有迭代器的失效 在vector中是不成立的  因为vector会动态开辟空间 头指针会发生变化 所以迭代器会失效
// 
//		构造函数
//			list<T> L1;                  默认构造
//			list<T> L2(beg,end);         区间构造
//			list<T> L3(const list&L);    拷贝构造
//			list<T> L4(int n,elem)       n个elem构造
// 
//		赋值以及交换
//			list& operator=(const list& L); 
//			assign(beg,end);
//			assign(int n,elem);
//			.swap(lst);    交换操作
// 
// 		大小操作
//			empty();         判断容器是否为空
//			size();          返回容器中元素个数
//			resize(int num); 重新指定容器长度为num  如果容器比原来长 则填充默认值  如果比原来短 则末尾超出部分删除
//			resize(int num,elem);   重新指定容器长度为num  如果容器比原来长 则填充elem  如果比原来短 则末尾超出部分删除
// 
//		插入与删除
//			push_back(elem);     尾插法
//			push_front(elem);    头插法
//			pop_back();          尾删法
//			pop_front();         头删法
//			insert(pos,elem);         指定pos位置插入elem  ！！pos是一个迭代器        返回新数据的位置
//			insert(pos,n,elem);         指定pos位置插入n个elem  ！！pos是一个迭代器   无返回值
//			insert(pos,d.begin(),d.end());    指定pos位置插入[begin,end)区间的元素    无返回值  都是迭代器
//			erase(pos);              删除pos位置元素        返回下一个数据的位置
//			erase(beg,end);			删除[beg,end)区间的元素  返回下一个数据的位置
//			clear();				清空容器
//			remove(elem);           删除所有与elem匹配的元素
// 
//		数据存取
//			没有[]和at方式访问  因为内存不是线性空间
//			back();            返回最后一个元素
//			front();           返回第一个元素
// 
//		反转与排序  ---  都是成员函数 需要对象调用
//			对于所有不支持随机访问的迭代器  都不允许使用标准算法的函数(全局函数)
//			但其内部会有一些对应的算法 需要对象来调用
//			reverse();       使链表反转
//			sort();          排序链表
// 
//			bool myCompare(int v1,int v2)  数据类型根据链表中类型确定
//			{
//				return v1 > v2;   //第一个数比第二个数大 所以是降序
//			}
//			sort(myCompare);    降序链表
// 
//			对于自定义数据类型排序 需要写一个回调函数或仿函数  然后再调用sort
//
// 
// 
// set容器
//		基本概念
//			所有元素在插入时自动被排序
//			set/multiset是关联式容器  底层逻辑是二叉树
//			set/multiset使用时只需要包含一个set头文件即可
//			set容器不允许有重复值出现  multiset允许有重复值出现
//		
//		构造函数
//			set<T> st;					默认构造
//			set<T> st(const set& s);    拷贝构造
// 
//		赋值操作
//			set& operator=(const set& s);
// 
//		大小操作与交换
//			empty();          判断是否为空
//			size();           返回元素个数
//			swap(at)          交换两个容器
// 
//		插入与删除
//			insert(elem);      只有这一种插法
//			clear();           清空所有元素
//			erase(pos);        删除pos位置元素         返回下一个迭代器位置
//			erase(beg,end);    删除[beg,end)区间的元素 返回下一个元素的迭代器位置
//			erase(elem);       删除elem这个元素
// 
//		查找与统计
//			find(elem);        若找到返回这个元素的迭代器 可以通过*方式访问这个元素  若找不到返回end()的迭代器
//			const(elem);       返回这个元素的个数
// 
//		排序
//			默认是从小到大 指定从大到小需要调用仿函数(在插入数据之前)(仿函数就是重载() )即 set<int,myCompare> s1;
//			自定义数据类型需要指定排序规则  用仿函数(在插入数据之前)(仿函数就是重载() )即 set<int,comparePerson> s1;
//			
//		pair对组的使用
//			pair<type,type> p(value1,value2);
//			pair<type,type> p = make_pair(value1,vlaue2);
//			可以通过p.first 访问第一个数据
// 
// 
// map容器
//		
//		基本概念
//			所有元素都是pair对组类型
//			pair中第一个元素为key(键值) 第二个元素为value(实值)
//			所有元素都会根据key自动排序
//			map/multimap是关联式容器   底层逻辑为二叉树结构
//			可以根据key快速找到value值
//			map容器不允许有重复的key值出现  multimap允许有重复的key值出现
// 
//		构造函数
//			map<T1,T2> mp;
//			map<T1,T2>(const map& m);
// 
//		赋值
//			map& operator=(const map& m)
// 
//		大小与交换
//			empty();      判断是否为空
//			size();       返回map的大小
//			swap(map& m2) 交换
// 
//		插入与删除
//			第一种：   m.insert(pair<int,int>(1,10))  因为插入的都是对组
//			第二种：   m.insert(make_pair(2.20));
//			第三种：   m.insert(map<int,int>::value_type(3,30));
//			第四种：   m[4] = 40;
//			clear();           清空所有元素
//			erase(pos);        删除pos位置元素         返回下一个迭代器位置
//			erase(beg,end);    删除[beg,end)区间的元素 返回下一个元素的迭代器位置
//			erase(key);       删除值为key这个元素
// 
//		查找与统计
//			find(key);        若找到返回这个元素的迭代器 可以通过*方式访问这个元素  若找不到返回end()的迭代器
//			const(key);       返回这个元素的个数
// 
//		排序
//			默认是从小到大排序  可以通过仿函数更改排序规则 与set相似
// 
// 
// 
//								函数对象
// 概念
//		重载()的类	其对象叫做函数对象
//		函数对象使用重载的() 行为类似函数调用 也称仿函数
//		函数对象的本质是一个类  不是一个函数
// 
// 特点
//		函数对象在使用时 可以像普通函数那样调用 可以有参数 也可以有返回值
//		函数对象超出普通函数的概念 函数对象可以有自己的状态( 类中的属性 )(例如 可以统计这个函数调用了几次)
//		函数对象可以作为参数传递
// 
// 谓词
//		概念
//			重载()的返回值是bool类型的仿函数称为谓词
//			()的参数接收一个对象的仿函数称为一元谓词
//			()的参数接收一个对象的仿函数称为二元谓词
// 
// 内建函数对象   需要头文件  <functional>
//		STL自己写的
//		分为算术仿函数
//			关系仿函数
//			逻辑仿函数
//	
// 
//		算术仿函数
//			template<T> T plus<T>       加法仿函数
//			template<T> T minus<T>		减法仿函数
//			template<T> T mutiplies<T>	乘法仿函数	
//			template<T> T divides<T>    除法仿函数
//			template<T> T modulus<T>	取模仿函数
//			template<T> T negate<T>		取反仿函数
//			
//		关系仿函数
//			template<T> T bool equal_to<T>    等于
//			template<T> T bool not_equal_to<T>    不等于
//			template<T> T bool greater<T>    大于
//			template<T> T bool greater_equal<T>    大于等于
//			template<T> T bool less<T>    小于
//			template<T> T bool less_equal<T>    小于等于
// 
//		逻辑仿函数
//			template<T> T bool lagical_and<T>    逻辑与
//			template<T> T bool lagical_or<T>    逻辑或
//			template<T> T bool lagical_not<T>    逻辑非
// 
//			
//			
//                      STL算法
// 
// 遍历
//		for_each(beg,end,_func)    _func是普通函数或者仿函数
//								   仿函数时默认是值传递 如果需要统计次数 则需要传入引用ref
//				for_each(v.begin(), v.end(), ref(p));   //for_each 默认是值传递 传递的是p的副本p1   而p.count仍为0  所以需要传入引用
// 
//		transform(beg1,end,beg2,_func)   搬运容器 beg1第一个源容器的起始迭代器 beg2目标容器的起始迭代器
//				创建好目标容器后 需要先开辟空间
//				vTarget.resize(v.size());   //必须要提前开辟空间
//				vTarget.reserve(v.size());   只是预留了空间 但是size仍然为0  ！！！
// 
// 查找
//		find(beg,end,value);    无论找到与否 都会返回一个迭代器
//								如果操作的是自定义数据类型  需要在类里重载==(参数一定要用const) 让底层的find知道怎么比较自定义数据类型
//		find_if(beg,end,_Pred);   _Pred 代表谓词(返回值是bool的仿函数( 重载() 的类 ))
// 
//		adjacent_find(beg,end);   查找相邻重复元素  比如 12133 (33)
// 
//		binary_search(beg,end,value);   二分查找 必须是在有序的容器中进行  返回的是一个bool类型 不是一个迭代器
//										有序默认的是升序 在降序中需要一个仿函数  binary_search(v.begin(), v.end(), 4 ,greater<int>())
// 
//		count(beg,end,value);    统计自定义数据类型时 需要 重载==号
// 
//		const_if(beg,end,_Pred);   _Pred 谓词 返回值是bool的仿函数
// 
// 排序
// 
//		sort(beg,end,_Pred);     谓词可以省略 省略就是默认从小到大
// 
//		random_shuffle(beg,end);     洗牌算法  将区间内的元素打乱
// 
//		merge(beg1,end1,beg2,end2,beg3);      将两个有序的容器合并到一个容器中	这个容器也是有序的    创建好目标容器后要先开辟空间
// 
//		reverse(beg,end);     将区间内的元素反转
// 
// 拷贝和替换
// 
//		copy(beg1,end1,beg2);     将beg1到end1的数据拷贝到beg2中
// 
//		replace(beg,end,oldvalue,newvalue);   将beg到end中的旧值替换成新值
// 
//		replace(beg,end,_Pred,newvalue);
// 
//		swap(c1,c2);  传的是两个容器  交换两个同种类型的容器的所有内容
// 
// 算术生成算法    需要包含numeric头文件!!!
//		accumulate(beg,end,value);   第三个参数代表起始累加值
// 
//		fill(beg,end,value);      将区间内填充为value
// 
// 集合算法   
// 
// set_intersection     
//			交集的预设大小为最坏情况 两个容器中一个大容器包含一个小容器
//			会返回一个迭代器位置 代表交集的大小 方便打印输出 否则会打印交集以外的0
//			v3.resize(min(v.size(), v2.size()));   
//          vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
//			for_each(v3.begin(),itEnd,Print02());
// 
// set_union  
//			并集  并集预设大小  最坏情况 两个容器一个元素都不相同
//			v3.resize(v.size() + v2.size());
//			itEnd = set_union(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
//			for_each(v3.begin(), itEnd, Print02());
// 
// set_differecnce
//			差集  预设大小 最坏情况 两个容器没有交集 取最大的容器大小
//					两个集合必须是有序序列
// 
// 
// 
// 
//