#include <stdio.h>
#include <stdlib.h>

int isNum(int n)
{
	if(n>10)
		return 2;
	else if(n>5)
		return 1;
	else if(n>=0)
		return 0;
	else 
		return -1;
}
int main (int argc, char* argv[])
{
	int i = 0;
	for(i=-1;i<12;++i)
		isNum(i);
	return 0;
}
