#  一.提问的艺术





- static_cast 在编译期间执行， 还是在运行期间执行？
- 右值是无法获取地址吗？如果可以 和左值有什么区别



# 二 思路正确，回答才能正确



### 问1：什么是虚函数

### 答：

虚函数能实现多态必要条件

(1) 需要指针 或者引用

假如是一个普通类 ，出现切割现象。base类根本无法代表派生类。指针或者引用可以。

普通的函数不占用类大小，在编译时候确定运行地址，不同实力 使用同一个地址来调用。

call 具体函数地址。



（2） 虚函数



虚函数也是函数，编译时候确定运动地址，这个地址存储程序只读数据段。



例如 派生类 只有自己一个虚表，虚标函数运动地址：继承base类的，重写base，新增的

编译时候确定了 每个函数运动地址。

（3）  单继承



派生类 继承base虚函数指针，指向自己虚函数表

在调用是痛殴base.ptr[offert]



base * ptre =new devise();

pre->xxx





虚函数也是函数 不占用类大小编译确定运行弟子，无法表现跟具体new 对象有关系。

多态根本还是虚指针.,，这个跟不同实力类有关系。





## 问2 :堆栈的区别

答：默认栈对象是值拷贝（深拷贝），堆上对象拷贝（浅拷贝）



## 问题：右值是无法获取地址吗？如果可以 和左值有什么区别?



思路：

### 用汇编编解释什么是右值，右值引用，零时对象

### 从汇编代码上看，左值引用和右值引用本质都是指向值的地址，那为什么c++里要对2者做出区分?



a+4，b+3都是保存在ax寄存器中。故在func1中内存并没有为右值和临时变量分配空间



对于用户自定义类型的对象，寄存器可能“放不下”这些“右值对象”或“临时对象”，可能会在内存中开辟空间





- 首先明确一点，左值引用和右值引用，都是指针。

~~~c++
指针和引用区别：（1） 指针值传递，操作指针 不影响原来值 （2）引用指针和对象是一题的
  
int a;
 int&x=a;
 009913DE  lea         eax,[a]               lea是取地址指令，把a的地址放到eax寄存器里
 009913E1  mov         dword ptr [x],eax    把eax寄存器里的值放到
   
int*p=&a;
009913E4  lea         eax,[a]  
009913E7  mov         dword ptr [p],eax 
  
理解：来看看汇编代码，编译器做了什么一览无遗。可以说，完 全 一 致。不管是x还是p，都只不过是一个指向a的指针罢了。

常量引用
  
int a=1;
00EF13DE  mov         dword ptr [a],1   //1就是一个右值，立即数，放在汇编指令中。
 
 const int& x=1;
00EF13E5  mov         dword ptr [ebp-20h],1   //中间变量
00EF13EC  lea         eax,[ebp-20h]  
  
00EF13EF  mov         dword ptr [x],eax  //为x分配空间

  在这里首先编译器把1赋值给了一个无名的变量，然后又把这个无名变量的地址给了x。
  再想想onst int&x就是const int* const x，变量的值不会改变，指针值的变量不会改变，
  等于说这个x就和1彻底的绑在了一起，中间的那个无名变量永远不会被外界接触到。


  栈中局部变量 --左值
  表达式计算存储寄存器或者汇编代码中数据 右值
  
 再来说说右值的概念，判断右值和左值的最好方法就是，看它能不能取地址。

 int a=1;
010913BE  mov         dword ptr [a],1  
 
  int b=1;
010913C5  mov         dword ptr [b],1  

  int c=a+b;
010913CC  mov         eax,dword ptr [a]  
010913CF  add         eax,dword ptr [b]   
  //在这里a+b就是一个右值，它是活在寄存器里的一个值，他在内存里根本没有存在的位置，你无法对它取地址，这就是个右值
010913D2  mov         dword ptr [c],eax  //


  右值引用其实是开辟了两块空间，一块是右值引用类型那么大的匿名变量，一块是指向这个匿名变量的指
 
  int&& x=f();
00C729EE  call        f (0C711D6h)  
00C729F3  mov         dword ptr [ebp-14h],eax  
00C729F6  lea         eax,[ebp-14h]   //取出指针x的值，也就是匿名变量的地址。
00C729F9  mov         dword ptr [x],eax  

改变右值引用值的过程也分为两步，
取出指针x的值，也就是匿名变量的地址。
  
把右值赋值给地址所指的匿名变量。
https://blog.csdn.net/qq_33113661/article/details/89040579

~~~





回答：



左值和右值区别是存储位置一样

前者 存储在栈中，通过变量地址获取，

后者存储在寄存器中，寄存器访问。

其实【地址】=变量。

局部变量其实也是无名地址和全局变量不一样。有符号的



# 右值引用的好处，直接寄存器读取值



![img](https://oscimg.oschina.net/oscnet/be8fadfe9942317e581a5158e31d0a2f0af.jpg)

# 三。 我的N次回答



- 右值 是临时变量 执行就结束，无法获取地址 【❌】

只要是值，肯定有存放地方，不然cpu怎么读取，你我一致说，肯定没有地址 无法获取空间

- 看多了“右值是短暂的，左值是持久的”这种正确但是让人摸不到头脑的话【❌】