#include "Dllist.h"

Dllist::Dllist()
{
}

Dllist::~Dllist()
{
}

int DataElement::count_ = 0; // 静态变量必须在CPP文件，类外面进行初始化。

void Dllist::runTestProc()
{
	ACE_TRACE(ACE_TEXT("Dllist::run"));
	MyList list1;
	
	for (int i = 0; i < 100; i++)//构造100个实例，链表操作->从尾部插入
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
	ACE_DLList_Iterator<DataElement> iter(list);//正向迭代器用于遍历整个链表

	while (! iter.done())
	{
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%d:"), iter.next()->getData()));
		iter++;
	}
	ACE_DEBUG((LM_DEBUG, ACE_TEXT("\n")));
	ACE_DEBUG((LM_DEBUG, ACE_TEXT("Reverse iteration\n")));

	ACE_DLList_Reverse_Iterator<DataElement> riter(list);//反向迭代器用于遍历整个链表
	while (! riter.done())
	{
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%d:"), riter.next()->getData()));
		riter++;
	}
	ACE_DEBUG((LM_DEBUG, ACE_TEXT("\n")));
}

void Dllist::destroyList(MyList &list)//这里要怎么销毁 new出来的实例？
{
	for (int i=0; i<100; i++)
	{
		DataElement *mDataElement = list.delete_head();
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%d:"), mDataElement->getData()));
		delete mDataElement;
	}
	
}
