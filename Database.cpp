#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctype.h>

CardMain* input() {
	static int count = 0;
	char* Name = (char*)malloc(sizeof(char) * 256);
	char* LastName = (char*)malloc(sizeof(char) * 256);
	int age, dept;
	CardMain* card = (CardMain*)malloc(sizeof(CardMain));
	printf("What department would you like to add to?\n");
	printf("Programmers - 0\n");
	printf("Management - 1\n");
	printf("Shipping - 2\n");
	(void)scanf("%d", &dept);
	printf("Enter a name: ");
	(void)scanf("%s", Name);
	Name = (char*)realloc(Name, sizeof(char) * (strlen(Name) + 1));
	printf("Enter a last name: ");
	(void)scanf("%s", LastName);
	LastName = (char*)realloc(LastName, sizeof(char) * (strlen(LastName) + 1));
	printf("Enter an age: ");
	(void)scanf("%d", &age);
	card->age = age;
	switch (dept) {
	case 0:
		card->dept_type = DEPT_PROGRAMMERS;
		break;
	case 1:
		card->dept_type = DEPT_MANAGEMENT;
		break;
	case 2:
		card->dept_type = DEPT_SHIPPING;
		break;
	}
	card->Name = (char*)malloc(sizeof(char) * (strlen(Name) + 1));
	card->LastName = (char*)malloc(sizeof(char) * (strlen(LastName) + 1));
	strcpy(card->Name, Name);
	strcpy(card->LastName, LastName);
	getSpec(*card);
	free(Name);
	free(LastName);
	return card;
}

void CardMain::print() {
	printf("%10s  %10s %10d", Name, LastName, age);
	switch (dept_type) {
	case DEPT_PROGRAMMERS:
		printf("%10s", "Prog-s");
		printf("%10s %10s %10d", task.p_task.Project, task.p_task.CPU, task.p_task.Memory);
		break;
	case DEPT_MANAGEMENT:
		printf("%10s", "Mng");
		printf("%10s %10s %10d", task.m_task.Project, task.m_task.Customer, task.m_task.ProgrammersNum);
		break;
	case DEPT_SHIPPING:
		printf("%10s", "Ship");
		printf("%10s %10s %10d", task.s_task.Address, task.s_task.Customer, task.s_task.Weight);
		switch (task.s_task.tr_type) {
		case TRANSP_TRAIN:
			printf("%10s", "Train");
			break;
		case TRANSP_AUTO:
			printf("%10s", "Auto");
			break;
		case TRANSP_AERO:
			printf("%10s", "Plane");
			break;
		case TRANSP_SHIP:
			printf("%10s", "Ship");
			break;
		}
		break;
	}
	
}

CardMain::~CardMain() {
	free(Name);
	free(LastName);
}
Task::Task() {
	printf("fuck");
}
Task::~Task() {
	printf("fcuk");
}
bool list::isEmpty() {
	if (tail == nullptr && head == nullptr) return true;
	else return false;
}

CardMain::CardMain() {
	Name = nullptr;
	LastName = nullptr;
	age = 0;
}

