#include "TList.h"
#include <cstdlib>
#include <time.h>
int main(){
	TList<int> a;

	
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
	return 0;
}