#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

enum Department {
	DEPT_PROGRAMMERS = 0,
	DEPT_MANAGEMENT = 1,
	DEPT_SHIPPING = 2
};
enum Transport {
	TRANSP_TRAIN = 0,
	TRANSP_AUTO = 1,
	TRANSP_AERO = 2,
	TRANSP_SHIP = 3
};

/*enum Department dept_type;
union {
	ProgTask p_task;
	ManagerTask m_task;
	ShipTask s_task;
};

struct ProgTask {
	char* Project;
	char* CPU;
	int Memory;
	ProgTask();
	ProgTask(char*, char*, int);
};
struct ManagerTask {
	char* Project;
	char* Customer;
	int ProgrammersNum;
	ManagerTask();
	ManagerTask(char*, char*, int);
};
struct ShipTask {
	char* Address;
	char* Customer;
	int Weight;
	Transport tr_type;
	ShipTask();
	ShipTask(char*, char*, int, char*);
};*/

struct CardMain {
	int index;
	char* Name;
	char* LastName;
	int age;
	//Department dept_type;
	//Transport tr_type;
	CardMain();
	CardMain(const CardMain& _card);
	void print();
};



struct Node {
	CardMain card;
	Node* next;
	Node* prev;
};

struct list {
	Node* head;
	Node* tail;
	int size;
	list();
	void push_back(CardMain);
	void remove();
	bool isEmpty();
	void print();
	void fprint();
};

list* init();


CardMain input();
//void print(Card card);
//void print1(list<Card> database1);
//void print_db(Card card, FILE* f);
//void print_db1(list<Card> database1);
//void remove(list<Card> &db1);
//list<Card> read_from_file();
//list<Card> read_from_file1();
//Card parse(char* str);
//char* parse1(char* str);