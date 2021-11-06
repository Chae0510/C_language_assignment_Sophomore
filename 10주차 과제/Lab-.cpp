#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LEN 8 // ���� ����
#define MAX_HOBBY_LEN 8	
#define MAX_PERSONS 30 // 20�������� �����ְ� 30������ �����

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

bool read_file(const char *fname, PERSONAL persons[], int *num_persons   /*const int a, int* b*/) { // file reading �����ߴ��� �д� �Լ�
	// const�� �����Ǿ��� ������ function �ȿ��� ���� �ٲ��� �ʴ´ٴ� �� �� �� ���� 
	// int *b�� const�� ���� �ٲ� �� �ִٴ� ���� �� �� �ֱ� ������ �ƿ�ǲ�̶�� ����� �� �� �ִ�.
	FILE* pFile;

	pFile = fopen(fname, "r");
	if (pFile == NULL) { // file reading failed

		printf("Error: Cannot Read File: %s\n", fname);
		*num_persons = 0;
		return false; // �������� �ʰ� ���߰�
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

bool write_file(const char* fname, const PERSONAL persons[], const int num_persons /*�� �� input �̶�� ��� �� ���� �� �� ����*/) {
	
	FILE* pFile;

	pFile = fopen(fname, "w");

	if (pFile == NULL) { // file reading failed

		printf("Error: Cannot Open File: %s\n", fname);

		return false; // �������� �ʰ� ���߰�
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
	 // sub problem ���� �Լ� ¥��! code �ξ� �б� ��������, code ���� ����

	PERSONAL persons[MAX_PERSONS]; // data �о���̴� ��
	int num_persons= 0;

	if (!read_file("personal.txt", persons, &num_persons)) { // ! : reading failed �ؽ�Ʈ ���� �о���� ����(�ܺο���)
		return -1;
	}

	if (!write_file("test.txt", persons, num_persons)) { // ! : reading failed �ؽ�Ʈ ���� �о���� ����(�ܺο���)
		return -1;
	}
	return 0
}