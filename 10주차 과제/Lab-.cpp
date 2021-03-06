#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LEN 8 // 띄어쓰기 포함
#define MAX_HOBBY_LEN 8	
#define MAX_PERSONS 30 // 20명이지만 여유있게 30명으로 잡았음

struct PERSONAL {
	char name[20];
	int age;
	char hobby[20];
};

void copy_element(const PERSONAL* src, PERSONAL* dest) {
	
	strcpy(dest->name, src->name);
	dest->age = src->age;
	strcpy(dest->hobby, src->hobby);
}

bool read_file(const char *fname, PERSONAL persons[], int *num_persons   /*const int a, int* b*/) { // file reading 성공했는지 읽는 함수
	// const로 지정되었기 때문에 function 안에서 값이 바뀌지 않는다는 걸 알 수 있음 
	// int *b는 const가 없어 바뀔 수 있다는 것을 알 수 있기 때문에 아웃풋이라는 사실을 알 수 있다.
	FILE* pFile;

	pFile = fopen(fname, "r");
	if (pFile == NULL) { // file reading failed

		printf("Error: Cannot Read File: %s\n", fname);
		*num_persons = 0;
		return false; // 수행하지 않고 멈추게
	}

	PERSONAL read_person;
	int num = 0;

	while (fscanf(pFile, "%s %d %s",
		&read_person.name,
		&read_person.age,
		&read_person.hobby) == 3) {

		copy_element(&read_person, &persons[num]);
		num++;
	}

	fclose(pFile);

	*num_persons = num;
	return true;
}

bool write_file(const char* fname, const PERSONAL persons[], const int num_persons /*셋 다 input 이라는 사실 한 눈에 알 수 있음*/) {
	
	FILE* pFile;

	pFile = fopen(fname, "w");

	if (pFile == NULL) { // file reading failed

		printf("Error: Cannot Open File: %s\n", fname);

		return false; // 수행하지 않고 멈추게
	}

	for (int i = 0; i < num_persons; i++) {
		fprintf(pFile, "%8s %d %8s\n", 
			persons[i].name,
			persons[i].age,
			persons[i].hobby);
	}

	fclose(pFile);
	return true;
}

int main (int argt, char* argv[]) {
	 // sub problem 별로 함수 짜기! code 훨씬 읽기 편해지고, code 이해 가능

	PERSONAL persons[MAX_PERSONS]; // data 읽어들이는 중
	int num_persons= 0;

	if (!read_file("personal.txt", persons, &num_persons)) { // ! : reading failed 텍스트 파일 읽어오기 실패(외부요인)
		return -1;
	}

	if (!write_file("test.txt", persons, num_persons)) { // ! : reading failed 텍스트 파일 읽어오기 실패(외부요인)
		return -1;
	}
	return 0
}