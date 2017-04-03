#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
	int i;
	pid_t pid;
	unsigned int test_arr[7] = {0};

	register unsigned int *r0 asm("r0") = 0;
	register unsigned int r1 asm("r1") = 0;
	register unsigned int r2 asm("r2") = 0;
	register unsigned int r3 asm("r3") = 0;
	register unsigned int r4 asm("r4") = 0;
	register unsigned int r5 asm("r5") = 0;
	register unsigned int r6 asm("r6") = 0;

	r0 = test_arr;

	asm volatile("mov r1, #0x3\n"
				"mov r2, r1, lsl #2\n"
				"mov r4, #0x2\n"
				"add r3, r1, r2, lsl r4\n"
				"stmia r0!, {r1, r2, r3}\n" // {3, 12, 51}
				"str r4, [r0]\n"	// {3, 12, 51, 2}
				"mov r5, #128\n"
				"mov r6, r5, lsr #3\n"
				"stmia r0, {r4, r5, r6}\n"	// {3, 12, 51, 2, 128, 16}
				"sub r0, r0, #12\n"
				"ldmia r0, {r4, r5, r6}\n"
				"swp r6, r3, [r0]");

	for(i = 0; i < 7; i++)
		printf("test_arr[%d] = %d\n", i, test_arr[i]);

	printf("r4 = %u, r5 = %u, r6 = %u\n", r4, r5, r6);

	asm volatile("mov r7, #57\n"
				"swi #0" : "=m" (pid)::"memory");

	if(pid > 0)
		printf("Parent\n");
	else if(pid == 0)
		printf("Child\n");
	else
	{
		perror("fork()");
		exit(-1);
	}
	return 0;
}