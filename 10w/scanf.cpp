#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "class.h"
#include <string.h>
#include <stdlib.h>
#define INTMAX 2147483647;

int main() {
	char format[255];
	char input[255];

	fileGenerator();
	fileReader(format, input, 255);

	printf("텍스트를 확인합니다.\n");
	printf("format : %s\n", format);
	printf("input  : %s\n", input);

	char check[3][3] = { "%d","%s","%c" };
	int formatCount[3] = { 0 };
	char* ptr = format;
	int count = 0;
	for (int i = 0; i < 3; i++) {
		while (ptr = strstr(ptr, check[i])) { 
			count++; 
			ptr++;
		}
		formatCount[i] = count;
		count = 0;
		ptr = format;
	}

	printf("--------------------------------------\n");
	printf("%%d 개수 : %d\n", formatCount[0]);
	printf("%%s 개수 : %d\n", formatCount[1]);
	printf("%%c 개수 : %d\n", formatCount[2]);
	int* intARR = (int*)malloc(sizeof(int*) * formatCount[0]);
	char** strARR = (char**)malloc(sizeof(char*) * formatCount[1]);
	for (int i = 0; i < formatCount[1]; i++) {
		strARR[i] = (char*)malloc(sizeof(char) * 100); 
	}
	char* charARR = (char*)malloc(sizeof(char*) * formatCount[2]);

	for (int i = 0; i < formatCount[0]; i++) {
		intARR[i] = INTMAX;
	}

	int size = formatCount[0] + formatCount[1] + formatCount[2];
	size = 1 + size * 2;
	char** str_arr = (char**)malloc(sizeof(char*) * size);	
	for (int i = 0; i < size; i++) {
		str_arr[i] = (char*)malloc(sizeof(char) * 100);
	}

	int index = 0;
	while (ptr = strstr(ptr, "%")) { 
		strncpy(str_arr[count++], &format[index], ptr - format - index);	
		str_arr[count - 1][ptr - format - index] = '\0';

		index = ptr - format;

		strncpy(str_arr[count++], &format[index], 2);
		str_arr[count - 1][2] = '\0';

		index = index + 2;
		ptr = ptr + 2; 
	}
	int len = strlen(format) - index;

	strncpy(str_arr[count], &format[index], len);
	str_arr[count][len] = '\0';
	
	int tmplen;
	char tmpstr[100];
	ptr = input;
	char* start_point;
	char* end_point;
	int length;
	for (int i = 0 ; i < size; i++) {
		printf("문자열 길이 : %d\t 배열 인덱스 %d: %s",strlen(str_arr[i]), i, str_arr[i]);
		tmplen = strlen(str_arr[i]);
		if (strstr(str_arr[i], "%")) {
			for (int j = 0; j < 3; j++) {
				if (strstr(str_arr[i], check[j])) {
					start_point = ptr;
					end_point = strstr(input, str_arr[i + 1]); 

					length = end_point - start_point;
					
					strncpy(tmpstr, ptr, length);
					tmpstr[length] = '\0';

					printf("\t추출값 : %s", tmpstr);
					tmplen = strlen(tmpstr);

					if (j == 0) {
						for (int a = 0; a < formatCount[0]; a++) {
							if (intARR[a] == 2147483647) {
								intARR[a] = atoi(tmpstr);
							}
						}
					}
					else if (j == 1) {
						for (int a = 0; a < formatCount[1]; a++) {
							strcpy(strARR[a], tmpstr);
						}
					}
					else if (j == 2) {
						for (int a = 0; a < formatCount[2]; a++) {
							charARR[a] = tmpstr[0];
						}
					}


					break;
				}
			}
		}
		printf("\n");
		ptr = ptr + tmplen;
	}

	printf("\nDatasave.txt파일에 분리해서 저장 완료\n");

	FILE* ff;

	ff = fopen("Datasave.txt", "w");

	for (int a = 0; a < formatCount[0]; a++) {
		fprintf(ff,"int  \t: %d\n", intARR[a]);
	}
	for (int a = 0; a < formatCount[1]; a++) {
		fprintf(ff, "string\t: %s\n", strARR[a]);
	}
	for (int a = 0; a < formatCount[2]; a++) {
		fprintf(ff, "char\t: %c\n", charARR[a]);
	}

	fclose(ff);

	return 0;
}