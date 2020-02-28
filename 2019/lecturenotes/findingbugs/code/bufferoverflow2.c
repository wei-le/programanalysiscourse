//a real bug adapted via wu-ftpd-2.6.2

#include <string.h>
#include <stdio.h>

//test input: "hello" "/est" -- trigger the overflow\n
//test input: "hellowor" "/" -- safe
int MAXPATHLEN = 10;
char* wbuf;
char test[10];
char* fb_realpath(char*);

void main(int argc, char** argv){
	wbuf = argv[1];
	strcpy(test, argv[2]);
	fb_realpath(test);
}

char* fb_realpath(char* resolved){
	int rootd = -1;
	if (resolved[0]=='/' && resolved[1]=='\0')
		rootd = 1;
	else
		rootd = 0;
	if(*wbuf){
		if (strlen(resolved)+strlen(wbuf)+rootd+1 >MAXPATHLEN){
			return resolved;
		}
		if (rootd == 0)
			strcat(resolved, "/");
		strcat(resolved, wbuf);	
		printf("rootd: %d\n",rootd);
		printf("string length: %d\n", strlen(resolved));
		if(10<=strlen(resolved))
			printf("buffer overflow\n");
	}
	return resolved;
}