void getSpec(CardMain& card) {
	switch (card.dept_type) {
	case DEPT_PROGRAMMERS:
		setProgSpec(card);
		break;
	case DEPT_MANAGEMENT:
		setManSpec(card);
		break;
	case DEPT_SHIPPING:
		setShipSpec(card);
		break;
	}
}
void setProgSpec(CardMain& card) {
	card.task.p_task.Project = (char*)malloc(sizeof(char) * 256);
	card.task.p_task.CPU = (char*)malloc(sizeof(char) * 256);
	printf("Enter the project name: ");
	(void)scanf("%s", card.task.p_task.Project);
	char* cpu = (char*)malloc(sizeof(char) * 256);
	printf("Enter the cpu name: ");
	(void)scanf("%s", card.task.p_task.CPU);
	printf("Enter the amount of memory: ");
	(void)scanf("%d", &card.task.p_task.Memory);
	card.task.p_task.Project = (char*)realloc(card.task.p_task.Project, sizeof(char) * (strlen(card.task.p_task.Project) + 1));
	card.task.p_task.CPU = (char*)realloc(card.task.p_task.CPU, sizeof(char) * (strlen(card.task.p_task.CPU) + 1));
}
void setManSpec(CardMain& card) {
	card.task.m_task.Project = (char*)malloc(sizeof(char) * 256);
	card.task.m_task.Customer = (char*)malloc(sizeof(char) * 256);
	printf("Enter the project name: ");
	(void)scanf("%s", card.task.m_task.Project);
	printf("Enter customer's last name: ");
	(void)scanf("%s", card.task.m_task.Customer);
	printf("Enter the number of programmers: ");
	(void)scanf("%d", &card.task.m_task.ProgrammersNum);
	card.task.m_task.Customer = (char*)realloc(card.task.m_task.Customer, sizeof(char) * (strlen(card.task.m_task.Customer) + 1));
	card.task.m_task.Project = (char*)realloc(card.task.m_task.Project, sizeof(char) * (strlen(card.task.m_task.Project) + 1));
}
void setShipSpec(CardMain& card) {
	int temp;
	card.task.s_task.Address = (char*)malloc(sizeof(char) * 256);
	card.task.s_task.Customer = (char*)malloc(sizeof(char) * 256);
	printf("Enter the address: ");
	(void)scanf("%s", card.task.s_task.Address);
	printf("Enter customer's last name: ");
	(void)scanf("%s", card.task.s_task.Customer);
	printf("Enter the weight: ");
	(void)scanf("%d", &card.task.s_task.Weight);
	printf("Choose the transport from the list: \n");
	printf("Train - 0\n");
	printf("Auto - 1\n");
	printf("Plane - 2\n");
	printf("Ship - 3\n");
	(void)scanf("%d", &temp);
	switch (temp) {
	case 0:
		card.task.s_task.tr_type = TRANSP_TRAIN;
		break;
	case 1:
		card.task.s_task.tr_type = TRANSP_AUTO;
		break;
	case 2:
		card.task.s_task.tr_type = TRANSP_AERO;
		break;
	case 3:
		card.task.s_task.tr_type = TRANSP_SHIP;
		break;
	}
	card.task.s_task.Address = (char*)realloc(card.task.s_task.Address, sizeof(char) * (strlen(card.task.s_task.Address) + 1));
	card.task.s_task.Customer = (char*)realloc(card.task.s_task.Customer, sizeof(char) * (strlen(card.task.s_task.Customer) + 1));
}


ManagerTask::ManagerTask() {
	Project = nullptr;
	Customer = nullptr;
}
ManagerTask::~ManagerTask() {
	free(Project);
	free(Customer);
}

ProgTask::ProgTask() {
	Project = nullptr;
	CPU = nullptr;
}

ProgTask::~ProgTask() {
	free(Project);
	free(CPU);
}

ShipTask::ShipTask() {
	Address = nullptr;
	Customer = nullptr;
}

ShipTask::~ShipTask() {
	free(Address);
	free(Customer);
}

list::list() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

list::~list() {
	Node* tmp = this->head;
	while(tmp->next) {
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
}

list* init() {
	list* lst;
	lst = (list*)malloc(sizeof(list));
	lst->size = 0;
	lst->head = nullptr;
	lst->tail = nullptr;
	return lst;
}

void list::push_back(CardMain& _card) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->card = _card;
	tmp->next = nullptr;
	tmp->prev = this->tail;
	if (this->tail) this->tail->next = tmp;
	this->tail = tmp;
	if (this->head == nullptr) this->head = tmp;
	this->size++;
}

