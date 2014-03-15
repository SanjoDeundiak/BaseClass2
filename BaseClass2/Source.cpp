#include "Base.h"

int main()
{
	Point p;
	//p.x = 1; p.y = 2; p.z = 3;

	//p.Save("debug.txt");
	p.x = p.y = p.z = 0;

	p.Load("debug.txt");	
}