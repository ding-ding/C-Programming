#include <stdio.h>
typedef void (*funcp)(void);

void test(void)
{
	printf("Hello\n");
}


int main(void)
{ 
	register funcp r0 asm("r0") = 0;
	register unsigned int r1 asm("r1") = 0;
	register unsigned int r2 asm("r2") = 0;
	register unsigned int r3 asm("r3") = 0;
	register unsigned int r4 asm("r4") = 0;
	register unsigned int r5 asm("r5") = 0;
	register unsigned int r6 asm("r6") = 0;

	r0 = test;

	asm volatile("bx r0");

	return 0;
}