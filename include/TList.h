#pragma once
#include <iostream>
using namespace std;
template <class T>
struct TLink {
	T val;
	TLink *pNext;
};
template <class T> 
class TList{
	TLink<T> *pFirst, *pLast, *pPrev, *pCurr, *pStop;
	int size, pos;
public:
	TList(){
		pFirst=pLast=pCurr=pStop=NULL;
		size=0;
		pos=-1;
	}
	void sortInput(T a){
		if (pFirst==pStop || a<pFirst->val ) { addFirst(a); pCurr=pPrev=pFirst; return ;}
		if (a>=pLast->val){ addLast(a); for(reset();!(pCurr->pNext==pStop);goNext()){} return ;}
		for(reset();!isEnd();goNext()){
			if (pCurr->val>a) {addCurr(a); return; }
		}

		

	}
	void sotrB(){
		
		T tmp;
		for (int i=0;i<size-1;i++){
			reset();
			for(int j=0;j<size-1-i;j++){
				goNext();
				if (pPrev->val>pCurr->val){
					tmp=pCurr->val;
					pCurr->val=pPrev->val;
					pPrev->val=tmp;
				}
			}
		}
	}
	void addFirst (T a){
		TLink<T> *tmp=new TLink <T>;
		tmp->val=a;
		if (size==0)
		{
			pFirst=pLast=pCurr=tmp;
			tmp->pNext=pStop;
		}
		else
		{
			tmp->pNext=pFirst;
			pFirst=tmp;
            if(size==1) pPrev=pFirst;
		}
		
		pos++;
		size++;
	}
	void addCurr (T a){
		if (pFirst==pCurr) addFirst(a);
		else 
		{

			TLink<T> *tmp=new TLink<T>;
			tmp->val=a;
			tmp->pNext=pCurr;
			pPrev->pNext=tmp;
			pCurr=tmp;
			size++;
		}
		
	}
	void addLast (T a){
		if (pFirst==pStop) addFirst(a);
		else{
             TLink<T> *tmp=new TLink<T>;
			 tmp->val=a;
			 pLast->pNext=tmp;
			 tmp->pNext=pStop;
             pLast=tmp;
			 size++;						
		}
		
	}
	T getElelm(){ return pCurr->val; }
	void delFirst (){
		if (size==1)
		{
			delete pFirst;
			pFirst=pLast=pPrev=pCurr=pStop;
		}
		else
		{
			TLink<T> *tmp=pFirst->pNext;
			delete pFirst;
			pFirst=tmp;
		}
		size--;
		pos--;
	}
	void delCurr (){
		if (pCurr==pFirst)
		
			delFirst();
		
		else 
		{
			pCurr=pCurr->pNext;
			delete pPrev->pNext;
			pPrev->pNext=pCurr;
			size--;

		}
	}
	void delLast (){
	  if (pLast==pFirst) delFirst();
	  else{
		  for(reset();!(pCurr->pNext==pStop);goNext()){}
		  delete pLast;
		  pLast=pCurr=pPrev;
	      reset();
		  size--;
		  pos--;
	  }
	}
	void reset(){
		pPrev=pCurr=pFirst;
		pos=0;
	}
	void goNext (){
		if (pFirst->pNext==pStop && (size-1)) pPrev=pFirst;
		else{
		pPrev=pCurr;
		pCurr=pCurr->pNext;
		pos++;
		}
	}
	bool isEnd (){
		return pCurr==pStop;
	}

	bool isEmpty(){
		return pFirst==pStop;
	}
	T operator[](int m){
		for(reset();!isEnd();goNext()){
			if (pos==m-1)
			return pCurr->val;
		}
	}	
};
