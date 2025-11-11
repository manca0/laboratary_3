#include <stdio.h>
#include <stdlib.h>

//it is 1 task
int sum_diag(int **arr, int cols, int rows){
	int result = 0;
	for(int i = rows-1, j = 0; i >= 0 && j < cols; i--, j++){
		if(arr[i][j] < 0) result += arr[i][j];
	}
	return result;
}

//it is 2 task
int min(int **arr, int rows){
	int temp = 99999;
	for(int i = 0; i < rows; i++){
		if(arr[i][2] < temp) temp = arr[i][2];	
	}
	return temp;
}	


//it is 3 task
void swap(int **arr, int rows, int el){
	int temp = arr[3][2];
	int index = 0;
	for(int i = 0; i < rows; i++){
		if(arr[i][2] == el) index = i;
	}
	arr[3][2] = el;
	arr[index][2] = temp;
}

int main(int argc, char **argv){
	if (argc < 2){
		printf("Too few arguments!\n");
		return 0;
	}	
	
	FILE *fp = fopen(argv[1], "r");
	if(!fp){ printf("Error with file!\n"); return 1;}

	//read the size of matrix
	char c;
	int rows = 0;
	int cols = 1;
	while((c = fgetc(fp)) != EOF){
		if (((int)c >= 48 && (int)c <= 57) || (int)c == 32 || (int)c == 10 || (int)c == 45){
			if(c == '\n') rows++;
			if(c == ' ' && rows == 0) cols++;
		}
		else{
			printf("Elements must be only numbers!\n");
			return 0;
		}
	}
	if (!(rows >= 4 && cols >= 4)){
		printf("matrix must be minimum 4x4!\n");
		return 1;
	}
	rewind(fp);

	
	int **matrix = (int**)malloc(rows * sizeof(int*));
	if(matrix == NULL){
		printf("Error of memory\n");
		return 0;
	}

	for(int i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(cols * sizeof(int));
		if(matrix[i] == NULL){
			printf("Error of memory\n");
			return 0;
		}
	}
	
	//read matrix from file to array
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			fscanf(fp, "%d", &matrix[i][j]);
		}
	}
	
	//realization block
	printf("sum = %i\n", sum_diag(matrix, cols, rows));
	printf("min = %i\n", min(matrix, rows));
	swap(matrix, rows, min(matrix, rows));

	for(int g = 0; g < rows; g++){
		for(int k = 0; k < cols; k++){
			printf("%i ", matrix[g][k]);
		}
		printf("\n");
	}

	//block of close/clear
	fclose(fp);
	for(int i = 0; i < rows; i++){
		free(matrix[i]);
		matrix[i] = NULL;
    }	
	free(matrix);
	matrix = NULL;

	return 0;
}
