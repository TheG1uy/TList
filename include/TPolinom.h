#pragma once
#include "THeadList.h"
#include "cstdlib"
#include "time.h"
#include  <string>
struct TMonom{
	double coeff;
	int x,y,z;

	TMonom toMonom(string st){
		string tmp="";		
		int i=0;
		x=0;
		y=0;
		z=0;
		coeff=1;
		while ((st[i]>='0' && st[i]<='9' || st[i]=='-' ) && i<st.size()){
			tmp+=st[i];
			i++;
		}
		if (tmp.size())
		coeff=(int)atof(tmp.c_str());
		tmp="";
		if (st.find('x')!=-1){
			i=st.find('x')+1;
			while ((st[i]>='0' && st[i]<='9' || st[i]=='^' || st[i]=='-') && i<st.size()){
			i++;
			tmp+=st[i];			
		}
		  if (!tmp.size()) x=1;
          else x=(int)atof(tmp.c_str()); tmp="";
		}
		if (st.find('y')!=-1){
			i=st.find('y')+1;
			while ((st[i]>='0' && st[i]<='9' || st[i]=='^' || st[i]=='-') && i<st.size()){
			i++;
			tmp+=st[i];
			
		}
          if (!tmp.size()) y=1;
          else y=(int)atof(tmp.c_str()); tmp="";
		}
		if (st.find('z')!=-1){
			i=st.find('z')+1;
			while ((st[i]>='0' && st[i]<='9' || st[i]=='^' || st[i]<='-') && i<st.size()){
			i++;
			tmp+=st[i];			
		}
          if (!tmp.size()) z=1;
          else z=(int)atof(tmp.c_str()); tmp="";
		}


		return *this;
	}
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
	TMonom operator*(const TMonom &q){
		TMonom tmp;
		tmp.x=q.x+x;
		tmp.y=q.y+y;
		tmp.z=q.z+z;
		tmp.coeff=q.coeff*coeff;
		return tmp;
	}
	TMonom& operator=(const TMonom &q){
		coeff=q.coeff;
		x=q.x;
		y=q.y;
		z=q.z;
		return *this;
	}
	void randomManom(){
		coeff=rand() % 20+1;
		x=rand() % 10+1;
		y=rand() % 10+1;
		z=rand() % 10+1;
	}
};
ostream& operator<<(ostream& os, const TMonom& m){
	if (!m.coeff) {os<<"0"; return os;}
	os<<m.coeff;
	if (m.x) if (m.x>1) os<<"x^"<<m.x;
	         else  os<<"x";
	if (m.y) if (m.y>1) os<<"y^"<<m.y;
	         else  os<<"y";
	if (m.z) if (m.z>1) os<<"z^"<<m.z;
	         else  os<<"z";
	return os;
	}
class TPolinom: public THeadList<TMonom>{
public:
	TPolinom():THeadList(){
		pHead->val.coeff=0;
		pHead->val.x=-1;
	}
	TPolinom(TPolinom &p):THeadList(){
		pHead->val.coeff=0;
		pHead->val.x=-1;
		if (p.size){
        TLink<TMonom> *tmp1=new TLink<TMonom>;
		pHead->pNext=tmp1;
		pFirst=pCurr=tmp1;
		for(p.reset();!p.isEnd();p.goNext()){
			TLink<TMonom> *tmp2=new TLink<TMonom>;
			pCurr->val=p.pCurr->val;
			if (p.pos==p.size-1) {pLast=pCurr; pLast->pNext=pStop; size=p.size; break;}
			pCurr->pNext=tmp2;
			goNext();
		    
		}
		}

	}
	TPolinom(const TMonom &m):THeadList(){
        TLink<TMonom> *tmp=new TLink<TMonom>;
		tmp->pNext=pStop;
		tmp->val=m;	
		pHead->pNext=tmp;
		pFirst=pLast=pCurr=tmp;
	}
	void sortInput(TMonom a){
		if (!size) { addFirst(a); return;}
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
		}
		addLast(a);
		
	}
	TPolinom(TMonom *mas,int size):THeadList(){
		pHead->val.coeff=0;
		pHead->val.x=-1;
		for(int i=0;i<size;i++)
		  	sortInput(mas[i]);
	}
	TPolinom operator+(TPolinom &p){
		TPolinom tmp(*this);
		p.reset();
		for(reset();!isEnd();goNext()){
			for(p.pCurr;(p.pCurr->val>pCurr->val && !p.isEnd());p.goNext()){
				tmp.sortInput(p.pCurr->val);
			}
		}
		if (isEnd() && !p.isEnd()) 
			for(p.pCurr;!p.isEnd();p.goNext())
				tmp.sortInput(p.pCurr->val);
		return tmp;
	}
	TPolinom operator-( TPolinom &p){
		TPolinom tmp(*this),tmp2(p);
		tmp2*=-1;
		tmp2.reset();
		for(reset();!isEnd();goNext()){
			for(tmp2.pCurr;(tmp2.pCurr->val>pCurr->val && !tmp2.isEnd());tmp2.goNext()){
				tmp.sortInput(tmp2.pCurr->val);
			}
		}
		if (isEnd() && !tmp2.isEnd()) 
			for(tmp2.pCurr;!tmp2.isEnd();tmp2.goNext())
				tmp.sortInput(tmp2.pCurr->val);
		return tmp;
		
	}
	TPolinom operator*(TPolinom &p){
        TPolinom tmp;
		for(p.reset();!p.isEnd();p.goNext())
			for(reset();!isEnd();goNext()){
				tmp.sortInput(pCurr->val*p.pCurr->val);	
			}
		return tmp;		
	}
	void operator*=(double a){
       for(reset();!isEnd();goNext())
		   pCurr->val.coeff*=a;	   
	}
	TPolinom operator*(double a){
        TPolinom tmp(*this);
		for(reset();!isEnd();goNext())
			tmp.pCurr->val.coeff*=a;	
		return tmp;		 
	}
	double getCoeffM(){
		return pCurr->val.coeff;
	}
	int getXM(){
		return pCurr->val.x;
	}
	int getYM(){
		return pCurr->val.y;
	}
	int getZM(){
		return pCurr->val.z;
	}
	friend ostream& operator<<(ostream& os,TPolinom &p){
		if (p.size==0) {os<<"0"; return os;}
	  for(p.reset();!p.isEnd();p.goNext()){
		if (!p.pos) os<<p.pCurr->val;
		else if (p.pCurr->val.coeff>0) os<<"+ "<<p.pCurr->val;
		     else os<<p.pCurr->val;
	  }
      return os;
} 
};
