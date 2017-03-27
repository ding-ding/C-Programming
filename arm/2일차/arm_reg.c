#include <stdio.h>

int main (void)
{
	register unsigned int r0 asm("r0");
	register unsigned int r1 asm("r1");
	register unsigned int r2 asm("r2");
	register unsigned int r3 asm("r3");

	r1 = 77;
	r2 = 37;
	r3 = 34;

	if(r2 < r1)
		asm volatile("sublt r3, r2, r3");		//r1 = 77, r2 = 37, r3 = 3
		// asm volatile("subgt r3, r3, #1"); 		//r1 = 77, r2 = 37, r3 = 33
		//asm volatile("subgt r3, r3, r2");		//r1 = 77, r2 = 37, r3 = -3

	printf("r1 = %d, r2 = %d, r3 = %d\n", r1, r2, r3);
	return 0;
}