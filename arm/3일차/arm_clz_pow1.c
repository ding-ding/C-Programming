#include <stdio.h>
#include <math.h>

int main(void)
{ 
	register unsigned int r0 asm("r0") = (unsigned int)pow(2.0, 27);
	register unsigned int r1 asm("r1") = 0;
	register unsigned int r2 asm("r2") = 0;
	register unsigned int r3 asm("r3") = 0;
	register unsigned int r4 asm("r4") = 0;
	register unsigned int r5 asm("r5") = 0;
	register unsigned int r6 asm("r6") = 0;

	asm volatile("mov r0, #31\n"
					"clz r1, r0");

	printf("r1 = %u, r0 = 0x%x\n", r1, r0);

	return 0;
}