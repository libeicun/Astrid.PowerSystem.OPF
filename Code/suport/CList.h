#ifndef CLISTNODE_CLIST
#define CLISTNODE_CLIST
#include <stdio.h>
template <class T>
class CListNode
{
	
private:
	T data;
	CListNode<T> *next;
public:
	CListNode<T>(T thedata,CListNode<T> *ptr_next);
	CListNode<T>();
	bool atTheEnd();
	bool atLast();
	 T& getData();
	void setData(T theData);
    CListNode<T>*getNext();
	void setNext(CListNode<T> *ptr_next);
};


template <class T>
class CList 
{
private:
	const unsigned int DOWN,UP;
	CListNode<T> *head;      //初始化后指向链表头
	CListNode<T> *iterator;  //初始化后指向head
	void insertSorted(T data,unsigned int mode);


public: 

typedef CListNode<T>* Iterator;

CList<T>(T data);
//初始化链表并以data的值生成头节点
CList<T>();
 CList<T>( CList<T>& thelist);
CList<T>& operator=( CList<T> thelist);
//生成空链表
virtual ~CList<T>();
void	ResetHead2NULL();
 CListNode<T>* begin();
//前提：链表至少有一个节点
//结果：为迭代器类返回指向链表头结点的指针

 CListNode<T>* end();
//前提：链表至少有一个节点
//为迭代器返回链表尾
//其值总为NULL
//迭代器指向end()时说明迭代器已越过链表最后一个节点


CListNode<T> *getIterator();
//前提：链表至少有一个节点
//否则返回空指针
//返回迭代器当前指向的节点的指针值

 CListNode<T>* getHead();
//前提：链表至少有一个节点
//返回指向链表头节点的指针值

void iterateMoveForward(int move);
//前提：迭代器已指向某个确定的节点
//不满足前提的调用　结果未有定义
//结果：迭代器的指涉物变成当前节点之后第move个节点
//当move过大时，迭代器最多前移到指向最后一个节点

/*CListNode *iterateMoveForward(int move);
//前提：迭代器已指向某个确定的节点
//不满足前提的调用　结果未有定义
//结果：迭代器的指涉物变成当前节点之后第move个节点
//当move过大时，迭代器最多前移到指向最后一个节点
////并返回迭代器指针值*/

/*CListNode *setIterator(int location);
//前提：链表至少有一个节点
//结果：迭代器指向第location个节点
//若location超出链表长度，则迭代器指向链表最后一个节点
//并返回迭代器指针值*/
void insertToHead(T data);
//
//
//

void insertToEnd(T data);
//
//
//

void insertSorted_up(T data) ;
//
//
//

void insertSorted_down(T data);
//
//
//

void insertAfter(CListNode<T> *afterMe,T data);
//前提：链表已初始化
//在afterMe所指节点后插入新节点，并用data 来初始化其数据
//

void insertBefore(CListNode<T> *beforeMe,T data);
//前提：链表已初始化
//在beforeMe所指节点前插入新节点，并用data 来初始化其数据
//

void insertReplace(T data,int location);
//前提：链表至少有location个节点
//若location过大（超出链表长度）或小于1 则不进行任何操作
//结果：以 data 值取代第 location 个节点中的数据
//若不满足前提则不进行任何操作

//ostream& << (CList &theList const);
bool isThere(T data,int from=1);
//前提：链表至少有一个节点
//在链表中从第from个节点开始知道表尾查找所含数据等于data的节点，一旦找到则返回true
//否则返回false

bool isThere(T data,int from,int to);
//前提：链表至少有一个节点
//在链表中从第from个节点直到第to个节点查找所含数据等于data的节点，一旦找到则返回true
//否则返回false


int locationOf(T data);
//前提：链表至少有一个节点
//搜索data出现的节点位置，并返回一个值说明是第几个节点
//只能返回data第一次出现的索引
//若找不到则返回0

void print();
//前提：链表至少有一个节点
//结果：从表头开始，将链表所有节点的数据输出到屏幕
//
void resetIterator();
//前提：链表至少有一个节点
//结果：迭代器指向链表头部

void setIterator(int location);
//前提：链表至少有一个节点
//结果：迭代器指向第location个节点
//若location超出链表长度，则迭代器指向链表最后一个节点

int size();
//返回链表长度
//若链表为空，则返回0

void removeOne(T data);
//前提：链表至少有一个节点
//结果：将链表中第一个所含数据等于data的节点删除
//若找不到目标节点，则不进行任何操作

void removeAll(T data);
//前提：链表至少有一个节点
//结果：将链表中所有所含数据等于data的节点删除
//若找不到目标节点，则不进行任何操作

void refresh();
//前提：链表至少有一个节点
//结果：将链表中所有节点删除
//生成空链表



//friend ostream& operator <<(ostream& outer, CList<T> mylist );
//
//
//
//const T& operator []( int location) const;
// 
//
//
T& operator []( int location);
//
//
//

};


