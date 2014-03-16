#include "Base.h"
#include "Point.h"

int main()
{
	Point p, q;
	p.x = 1; p.y = 2; p.z = 3;
	q.x = -1; q.y = -2; q.z = -3;

	/*q.Save("debug.txt");
	q.x = q.y = p.x = p.y = 0;
	p.Load("debug.txt");	
	q.Load("debug.txt");
	*/
	Line l;
	l.p1.x = 1;
	l.p1.y = 3;
	l.p2.x = 5;
	l.p2.y = 7;
	l.name = "Sasha";
	//l.Save("debug.txt");
	l.p1.x = l.p1.y = l.p2.x = l.p2.y = 0;	
	l.name = "";
	l.Load("debug.txt");
}