void list::print() {
	Node* tmp = this->head;
	int i = 0;
	printf("#  |%10s|%10s|%10s|%10s||%10s|%10s|%10s|%10s\n", "Name", "Last Name", "Age", "Dept P", "Project", "CPU", "Memory", " ");
	printf("   |%10s|%10s|%10s|%10s||%10s|%10s|%10s|%10s\n", " ", " ", " ", " M", "Project", "Customer", "Progers", " ");
	printf("   |%10s|%10s|%10s|%10s||%10s|%10s|%10s|%10s\n", " ", " ", " ", " S", "Address", "Customer", "Weight", "Transport");
	printf("--------------------------------------------------------------------------------------------\n");
	while (tmp && i < size) {
		printf("%3d", i++);
		tmp->card.print();
		tmp = tmp->next;
		printf("\n");
	}
	printf("\n");
	free(tmp);
}

void list::fprint() {
	FILE* f;
	char file_name[] = "C:\\Users\\User\\source\\repos\\Project9\\Project9\\Out.txt";
	if ((f = fopen(file_name, "w")) == NULL) printf("File error\n");
	Node* tmp = this->head;
	int i = 0;
	fprintf(f, "#  |%10s|%10s|%10s|%10s||%10s|%10s|%10s|%10s\n", "Name", "Last Name", "Age", "Dept P", "Project", "CPU", "Memory", " ");
	fprintf(f, "   |%10s|%10s|%10s|%10s||%10s|%10s|%10s|%10s\n", " ", " ", " ", " M", "Project", "Customer", "Progers", " ");
	fprintf(f, "   |%10s|%10s|%10s|%10s||%10s|%10s|%10s|%10s\n", " ", " ", " ", " S", "Address", "Customer", "Weight", "Transport");
	fprintf(f, "--------------------------------------------------------------------------------------------\n");
	while (tmp && i < size) { //got to our element
		fprintf(f, "%3d", i++);
		fprintf(f, "%10s  %10s %10d", tmp->card.Name, tmp->card.LastName, tmp->card.age);
		switch (tmp->card.dept_type) {
		case DEPT_PROGRAMMERS:
			fprintf(f, "%10s", "Prog-s");
			fprintf(f, "%10s %10s %10d", tmp->card.task.p_task.Project, tmp->card.task.p_task.CPU, tmp->card.task.p_task.Memory);
			break;
		case DEPT_MANAGEMENT:
			fprintf(f, "%10s", "Mng");
			fprintf(f, "%10s %10s %10d", tmp->card.task.m_task.Project, tmp->card.task.m_task.Customer, tmp->card.task.m_task.ProgrammersNum);
			break;
		case DEPT_SHIPPING:
			fprintf(f, "%10s", "Ship");
			fprintf(f, "%10s %10s %10d", tmp->card.task.s_task.Address, tmp->card.task.s_task.Customer, tmp->card.task.s_task.Weight);
			switch (tmp->card.task.s_task.tr_type) {
			case TRANSP_TRAIN:
				fprintf(f, "%10s", "Train");
				break;
			case TRANSP_AUTO:
				fprintf(f, "%10s", "Auto");
				break;
			case TRANSP_AERO:
				fprintf(f, "%10s", "Plane");
				break;
			case TRANSP_SHIP:
				fprintf(f, "%10s", "Ship");
				break;
			}
			break;
		}
		tmp = tmp->next;
		fprintf(f, "\n");
	}
	fclose(f);
	free(tmp);
	printf("\nYour list was copied to Out.txt");
}
void list::remove() {
	int num;
	printf("Which element would you like to delete (enter index): ");
	(void)scanf("%d", &num);
	int i = 0;
	Node* tmp = this->head;

	while (tmp && i < num) { //got to our element
		tmp = tmp->next;
		i++;
	}
	if (tmp->prev) {
		tmp->prev->next = tmp->next;
	}
	if (tmp->next) {
		tmp->next->prev = tmp->prev;
	}
	if (!tmp->prev) {
		this->head = tmp->next;
	}
	if (!tmp->next) {
		this->tail = tmp->prev;
	}
	free(tmp);
	this->size--;
}