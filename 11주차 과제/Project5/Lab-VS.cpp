#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

struct SALARY {
	char name[20];
	int age;
	float salary;
}salary[20];

struct SALARY_V1 {
	char name[20];
	int age;
	float salary;
}v1[20];

struct SALARY_V3 {
	char name[20];
	int age;
	float salary;
}v3[20];

bool read_file(const char* fname) {
	FILE* pFile;
	int i = 0;
	pFile = fopen(fname, "r");

	if (pFile == NULL) {
		printf("Cannot open the file!\n");
		return false;
	}

	while (fscanf(pFile, "%s  %d  %f", &salary[i].name, &salary[i].age, &salary[i].salary) == 3) {
		i++;
	}

	fclose(pFile);
	return true;
}

bool write_salary2(const char* fname) {
	FILE* pFile;
	for (int i = 0; i < 20; i++) {
		if (salary[i].age / 10 == 4) {

			salary[i].salary *= 1.1f;

		}
	}

	pFile = fopen(fname, "w");

	if (pFile == NULL) {

		printf("Error: Cannot Open File: %s\n", fname);

		return false;
	}


	for (int i = 0; i < 20; i++) {
		fprintf(pFile, "%-5s  %d  %.1f\n",
			salary[i].name,
			salary[i].age,
			salary[i].salary);
	}

	fclose(pFile);

	return true;
}

bool write_salary3(const char* fname) {
	FILE* pFile;
	for (int i = 0; i < 20; i++) {
		if (salary[i].age / 10 == 3) {
			salary[i].salary *= 1.2f;
		}
	}
	pFile = fopen(fname, "w");

	if (pFile == NULL) {
		printf("Cannot open the File!\n");
		return false;
	}

	for (int i = 0; i < 20; i++) {
		fprintf(pFile, "%-5s  %d  %.1f\n", salary[i].name, salary[i].age, salary[i].salary);
	}

	fclose(pFile);

	return true;
}

void compare(const char* fname, const char* fname3) {

	

	FILE* pFile = NULL;
	int i = 0;

	pFile = fopen(fname, "r");

	if (pFile == NULL) {
		printf("Cannot open the file!\n");
		return;
	}

	while (fscanf(pFile, "%s  %d  %f", &v1[i].name, &v1[i].age, &v1[i].salary) == 3) {
		i++;
	}

	fclose(pFile);

	FILE* pFile2;
	i = 0;

	pFile2 = fopen(fname3, "r");

	if (pFile2 == NULL) {
		printf("Cannot open the file!!\n");
		return;
	}

	

	while (fscanf(pFile2, "%s %d %f", &v3[i].name, &v3[i].age, &v3[i].salary) == 3) {
		i++;
	}

	for (i = 0; i < 20; i++) {
		if (v1[i].salary < v3[i].salary) {
			printf("%-5s  %d  %.1f -> %.1f Different\n", v3[i].name, v3[i].age, v1[i].salary, v3[i].salary);
		}

		else {
			printf("%-5s  %d  %.1f -> %.1f\n", v3[i].name, v3[i].age, v1[i].salary, v3[i].salary);
		}

		fclose(pFile2);
	}

}

int main() {

	char fname[20] = "salary_v1.txt";

	if (!read_file("salary_v1.txt")) {
		return -1;
	}

	strcpy(fname, "salary_v2.txt");
	if (!write_salary2(fname)) {
		return -1;
	}

	strcpy(fname, "salary_v3.txt");
	if (!write_salary3(fname)) {
		return -1;
	}

	compare("salary_v1.txt", "salary_v3.txt");
	return 0;
}