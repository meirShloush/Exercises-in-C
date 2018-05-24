#include<string.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct
{
	char firstName[15];
	char lastName[15];
	size_t ID;
	char cellularNumber[15];	
	char gender;	
}person;


void PrintPerson(person p)
{
	printf("name: %s %s\n", p.firstName, p.lastName);
	printf("ID: %d\n", (int)p.ID);
	printf("cellular number: %s\n", p.cellularNumber);
	printf("gender: %c\n\n", p.gender);
}


int main(int argc, char **argv)
{
	int res = 0;
	FILE *fp = NULL;
	person copy_person[3];
	person person_arr[3] = 
	{
		{"meir", "shloush", 300, "050-7654812", 'm'},
		{"maggy", "sss", 100, "0987652", 'f'},
		{"bbb", "ddd", 200, "09432575", 'f'},
	};
	
	/* Open file for both reading and writing */
	fp = fopen("person.txt" , "w+");
	if (NULL == fp)
	{
		exit(1);
	}

	fwrite(person_arr, 3, sizeof(person), fp);	
	fseek(fp, 0, SEEK_SET);
	fread(copy_person, 3, sizeof(person), fp);
	fclose(fp);	
	
	/* compare between copy_person and person_arr */
	res = memcmp(copy_person, person_arr, sizeof(person) * 3);
	
	printf((res == 0) ? "Copy successful\n": "Copy fail\n");
	
	return(0);
}


