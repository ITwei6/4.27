#include <iostream>

using namespace std;

//class A
//{
//public:
//	//���������򳡹��õ�
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
////private:
//	//˽�еģ��Է���������
//	char _a;
//};
//int main()
//{
//	A aa1;
//	A aa2;
//	A aa3;//������������
//	cout << sizeof(A) << endl;//����һ����Ĵ�С
//	cout << sizeof(aa1) << endl;//��������С
//	aa1._a = 'd';
//	aa1.PrintA();
//}

////��һ��1.���м��г�Ա���������г�Ա����
//class A1 {
//public:
//	void f1(){}
//private:
//	char _ch;
//	int _a;
//	double _d;
//};
//
////�ڶ��֣�����ֻ�г�Ա����
//class A2 {
//public:
//	void f2(){}
//};
//
////����������ʲô��û��
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
//	//û�г�Ա����������󣬴�СΪ1�����1��Ϊ������ռλ����ʾ������ڵ�
//	A2 aa1;
//	A2 aa2;//��A2����ඨ����������
//	//�����������ַһ������һ��ʼ����Ķ���ͬ
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
//	//this ָ�벻�����βκ�ʵ����ʾ���ݣ����ǿ����ں����ڲ���ʾʹ��
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//	//��ʵ��������Գ�Ա�������д����������
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
//	Data d1, d2;//������������
//	d1.Init(2023, 4, 27);
//	d2.Init(2022, 2, 14);
//	d1.Print();
//	d2.Print();
//	//Data::_year;//��������д��û�й涨
//	// //������Ϊ_year������ͼֽ��û�п����ڴ��޷�ʹ��
//
//	//d1.year;//Ҳ���������Գ�Ա����֮����ʣ���Ϊ�з����޶�������
//	//d1.Print(&d1);//��ʵ��һ����ʽָ��this��d1��d2�ĵ�ַ��������
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
//	p->Print();//�����û�н���������ȥ����Ϊ��Ա���������ڶ�������
//	//����û�жԶ������--��Ա��������Ҳû�жԶ������
//	//��û�ж����������н�����
//	//�����ǺϷ���
//	////�ڶ��ֳ���
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
//		//��˴���������ᴦ���
//		//cout<<this->_a<<endl;
//		//�������Ϊthis�ǿ�ָ�룬Ȼ���ַ��ʿ�ָ�������ڷǷ�������
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();//����Ͳ�һ����
//}
//
//
typedef int DataType;
class stack//class���Զ���һ����
{
public://�����޶���

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

	stack(DataType*a,int n)//��������
	{
		cout << "stack(DataType*a,int n)" << endl;
		
	}
	//���캯��---�ڶ���ʵ����ʱ�Զ�����
	stack(int capacity=4)//ȱʡֵ
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

private://�����޶���
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
private://�����޶���
	DataType* _array;
	int _capacity;
	int _size;
};
//����ʹ������ʹ�ú���ʱ�������ǳ�ʼ�����������ٺ���������C++
//��������˼���Ĭ�Ϻ���--���캯��--��ʼ������
//
//int main()
//{
//	stack s;//����һ������
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
	*///���캯�����Թ�������;�����Ϸ���Ϊ������
	//���޲ε���ʱ�������壬�ǵ��õ�һ�����ǵڶ������ڶ���ȫ��ȱʡ������û�д���Ҳ����ʹ���������
	//���Բ�����ͬʱ����
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
	int _year=1;//����ֻ�����Ա������������û���ڴ��
	int _month=1;
	int _day=1;
	//��������-C++11֧�֣����ﲻ�ǳ�ʼ������Ϊ����ֻ������
	//���������Ĭ�ϵ�ȱʡֵ��������������Ĭ�Ϲ��캯���õ�
};

//���캯��--��ʼ������
//��û��д���캯��ʱ�����������Լ�����һ�����캯��
//������캯���ǻ���Զ������ͺ�����ʼ���������������ͱ�������ʼ��
//������������ñ���������ʱ�����ȱʡֵ����������û�и��������ͱ�����ʼ��
//Ҳ������ֺܴ�����⡣
int main()
{
	//���캯���ĵ��ø���ͨ����Ҳ��һ����
	Data d1;
		//Data d1()����������д����ͺ��������е��ͻ������������ʶ��
	/*Data d2(2023,1,1);*///��������ù��캯��������ʹ�õ�
	d1.Print();//�Զ����ù��캯��1-1-1;
	/*d2.Print();*///�Լ���ʼ��2023-1-1;
	Data d3(2000);
	d3.Print();
	
}