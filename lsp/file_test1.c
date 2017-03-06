#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 	1024

void fd_open(char **fname, int *fd)
{
	fd[0] = open(fname[0], O_RDONLY);
	fd[1] = open(fname[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
}

void str_cng(char *con, char *find, char *mod)
{

}

void mod_contents(char *con, char *find, char *mod, int fd)
{
	int i, c_len, m_len, f_len;
	int save = 0, t_save = 0, c_save = 0;
	char tmp[1024] = "";

	f_len = strlen(find);
	c_len = strlen(con);
	m_len = strlen(mod);

	// for(i = 0; con[i]; i++)
	// 	printf("%s\n", &con[i]);

	for(i = 0; con[i]; i++){
		save = i;
		if(!strncmp(&con[i], find, f_len)){
			strncpy(&tmp[t_save], mod, m_len);
			// strncpy(&tmp[save + m_len], &con[save + f_len], c_len - save - f_len);
			t_save = save + m_len;
		}
		else{
			strncpy(&tmp[t_save], &con[i], strlen(&con[i]));
			t_save = save + strlen(&con[i]);
		}
	}

	// for(i = 0; tmp[i]; i++)
	// 	printf("%s\n", &tmp[i]);

}

void analysis_contents(int *fd)
{
	int filedes;
	char buf[BUFSIZE] = "";
	char *mod = "DSP";
	char *find = "BBBB";

	filedes = read(fd[0], buf, sizeof(buf));
	int i;
	for(i = 0; buf[i]; i++)
		printf("%s\n", &buf[i]);

	write(0, buf, strlen(buf));

	mod_contents(buf, find, mod, fd[1]);
}

int main(void)
{
	int fd[2] = {0};
	char *fname[2] = {"AA.txt", "change.txt"};

	fd_open(fname, fd);

	analysis_contents(fd);

	return 0;
}

// int main(void)
// {
// 	int fdin, fdout;
// 	ssize_t nread;
// 	char buf[BUFSIZE];
// 	char pre[BUFSIZE] = "BBBB";
// 	char aft[BUFSIZE] = "DSP";

// 	fdin = open("temp1.txt", O_RDONLY);
// 	fdout = open("temp2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

// 	while((nread = read(fdin, buf, 1024)) > 0)
// 	{
// 		if(write(fdout, tmp, arr_size(tmp)) < nread)
// 		{
// 			close(fdin);
// 			close(fdout);
// 		}
// 	}

// }