template <class T>
CListNode<T>::CListNode()
{
	next=NULL;
}

template <class T>
CListNode<T>::CListNode(T thedata,CListNode<T> *ptr_next)
	{
		data=thedata;
		next=ptr_next;
	} 

template <class T>
bool CListNode<T>::atTheEnd()
	{
		return (this==NULL);
	}

template <class T>
bool CListNode<T>::atLast()
	{
		return (next==NULL);
	}

template <class T>
 T& CListNode<T>::getData()
	{
		return data;
	}

template <class T>
void CListNode<T>::setData(T theData)
	{
		data=theData;
	}


template <class T>
 CListNode<T>* CListNode<T>::getNext()
	{
		return next;
	}

template <class T>
void CListNode<T>::setNext(CListNode<T> *ptr_next)
	{
		next=ptr_next;
	}

//****************************************************************************

template <class T>
CList<T>::~CList()
	{
		if (head==NULL) return;
		CListNode<T> *p;
		do{
			p=head;
			head=head->getNext();
			delete p;
		}while(head!=NULL);

	}

template <class T>
CList<T>::CList():

		DOWN(1),UP(2)
	{
		head=NULL;
		iterator=NULL;

	}

template <class T>
CList<T>& CList<T>::operator=( CList<T> thelist)
	{
		CList<T> newlist;
		thelist.resetIterator();
		int i=1;
		while(thelist.getIterator()!=NULL)
		{
			newlist.insertToEnd(thelist[i]);
			i++;
			thelist.setIterator(i);
		}
		newlist.resetIterator();

		return newlist;

	}
	

 template <class T> 
 CList<T>::CList( CList<T>& thelist):
 DOWN(1),UP(2) //有可能改变了形参！！！！！
	{
		head=NULL;
		iterator=head;
		CListNode<T>* p=thelist.getHead();
		//thelist.resetIterator();//
		int i=1,size_ofthelist;
		size_ofthelist=thelist.size();
		while(/*thelist.getIterator()*/p!=NULL)
		{
			if(i>size_ofthelist) break;
			insertToEnd(thelist[i]);
			i++;
			//setIterator(i);//
			p=p->getNext();
		}
		//resetIterator();

	}

template <class T>
CList<T>::CList(T data):
		DOWN(1),UP(2)
	{

		head=new CListNode<T>(data,NULL);
		iterator=head;

	}

template <class T>
CListNode<T>* CList<T>::getIterator()        //返回迭代器地址
	{
		if (head==NULL) return NULL;
		return iterator;
	}

template <class T>
void CList<T>::insertSorted(T data,unsigned int mode)
	{
		if (head==NULL) 
		{
			head=new CListNode<T>(data,NULL);
			return;
		}
		CListNode<T> *iter=head;
		if (mode==DOWN)
			while (!(data>iter->getData()))//
			{
				if (iter->getNext ()==NULL)
				{
					insertAfter(iter,data);
					return;
				}
				iter=iter->getNext();
			}
        if (mode==UP)
			while (!(data<iter->getData()))//
			{
				if (iter->getNext ()==NULL)
				{
					insertAfter(iter,data);
					return;
				}
				iter=iter->getNext();
			}

		insertBefore(iter,data); 

	}

template <class T>
void CList<T>::insertAfter(CListNode<T> *afterMe,T data)
	{	
		if (afterMe->atLast ()){ insertToEnd(data);return;}
		afterMe->setNext (new CListNode<T>(data,afterMe->getNext ()));


	}

template <class T>
void CList<T>::insertBefore(CListNode<T> *beforeMe,T data)
	{
		if (head==NULL) {head=new CListNode<T>(data,NULL);return;}
		if (head==beforeMe) {insertToHead(data);return;}
		CListNode<T> *iter=head;
		while(iter->getNext ()!=beforeMe)
		{
			iter=iter->getNext();
		}
		iter->setNext (new CListNode<T>(data,beforeMe));

	}

template <class T>
void CList<T>::insertToHead(T data)
	{

		head=new CListNode<T>(data,head);
	}

template <class T>
void CList<T>::insertToEnd(T data)
	{
		if (head==NULL) {head=new CListNode<T>(data,NULL);return;}
		CListNode<T> *iter=head;
		while(iter->getNext ()!=NULL)
		{
			iter=iter->getNext ();
		}
		iter->setNext (new CListNode<T>(data,NULL));
	}

template <class T>
void CList<T>::insertSorted_up(T data)                //tested
	{
		insertSorted(data,UP) ;
	}

template <class T>
void CList<T>::insertSorted_down(T data)
	{
		insertSorted(data,DOWN) ;
	}

