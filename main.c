#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4


//it is 1 task
int sum_diag(int **arr){
	int result = 0;
	for(int i = 3, j = 0; i >= 0 && j < N; i--, j++){
		if(arr[i][j] < 0) result += arr[i][j];
	}
	return result;
}

//it is 2 task
int min(int **arr){
	int temp = 99999;
	for(int i = 0; i < N; i++){
		if(arr[i][2] < temp) temp = arr[i][2];	
	}
	return temp;
}	


//it is 3 task
void swap(int **arr, int el){
	int temp = arr[3][2];
	int index = 0;
	for(int i = 0; i < N; i++){
		if(arr[i][2] == el) index = i;
	}
	arr[3][2] = el;
	arr[index][2] = temp;
}

int main(int argc, char **argv){
	if (argc < 2){
		printf("Ti eblan eshe imya faila");
		return 0;
	}	
	
	FILE *fp = fopen(argv[1], "r");
	if(!fp){ printf("Error with file!"); return 1;}
	
	
	int **matrix = (int**)malloc(N * sizeof(int*));
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
	
	int i = 0;
	int j = 0;
	for(; fscanf(fp, "%i", &matrix[i][j]) == 1; i++){
		for(; j < N - 1; j++){
			fscanf(fp, "%i", &matrix[i][j+1]);
		}
		j = 0;
	}
	

	printf("sum = %i\n", sum_diag(matrix));
	printf("min = %i\n", min(matrix));
	swap(matrix, min(matrix));

	for(int g = 0; g < N; g++){
		for(int k = 0; k < N; k++){
			printf("%i ", matrix[g][k]);
		}
		printf("\n");
	}

	//блок удаления\закрытия
	fclose(fp);
	for(int i = 0; i < N; i++){
		free(matrix[i]);
		matrix[i] == NULL;
	}
	free(matrix);
	matrix = NULL;

	return 0;
}
