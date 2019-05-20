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
struct ProgTask {
	char* Project;
	char* CPU;
	int Memory;
	ProgTask();
	~ProgTask();
};
struct ManagerTask {
	char* Project;
	char* Customer;
	int ProgrammersNum;
	ManagerTask();
	~ManagerTask();
};
struct ShipTask {
	char* Address;
	char* Customer;
	int Weight;
	Transport tr_type;
	ShipTask();
	~ShipTask();
};

typedef union Task{
	ProgTask p_task;
	ManagerTask m_task;
	ShipTask s_task;
	Task();
	~Task();
};

struct CardMain {
	char* Name;
	char* LastName;
	int age;
	Department dept_type;
	Task task;
	CardMain(); //trivial default constructor
	//CardMain(const CardMain& _card); //trivial copy constructor
	~CardMain(); //trivial destrucror
	void print(); //print to console
};

void getSpec(CardMain& card);

struct Node {
	CardMain card;
	Node* next;
	Node* prev;
};

struct list {
	Node* head;
	Node* tail;
	int size;
	list(); //trivial default constructor
	void push_back(CardMain&); // push to the tail of the list
	void remove(); //delete a node
	bool isEmpty(); // check if the list is empty
	void print(); // print to console
	void fprint(); //print to file
	~list(); //trivial destructor
};

list* init();
CardMain* input();
void setProgSpec(CardMain&);
void setManSpec(CardMain&);
void setShipSpec(CardMain&);
list* read_from_file();