#if 0
1. test.txt 파일을 생성하는 프로그램을 작성하시오.

2. doc.txt 에 아무런 내용을 기입하고 이 내용을 읽는 프로그램을 작성하시오.

3. 아래 내용을 opengl.txt 에 저장하고 여기서 opengl 이 몇 번 반복되는지 찾으시오.

OpenGL Headline News

WGL_EXT_colorspace specification is now available
WGL_EXT_colorspace specification is available and implemented in GeForce 376.09 drivers. This extension enables faster support of linear rendering on Windows with OpenGL ES for physically based shading. WGL_EXT_colorspace allows rendering directly to the default framebuffer without requiring an intermediate framebuffer and extra blit to perform the linear to sRGB conversion on the default framebuffer. This extension is used in Unity 5.5 editor for OpenGL ES native emulation enabling faster iterations while developing high quality graphics on mobile.
#endif


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE	1024

void downcase(char *con)
{
	int i;
	for(i = 0; con[i]; i++)
	{
		if(con[i] >= 65 && con[i] <= 90)		
			con[i] += 32;
	}
}

int buf_cmp(char *con, char *find)
{
	downcase(con);
	downcase(find);
	if(!(strncmp(con, find, strlen(find))))
		return 1;
	return 0;
}

int main(void)
{
	int fd, cnt = 0, i;
	char buf[BUFSIZE] = "";
	char tmp[BUFSIZE] = "OpenGL Headline News WGL_EXT_colorspace specification is now available WGL_EXT_colorspace specification is available and implemented in GeForce 376.09 drivers. This extension enables faster support of linear rendering on Windows with OpenGL ES for physically based shading. WGL_EXT_colorspace allows rendering directly to the default framebuffer without requiring an intermediate framebuffer and extra blit to perform the linear to sRGB conversion on the default framebuffer. This extension is used in Unity 5.5 editor for OpenGL ES native emulation enabling faster iterations while developing high quality graphics on mobile.";
	char find[BUFSIZE] = "opengl";
	

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd = open("doc.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, tmp, strlen(tmp));
	fd = open("doc.txt", O_RDONLY);
	read(fd, buf, sizeof(buf));
	printf("%s\n", buf);

	fd = open("opengl.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, tmp, strlen(tmp));
	fd = open("opengl.txt", O_RDONLY);
	memset(buf, 0, sizeof(buf));
	read(fd, buf, sizeof(buf));
	for(i = 0; buf[i]; i++)
	{
		if(buf_cmp(&buf[i], find))
			cnt++;
	}
	printf("cnt = %d\n", cnt);

	return 0;
}
