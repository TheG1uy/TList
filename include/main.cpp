#include "TList.h"
#include "THeadList.h"
#include <cstdlib>
#include <time.h>
#include "TPolinom.h"
int main(){
	srand(time(NULL));
	TList<int> a;
	THeadList<int> b;
	TMonom p,q,p1,q1,*mas;
	int size=3;
	mas=new TMonom[size];
	for(int i=0;i<size;i++)
		mas[i].randomManom();
	//cout<<p.toMonom("-122z^3")<<endl;
	p.coeff=3;
	q.coeff=2;
	p.x=0;
	p.y=1;
	p.z=0;
	q.x=0;
	q.y=0;
	q.z=0;
	p1.coeff=3;
	q1.coeff=2;
	p1.x=4;
	p1.y=1;
	p1.z=0;
	q1.x=0;
	q1.y=0;
	q1.z=0;
	TPolinom pol1,pol2;
	pol1.sortInput(p);
	//pol1.sortInput(q);
	//pol2.sortInput(p1);
	pol2.sortInput(q1);
	pol1=pol1+pol2;
	//cout<<pol1<<endl;
	cout<<pol1-pol2<<endl;
	//cout<<pol1-pol2<<endl;
   // cout<<pol1*pol2<<endl;


/*
	
	a.sortInput(5);
	a.sortInput(2);
	a.delCurr();

	a.sortInput(2);
	a.sortInput(1);
	a.sortInput(7);
	a.sortInput(3);
	a.sortInput(4);
	a.sortInput(8);
	a.sortInput(4);
	a.sortInput(6);
	a.sortInput(8);
	a.sortInput(8);
	a.sortInput(1);
	
	for(a.reset();!a.isEnd();a.goNext()){cout<<a.getElelm()<<endl;}
	cout<<endl;
	//a.sotrB();
	//for(a.reset();!a.isEnd();a.goNext()){cout<<a.getElelm()<<endl;}
	*/
	return 0;
}