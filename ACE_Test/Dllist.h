#pragma once

#ifndef WIN32
#define WIN32
#endif

#include "ace/Containers.h"
#include "ace/Log_Msg.h"
#include "Test.h"


/*
	这个类具有两个成员变量，一个是静态成员变量，用于记录实例个数
*/
class DataElement
{
public:
	DataElement()//不带参数的构造函数
	{
		count_++;
	}
	DataElement(int data) : data_(data)//带参数的构造函数
	{
		count_++;
	}
	DataElement(const DataElement& e)//根据一个实例复制构造
	{
		data_ = e.getData();
		count_++;
	}

	~DataElement()
	{
		count_--;
	}

	int getData(void) const
	{
		return data_;
	}

	void setData(int val)
	{
		data_ = val;
	}

	static int numOfActiveObjects(void)//静态方法，只能使用静态变量，用于记录实例的数量
	{
		return count_;
	}
	
private:
	int data_;
	static int count_;//静态变量必须在CPP文件，类外面进行初始化。
};


typedef ACE_DLList<DataElement> MyList;


class Dllist :
	public Test
{
public:
	Dllist();
	~Dllist();
	virtual void runTestProc();
	void displayList(MyList &list);
	void destroyList(MyList &list);
};

