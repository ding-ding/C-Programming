#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int check(char buf[1024], char buf1[1024], int i)
{
	int j;
	for(j = 0; buf1[j]; j++)
	{
		if(!(buf[i+j] == buf1[j]))
			return 0;
	}
	return 1;
}

int arr_size(char arr1[1024])
{
	int i = 0;
	while(1) 
	{
		i++;
		if(arr1[i] == '\0')
			return i;
	}
}
void prn_arr(char arr[1024])
{
	int i;
	for(i = 0; ; i++)
	{
		printf("%c", arr[i]);
		if(arr[i] == '\0')
			break;
	}
	printf("\n");
}

void chg_buf(char tmp[1024], char buf[1024], char pre[1024], char aft[1024])
{
	int i, j = 0, k = 0;

	for(i = 0; buf[i]; i++)
	{
		tmp[j] = buf[i];
		if(check(buf, pre, i))
		{
			while(1)
			{
				if(aft[k] == '\0')
					break;
				tmp[j + k] = aft[k];
				k++;
			} 
			i += (arr_size(pre)-1);
			j += (k-1);
		}
		j++;
	}
}

int main(void)
{
	int filedes, fdout, i, j, size, k = 0;
	ssize_t nread;
	char buf[1024];
	char tmp[1024];
	char pre[1024] = "Cortex-R5F Safety MCU";
	char aft[1024] = "C6678 Safety DSP";

	filedes = open("tmp.txt", O_RDONLY, 0644);
	fdout = open("tmp2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);


	while((nread = read(filedes, buf, 1024)) > 0)
	{
		chg_buf(tmp, buf, pre, aft);
		
		if(write(fdout, tmp, arr_size(tmp)) < nread)
		{
			close(filedes);
		}
	}
	close(filedes);

	return 0;

}