#include "Dllist.h"

Dllist::Dllist()
{
}

Dllist::~Dllist()
{
}

int DataElement::count_ = 0; // ��̬����������CPP�ļ�����������г�ʼ����

void Dllist::runTestProc()
{
	ACE_TRACE(ACE_TEXT("Dllist::run"));
	MyList list1;
	
	for (int i = 0; i < 100; i++)//����100��ʵ�����������->��β������
	{
		DataElement *element = new DataElement(i);
		list1.insert_tail(element);
	}
	this->displayList(list1);
	MyList list2;
	list2 = list1;
	this->displayList(list2);

	

	ACE_DEBUG((LM_DEBUG, ACE_TEXT("#of live objects: %d\n"), DataElement::numOfActiveObjects()));

	this->destroyList(list2);
	this->destroyList(list1);

}


void Dllist::displayList(MyList &list)
{
	ACE_TRACE(ACE_TEXT("Dllist::displayList"));

	ACE_DEBUG((LM_DEBUG, ACE_TEXT("Forward iteration\n")));
	ACE_DLList_Iterator<DataElement> iter(list);//������������ڱ�����������

	while (! iter.done())
	{
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%d:"), iter.next()->getData()));
		iter++;
	}
	ACE_DEBUG((LM_DEBUG, ACE_TEXT("\n")));
	ACE_DEBUG((LM_DEBUG, ACE_TEXT("Reverse iteration\n")));

	ACE_DLList_Reverse_Iterator<DataElement> riter(list);//������������ڱ�����������
	while (! riter.done())
	{
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%d:"), riter.next()->getData()));
		riter++;
	}
	ACE_DEBUG((LM_DEBUG, ACE_TEXT("\n")));
}

void Dllist::destroyList(MyList &list)//����Ҫ��ô���� new������ʵ����
{
	for (int i=0; i<100; i++)
	{
		DataElement *mDataElement = list.delete_head();
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%d:"), mDataElement->getData()));
		delete mDataElement;
	}
	
}
