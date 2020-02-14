//adapted from Sendmail-8.7.5
#include<string.h>
#include<stdlib.h>

//input: "hello world"
void main(int argc, char** argv){
	char buf0[8];
	char* buf;
	char* q_user = argv[1];
	int i = strlen(q_user);
	printf("sizeof buf0: %d",sizeof(buf0));
	if (i>= sizeof(buf0))
		buf = (char*)malloc(i+1);
	else 
		buf = buf0;
	strcpy(buf, q_user);
}