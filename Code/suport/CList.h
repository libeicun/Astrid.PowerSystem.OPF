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
	CListNode<T> *head;      //��ʼ����ָ������ͷ
	CListNode<T> *iterator;  //��ʼ����ָ��head
	void insertSorted(T data,unsigned int mode);


public: 

typedef CListNode<T>* Iterator;

CList<T>(T data);
//��ʼ��������data��ֵ����ͷ�ڵ�
CList<T>();
 CList<T>( CList<T>& thelist);
CList<T>& operator=( CList<T> thelist);
//���ɿ�����
virtual ~CList<T>();
void	ResetHead2NULL();
 CListNode<T>* begin();
//ǰ�᣺����������һ���ڵ�
//�����Ϊ�������෵��ָ������ͷ����ָ��

 CListNode<T>* end();
//ǰ�᣺����������һ���ڵ�
//Ϊ��������������β
//��ֵ��ΪNULL
//������ָ��end()ʱ˵����������Խ���������һ���ڵ�


CListNode<T> *getIterator();
//ǰ�᣺����������һ���ڵ�
//���򷵻ؿ�ָ��
//���ص�������ǰָ��Ľڵ��ָ��ֵ

 CListNode<T>* getHead();
//ǰ�᣺����������һ���ڵ�
//����ָ������ͷ�ڵ��ָ��ֵ

void iterateMoveForward(int move);
//ǰ�᣺��������ָ��ĳ��ȷ���Ľڵ�
//������ǰ��ĵ��á����δ�ж���
//�������������ָ�����ɵ�ǰ�ڵ�֮���move���ڵ�
//��move����ʱ�����������ǰ�Ƶ�ָ�����һ���ڵ�

/*CListNode *iterateMoveForward(int move);
//ǰ�᣺��������ָ��ĳ��ȷ���Ľڵ�
//������ǰ��ĵ��á����δ�ж���
//�������������ָ�����ɵ�ǰ�ڵ�֮���move���ڵ�
//��move����ʱ�����������ǰ�Ƶ�ָ�����һ���ڵ�
////�����ص�����ָ��ֵ*/

/*CListNode *setIterator(int location);
//ǰ�᣺����������һ���ڵ�
//�����������ָ���location���ڵ�
//��location���������ȣ��������ָ���������һ���ڵ�
//�����ص�����ָ��ֵ*/
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
//ǰ�᣺�����ѳ�ʼ��
//��afterMe��ָ�ڵ������½ڵ㣬����data ����ʼ��������
//

void insertBefore(CListNode<T> *beforeMe,T data);
//ǰ�᣺�����ѳ�ʼ��
//��beforeMe��ָ�ڵ�ǰ�����½ڵ㣬����data ����ʼ��������
//

void insertReplace(T data,int location);
//ǰ�᣺����������location���ڵ�
//��location���󣨳��������ȣ���С��1 �򲻽����κβ���
//������� data ֵȡ���� location ���ڵ��е�����
//��������ǰ���򲻽����κβ���

//ostream& << (CList &theList const);
bool isThere(T data,int from=1);
//ǰ�᣺����������һ���ڵ�
//�������дӵ�from���ڵ㿪ʼ֪����β�����������ݵ���data�Ľڵ㣬һ���ҵ��򷵻�true
//���򷵻�false

bool isThere(T data,int from,int to);
//ǰ�᣺����������һ���ڵ�
//�������дӵ�from���ڵ�ֱ����to���ڵ�����������ݵ���data�Ľڵ㣬һ���ҵ��򷵻�true
//���򷵻�false


int locationOf(T data);
//ǰ�᣺����������һ���ڵ�
//����data���ֵĽڵ�λ�ã�������һ��ֵ˵���ǵڼ����ڵ�
//ֻ�ܷ���data��һ�γ��ֵ�����
//���Ҳ����򷵻�0

void print();
//ǰ�᣺����������һ���ڵ�
//������ӱ�ͷ��ʼ�����������нڵ�������������Ļ
//
void resetIterator();
//ǰ�᣺����������һ���ڵ�
//�����������ָ������ͷ��

void setIterator(int location);
//ǰ�᣺����������һ���ڵ�
//�����������ָ���location���ڵ�
//��location���������ȣ��������ָ���������һ���ڵ�

int size();
//����������
//������Ϊ�գ��򷵻�0

void removeOne(T data);
//ǰ�᣺����������һ���ڵ�
//������������е�һ���������ݵ���data�Ľڵ�ɾ��
//���Ҳ���Ŀ��ڵ㣬�򲻽����κβ���

void removeAll(T data);
//ǰ�᣺����������һ���ڵ�
//������������������������ݵ���data�Ľڵ�ɾ��
//���Ҳ���Ŀ��ڵ㣬�򲻽����κβ���

void refresh();
//ǰ�᣺����������һ���ڵ�
//����������������нڵ�ɾ��
//���ɿ�����



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
 DOWN(1),UP(2) //�п��ܸı����βΣ���������
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
CListNode<T>* CList<T>::getIterator()        //���ص�������ַ
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
		}//iterָ��from�ڵ�

		if (iter->getData()==data) return true;
		i=from;
		while (iter!=NULL) 
		{
			if (i>to) return false;//ָ��Խ��to�ڵ�
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
void CList<T>::resetIterator()            //���õ�������ʹָ֮���ͷ
	{
		if (head==NULL) return;
		iterator=head;
	}

template <class T>
void CList<T>::setIterator(int location)  //ʹ������ָ���location���ڵ�
	{
		if (head==NULL) return;
		iterator=head;
		iterateMoveForward(location-1);

	}


template <class T>
void CList<T>::iterateMoveForward(int move)//������ָ��Ľڵ�ǰ��move��λ��
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
		//����ɾ���ڵ�Ϊͷ���ʱ
		{
			if(iter_pre->getData()==data)
			{
				head=head->getNext();
				delete iter_pre;
				return ;
			}

		}
		//����ɾ���ڵ�Ϊͷ���ʱ
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
