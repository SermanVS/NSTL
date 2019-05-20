#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctype.h>

CardMain input() {
	static int count = 0;
	char* Name = (char*)malloc(sizeof(char) * 256);
	char* LastName = (char*)malloc(sizeof(char) * 256);
	int age;
	CardMain card;

	printf("Enter a name: ");
	(void)scanf("%s", Name);
	Name = (char*)realloc(Name, sizeof(char) * (strlen(Name) + 1));
	printf("Enter a last name: ");
	(void)scanf("%s", LastName);
	LastName = (char*)realloc(LastName, sizeof(char) * (strlen(LastName) + 1));
	printf("Enter an age: ");
	(void)scanf("%d", &age);
	card.age = age;
	card.Name = (char*)malloc(sizeof(char) * (strlen(Name) + 1));
	card.LastName = (char*)malloc(sizeof(char) * (strlen(LastName) + 1));
	strcpy(card.Name, Name);
	strcpy(card.LastName, LastName);
	free(Name);
	free(LastName);
	return card;
}

void CardMain::print() {
	printf("%10s %10s %10d", Name, LastName, age);
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

CardMain::CardMain(const CardMain& _card) {
	age = _card.age;
	index = _card.index;
	Name = (char*)malloc(sizeof(char) * (strlen(_card.Name) + 1));
	LastName = (char*)malloc(sizeof(char) * (strlen(_card.LastName) + 1));
	strcpy(Name, _card.Name);
	strcpy(LastName, _card.LastName);
}

list::list() {
	head = nullptr;
	tail = nullptr;
}

list* init() {
	list* lst;
	lst = (list*)malloc(sizeof(list));
	lst->size = 0;
	lst->head = nullptr;
	lst->tail = nullptr;
	return lst;
}

void list::push_back(CardMain _card) {
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

}

void list::remove() {
	int num;
	printf("Which element would you like to delete (enter index): ");
	scanf("%d", &num);
	int i = 0;
	Node* tmp = this->head;


	while (tmp && i < num) { //got to our element
		tmp = tmp->next;
		i++;
	}


}