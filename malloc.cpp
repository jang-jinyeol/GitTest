#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>
#pragma warning(disable:4996)

typedef struct book_title {

	int k;
	char* title;
}BINFO;

int main() {



	
	char temp[100];
	char* temp2;
	int i, n,len;
	BINFO* p;
	scanf("%d", &n);
	getchar();
	p = (BINFO*)malloc(sizeof(BINFO) * n);
	
	for (i = 0; i < n; i++) {
		gets_s(temp);
	

		p[i].title = (char*)malloc(sizeof(char)*strlen(temp)+1);
		strcpy(p[i].title, temp);
		//p[i].title = temp 대입으로 하면 전부 마지막것이 들어감
		


	}

	for (i = 0; i < n; i++) {
		
		printf("%s\n", p[i].title);

	}

	for (i = 0; i < n; i++) {

		free(p[i].title);

	}
	

	free(p);


	_CrtDumpMemoryLeaks();

	return 0;
}

