#include <iostream>

using namespace std;

//class A
//{
//public:
//	//健身房，篮球场共用的
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
////private:
//	//私有的，卧房，厨房等
//	char _a;
//};
//int main()
//{
//	A aa1;
//	A aa2;
//	A aa3;//定义三个对象
//	cout << sizeof(A) << endl;//计算一下类的大小
//	cout << sizeof(aa1) << endl;//计算对象大小
//	aa1._a = 'd';
//	aa1.PrintA();
//}

////第一种1.类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1(){}
//private:
//	char _ch;
//	int _a;
//	double _d;
//};
//
////第二种：类中只有成员函数
//class A2 {
//public:
//	void f2(){}
//};
//
////第三章类中什么都没有
//class A3
//{
//
//};
//
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	//没有成员变量的类对象，大小为1，这个1是为了用来占位，表示对象存在的
//	A2 aa1;
//	A2 aa2;//用A2这个类定义两个对象
//	//这两个对象地址一样的吗？一开始定义的对象不同
//	cout << &aa1<< endl;
//	cout << &aa2 << endl;
//	return 0;
//}
//class Data
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//this 指针不能在形参和实参显示传递，但是可以在函数内部显示使用
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//	//其实编译器会对成员函数进行处理，变成这样
//	/*void Print(Data* const this)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Data d1, d2;//定义两个对象
//	d1.Init(2023, 4, 27);
//	d2.Init(2022, 2, 14);
//	d1.Print();
//	d2.Print();
//	//Data::_year;//不能这样写，没有规定
//	// //还有因为_year仅仅是图纸，没有开辟内存无法使用
//
//	//d1.year;//也不能这样对成员变量之间访问，因为有访问限定符存在
//	//d1.Print(&d1);//其实有一个隐式指针this将d1和d2的地址传给函数
//	//d2.Print(&d2);//
//
//
//}
//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();//这个并没有进对象里面去，因为成员函数并存在对象里面
//	//所以没有对对象访问--成员函数里面也没有对对象访问
//	//并没有对这个对象进行解引用
//	//所以是合法的
//	////第二种场景
//	//A::Print(nullptr);
//	//A::Print(p);
//
//}
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//		//这端代码编译器会处理成
//		//cout<<this->_a<<endl;
//		//这里就因为this是空指针，然后又访问空指针了属于非法访问了
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();//这个就不一样了
//}
//
//
typedef int DataType;
class stack//class可以定义一个类
{
public://访问限定符

	/*void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (_array == NULL)
		{
			perror("malloc");
		}
		_capacity = 3;
		_size = 0;
	}*/

	stack(DataType*a,int n)//函数重载
	{
		cout << "stack(DataType*a,int n)" << endl;
		
	}
	//构造函数---在对象实例化时自动调用
	stack(int capacity=4)//缺省值
	{
		cout << "stack(int capacipty=4)" << endl;
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		_capacity = capacity;
		_size = 0;
	}
	void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	void Pop()
	{
		if (Empty())
		{
			return;
		}
		--_size;

	}
	DataType Top()
	{
		return _array[_size - 1];
	}
	int Empty()
	{
		return _size == 0;
	}
	int Size()
	{
		return _size;
	}
	void Destroy()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
	~stack()
	{
		cout << "~stack()" << endl;
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private://访问限定符
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp =(DataType*)realloc(_array, sizeof(DataType) * newcapacity);
			if (temp == NULL)
			{
				perror("realloc");
		    }
			_array = temp;
			_capacity = newcapacity;
		}
	}
private://访问限定符
	DataType* _array;
	int _capacity;
	int _size;
};
//由于使用者在使用函数时经常忘记初始化函数和销毁函数，所以C++
//里就引入了几个默认函数--构造函数--初始化函数
//
//int main()
//{
//	stack s;//定义一个对象
//	/*s.Init();*/
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	s.Push(5);
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//	s.Pop();
//	s.Pop();
//	printf("%d", s.Top());
//	/*s.Destroy();*/
//	return 0;
//}
class Data
{
public:
/*	Data()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}
	*///构造函数可以构成重载;但不合法因为有歧义
	//当无参调用时存在歧义，是调用第一个还是第二个。第二个全是缺省参数，没有传参也可以使用这个函数
	//所以不可以同时存在
	Data(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year=1;//这里只是类成员变量声明，是没有内存的
	int _month=1;
	int _day=1;
	//内置类型-C++11支持，这里不是初始化，因为这里只是声明
	//这里给的是默认的缺省值，给编译器生成默认构造函数用的
};

//构造函数--初始化函数
//当没有写构造函数时，编译器会自己生成一个构造函数
//这个构造函数是会对自定义类型函数初始化，而对内置类型变量不初始化
//解决方案：内置变量声明的时候给定缺省值，这样就算没有给内置类型变量初始化
//也不会出现很大的问题。
int main()
{
	//构造函数的调用跟普通函数也不一样。
	Data d1;
		//Data d1()不可以这样写，会和函数声明有点冲突，编译器不好识别
	/*Data d2(2023,1,1);*///这样算调用构造函数是这样使用的
	d1.Print();//自动调用构造函数1-1-1;
	/*d2.Print();*///自己初始化2023-1-1;
	Data d3(2000);
	d3.Print();
	
}