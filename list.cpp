#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	list l;
	l.add(1);
	l.add(2);
	l.add(33);
	l.remove(0);
	l.set(0, 32);
	cout << l.pos(33) << endl;
	return 0;
}