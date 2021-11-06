#include <stdio.h>
#include <string.h>

#define MAX_NUM 20

struct EMPLOYEE {
	char RRN[14];
	char name[20];
	float salary;
	float bonus;
} employee[1000];

struct DATASET {
	char RRN[14];
	char name[20];
	float salary;
	float bonus;
}dataset[5]{
	  {"0105104077777", "Baek" , 1, 0 },
	  {"0031344562341", "Cha", 3, 2},
	  {"0105112123457", "Kim" , 4, 2},
	  {"9923345561234", "Lee", 3, 5},
	  {"0023234213545", "Hwang", 2, 1}
};



int Constraint_U(const char* search) {

	int search_key = 0;

	for (int i = 0; i < 5; i++) {
		if (strcmp(search, dataset[i].RRN) == 0) {
			search_key = i;
			break;
		}
		else {
			search_key = -1;
		}
	}
	return  search_key;
}


int main() {
	char add_RRN[MAX_NUM][14] = {
		"0105102345277", // unique
		"0031323465441", // unique
		"0105112123457", // ununique
		"9923361425234", // unique but bonus > salary
		"0023234523545" // unique
	};

	
	for (int t = 0; t < 5; t++) {
		
		char* search_key = add_RRN[t];

		int index = Constraint_U(search_key);
	

		printf("\n//--- Experiment(%d) --- \n", t + 1);
		
		if (index > 0) {
			printf("This Data is invalid because RRN is not unique.\n");
		}

		else {
			if (dataset[t].salary < dataset[t].bonus) {
				printf("This data is invalid because bonus is not smaller than salary\n");
			}
			else {
				strcpy_s(employee[index].RRN, dataset[t].RRN);
				strcpy_s(employee[index].name, dataset[t].name);
				employee[index].salary = dataset[t].salary;
				employee[index].bonus = dataset[t].bonus;

				printf("RRN: (%s), name: (%s), salary: (%f), bonus: (%f)\n", employee[index].RRN, employee[index].name, employee[index].salary, employee[index].bonus);

			}
		}
	}
	return 0;
	

}
	



	


	