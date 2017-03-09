#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>

int main(void)
{
	DIR *dp;
	int i = 0;
	struct dirent *p;
	dp = opendir(".");
	/*
	DIR *opendir(const char *dirname);
	opendir()함수는 매개변수 dirname 에 해당하는 디렉토리 스트림을 열고,
	그 디렉토리 스트림에 대한 포인터를 반환합니다.
 	포인터가 가리키는 디렉토리의 첫번째 항목을 가리킵니다.
	*/
	/*
	int readdir(unsigned int fd, struct dirent *dirp, unsigned int count);
	위 함수는 이미 바뀐 예전 커널시스템 콜 인터페이스를 위해
	manual에 존재하는 내용이며, 위 함수의 사용은 getdents() 가 대신하고 있다.
	readdir() 함수는 파일 서술자 fd 에 의해 지목된 디렉토리에서
	dirp 에 의해 포인트된 메모리 지역에 있는 dirent 구조체를 읽어, DIR * 에 저장한다.
	count 인자는 메모리 공간의 크기이지만, 무시 가능하다. 
	*/
	while(p = readdir(dp))
	{
		if(p->d_name[0] == '.')
			continue;
		printf("%-16s ", p->d_name);
		if((i + 1) % 5 == 0)
			printf("\n");
		i++;
	}
	printf("\n");
	closedir(dp);
	return 0;
}

#if 0
struct dirent
{
	long d_ino;	 	//아이노드 
	off_t d_off;	 	//dirent 의 offset 
	unsigned short d_reclen;//d_name 의 길이
	char d_name[NAME_MAX+1];//파일 이름 (없다면 NULL로 종료)		
}

dirent 구조체는 파일, 또는 디렉토리가 가지고 있는 정보 구조체이다.

d_ino :: 는 파일이 가지고 있는 자신만의 번호 inode를 가리키는 숫자이다.
d_off :: 는 디렉토리의 시작에서 dirent 까지의 거리를 말한다.
d_reclen :: 파일 혹은 디렉토리의 이름의 길이이다. (NULL을 포함하지 않는다.)
d_name :: 파일 혹은 디렉토리의 이름이다. (NULL이라면 파일 없음을 의미)

int closedir(DIR *dir)

closedir() 함수는 dir과 연관된 디렉토리 스트림을 닫습니다.
디렉토리 스트림 서술자 dir 은 위 함수 호출 이후에는 유효하지 않습니다. 
#endif
