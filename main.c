#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4

int main(int argc, char **argv){
	if (argc < 2){
		printf("Ti eblan eshe imya faila");
		return 0;
	}	
	
	FILE *fp = fopen(argv[1], "r");
	int matrix = (int*)malloc(N * sizeof(int));
	if(matrix == NULL){
		printf("Error of memory");
		return 0;
	}

	for(int i = 0; i < N; i++){
		matrix[i] = (int*)malloc(N * sizeof(int));
		if(matrix[i] == NULL){
			printf("Error of memory");
			return 0;
		}
	}
//Допиши там потом
//остлаось только читать числа с файла и записывать их в массивы 


	return 0;
}
