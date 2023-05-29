#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int find(const char* string, const char* query); //returns index of query in string
int replace(char string[], const char* insert, int index, int querylen); //modifies string by inserting at index, string should be big enough

int main(int argc, char *argv[]){

	if(argc < 3){
		printf("Too Few Arguments!");
		return 0;
	}
	char usrinput[MAXLEN];


	int i = 0;
	int c;
	while((c = getchar()) != '\n'){
		usrinput[i] = c;
		i++;
	}
	usrinput[++i] = '\0';
			


	int index;
	int querylen = strlen(argv[1]);

	index = find(usrinput, argv[1]);

	while (1) {
		replace(usrinput, argv[2], index, querylen);
		index = find(usrinput, argv[1]);
		if (index == -1)
			break;
	}

	
	
	printf("%s\n", usrinput);
}

int find(const char* string, const char* query)
{
	char* ptr;
	ptr = strstr(string, query);
	if (ptr == NULL)
		return -1;
	return ptr - string;
}

int replace(char string[], const char* insert, int index, int querylen)
{
	int j = 0;
	int insertlen = strlen(insert);
	int indexafterinsert = index + querylen;
	char originalstr[1000];
	strcpy(originalstr, string);

	for (j = 0; j < insertlen; j++) {
		string[index++] = insert[j];
	}

	for (indexafterinsert; originalstr[indexafterinsert] != '\0'; indexafterinsert++) {
		string[index++] = originalstr[indexafterinsert];
	}
	
	string[index] = '\0';
	return 1;
}
