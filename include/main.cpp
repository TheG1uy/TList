#include "TList.h"
#include "THeadList.h"
#include <cstdlib>
#include <time.h>
#include "TPolinom.h"
int main(){
	srand(time(NULL));
	TList<int> a;
	THeadList<int> b;
	TMonom p,q,*mas;
	int size=3;
	mas=new TMonom[size];
	for(int i=0;i<size;i++)
		mas[i].randomManom();
	
	p.coeff=10;
	q.coeff=2;
	p.x=12;
	p.y=8;
	p.z=7;
	q.x=2;
	q.y=8;
	q.z=7;
	TPolinom pol1(mas,size),pol2;
	pol2.sortInput(q);
	cout<<pol1<<endl;
    cout<<pol1*pol2<<endl;


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