template <class T>
void CList<T>::insertReplace(T data,int location)
	{
		if (head==NULL  ||  location<1) return;
		CListNode<T>* iter=head;
		for(int i=1;i<=location-1;i++)
		{
			if (iter->getNext()==NULL) return;
			iter=iter->getNext();
		}
		iter->setData(data);
	}

template <class T>
void CList<T>::ResetHead2NULL()
{
	head=NULL;
	iterator=NULL;
}
template <class T>
bool CList<T>::isThere(T data,int from,int to)
	{
		if(head==NULL) return false;
		if( from>to) return false;
		if(to>size() ) to=size()/*return isThere(data,from)*/;

		CListNode<T>* iter=head;
		for (int i=1;i<=from-1;i++)
		{
			if (iter->getNext()==NULL) return false;
			iter=iter->getNext();
		}//iter指向from节点

		if (iter->getData()==data) return true;
		i=from;
		while (iter!=NULL) 
		{
			if (i>to) return false;//指针越过to节点
			else
			{
				if(iter->getData()==data)return true;
				else
				{
					iter=iter->getNext();
					i++;
				}
			}

		
		}

		return false;
	}

template <class T> 
bool CList<T>::isThere(T data,int from)
	{
		if(head==NULL) return false;
		CListNode<T>* iter=head;
		for (int i=1;i<=from-1;i++)
		{
			if (iter->getNext()==NULL) return false;
			iter=iter->getNext();
		}
		if (iter->getData()==data) return true;
		while((iter->getData()!=data) && (iter->getNext()!=NULL))
		{
			iter=iter->getNext();
			if(iter->getData()==data)return true;
		}

		return false;

	}

template <class T>
void CList<T>::resetIterator()            //重置迭代器，使之指向表头
	{
		if (head==NULL) return;
		iterator=head;
	}

template <class T>
void CList<T>::setIterator(int location)  //使迭代器指向第location个节点
	{
		if (head==NULL) return;
		iterator=head;
		iterateMoveForward(location-1);

	}


template <class T>
void CList<T>::iterateMoveForward(int move)//迭代器指向的节点前移move个位置
	{
		if (head==NULL) return;
		for(int i=1;i<=move;i++)
		{
			if (iterator->getNext()==NULL) return;
			iterator=iterator->getNext();
		}
		
	}


template <class T>
 CListNode<T>* CList<T>::getHead()
	{
		return head;
	}




template <class T>
void CList<T>::print()
	{	
		CListNode<T> *p=head;
		cout<<"Now outputing the datas in the list...\n\n";
		for (;!(p->atTheEnd ());p=p->getNext () )
		{
			cout <<p->getData()<<" ";

		}
		cout<<"\n\nThat's all.\n\n";
	}


template <class T>
void CList<T>::refresh()
	{
		this->~CList();
	}

template <class T>
 CListNode<T>* CList<T>::begin ()
	{
		 return head;
	}

template <class T>
 CListNode<T>* CList<T>::end ()
	{
		return NULL;
	}

template <class T>
void CList<T>::removeOne(T data)
	{
		if (head==NULL) return;
		CListNode<T>* iter_pre=head;
		CListNode<T>* iter_nex=head->getNext();
		//当需删除节点为头结点时
		{
			if(iter_pre->getData()==data)
			{
				head=head->getNext();
				delete iter_pre;
				return ;
			}

		}
		//当需删除节点为头结点时
		while (iter_nex->getData()!=data)
		{
			if (iter_nex->getNext()==NULL) return ;
			iter_pre=iter_pre->getNext();
			iter_nex=iter_pre->getNext();
		}
		iter_pre->setNext(iter_nex->getNext());
		delete iter_nex;

	}

template <class T>
void CList<T>::removeAll(T data)
	{
		while(isThere(data))
		{
			removeOne(data);
		}

	}


template <class T> 
int CList<T>::size()
	{
		if (head==NULL ) return 0;
		CListNode<T>* iter=head;
		int s=1;
		while(iter->getNext()!=NULL)
		{
			iter=iter->getNext();
			s++;
		}
		return s;
	}


/*template <class T>
const T& CList<T>::operator []( int location) const
	{
		if (head==NULL) return NULL;
		if (location<1 ) return NULL;
		//if (location>size()) return NULL;
		CListNode<T>* iter=head;
		for(int i=1;i<=location-1;i++)
		{
			//if (iterator->getNext()==NULL) return NULL;
			iter=iter->getNext();
		}

		T val=iter->getData();		return val;

	}*/


template <class T>
T& CList<T>::operator []( int location)
	{
		//if (head==NULL) return NULL;
		//if (location<1 ) return NULL;
		//if (location>size()) return NULL;
		CListNode<T>* iter=head; 
		for(int i=1;i<=location-1;i++)
		{
				//if (iterator->getNext()==NULL) return NULL;
			iter=iter->getNext();
		}

		T &val=iter->getData();
		return val;

	}
#endif CLISTNODE_CLIST
