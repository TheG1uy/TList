#pragma once
#include "THeadList.h"
struct TMonom{
	double coeff;
	int x,y,z;

	bool operator<(const TMonom &q){
    return ((x*100+y*10+z)<(q.x*100+q.y*10+q.z));
	}
	bool operator>(const TMonom &q){
    return ((x*100+y*10+z)>(q.x*100+q.y*10+q.z));
	}
	bool operator!=(const TMonom &q){
    if ((x*100+y*10+z)==(q.x*100+q.y*10+q.z))
		return (coeff!=q.coeff);
	else return true;
	}
	bool EqualDegrees(const TMonom &q){
	return ((x*100+y*10+z)==(q.x*100+q.y*10+q.z));
	}
	bool operator==(const TMonom &q){
    if ((x*100+y*10+z)==(q.x*100+q.y*10+q.z))
		return (coeff==q.coeff);
	else return false;
	}
	TMonom& operator=(const TMonom &q){
		coeff=q.coeff;
		x=q.x;
		y=q.y;
		z=q.z;
		return *this;
	}
};
ostream& operator<<(ostream& os, const TMonom& m){
	os<<m.coeff<<"x^"<<m.x<<"y^"<<m.y<<"z^"<<m.z;
	return os;
	}
class TPolinom: public THeadList<TMonom>{
public:
	TPolinom():THeadList(){
		pHead->val.coeff=0;
		pHead->val.x=-1;
	}
	TPolinom(const TMonom &m):THeadList(){
        TLink<TMonom> *tmp=new TLink<TMonom>;
		tmp->pNext=pStop;
		tmp->val=m;	
		pHead->pNext=tmp;
		pFirst=pLast=pCurr=tmp;
	}
	void sortInput(const TMonom &a){
		for(reset();!isEnd();goNext()){
			if (pCurr->val.EqualDegrees(a)){
				pCurr->val.coeff+=a.coeff;
				if (!pCurr->val.coeff) delCurr();
				return;
			}
			else  if(pCurr->val<a){
				addCurr(a);
				return;
			}
            addLast(a);
		}
	}
	TPolinom(const TMonom *mas,int size){
		for(int i=0;i<size;i++)
		  	sortInput(mas[i]);
	}
	TPolinom operator+(const TPolinom &p){
		
	}
	TPolinom operator-(const TPolinom &p){
		
	}
	TPolinom operator*(const TPolinom &p){
		
	}
	friend ostream& operator<<(ostream& os,TPolinom &p){
	  for(p.reset();!p.isEnd();p.goNext()){
		if (!p.pos) os<<p.pCurr->val;
		else if (p.pCurr->val.coeff>0) os<<"+ "<<p.pCurr->val;
		     else os<<p.pCurr->val;
	  }
      return os;
} 
};
