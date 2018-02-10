#include "TList.h"
template <class T>
class THeadList:public TList<T>{
protected: TLink<T> *pHead;
public:
	THeadList():TList(){
		TLink<T> *tmp=new TLink<T>;
		pHead=tmp;
		tmp->val=-1;
		pStop=tmp;
		tmp->pNext=pStop;
		size=0;
	}
	~THeadList(){
		TList<T>::~TList();
		delete pHead;
		//pHead=pStop=NULL;
	}
		virtual void delFirst (){
		if (size==1)
		{
			delete pFirst;
			pFirst=pLast=pPrev=pCurr=NULL;
			pHead->pNext=pStop;
		}
		else
		{
			TLink<T> *tmp=pFirst->pNext;
			delete pFirst;
			pFirst=tmp;
			pHead->pNext=pFirst;
		}
		size--;
		pos--;
	}
	virtual void addFirst (T a){
		TLink<T> *tmp=new TLink<T>;
		tmp->val=a;
		if (pFirst==NULL) {
			tmp->pNext=pStop;
			pFirst=pLast=tmp; 
			pos=0;
		}
		else {
			tmp->pNext=pFirst;
			pFirst=tmp;
			pos++;
		}
		size++;
		pHead->pNext=pFirst;
	}
	


};