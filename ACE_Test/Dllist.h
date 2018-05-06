#pragma once

#ifndef WIN32
#define WIN32
#endif

#include "ace/Containers.h"
#include "ace/Log_Msg.h"
#include "Test.h"


/*
	��������������Ա������һ���Ǿ�̬��Ա���������ڼ�¼ʵ������
*/
class DataElement
{
public:
	DataElement()//���������Ĺ��캯��
	{
		count_++;
	}
	DataElement(int data) : data_(data)//�������Ĺ��캯��
	{
		count_++;
	}
	DataElement(const DataElement& e)//����һ��ʵ�����ƹ���
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

	static int numOfActiveObjects(void)//��̬������ֻ��ʹ�þ�̬���������ڼ�¼ʵ��������
	{
		return count_;
	}
	
private:
	int data_;
	static int count_;//��̬����������CPP�ļ�����������г�ʼ����
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

