


#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__
#include "dlist.h"



typedef struct{
	char *name;
	char *phone_num;
	char *id;
	char *password;
	char *Rent_Video;
	
	int age;
	int number;	
}Customer;

void Customer_list_open(DList *Customer_list);
void Customer_list_close(DList *Customer_list);
void cp_CustomerData(Customer *data1,Customer *data2);
void CustomerList_sort(DList *list);
void Customer_menu(DList *list,int ins_menu);
void fix_Customer(DList *list);
void CustomerList_sort(DList *list);
void del_Customer(DList *list);

Customer* ins_Customer_data(DList *list);
DList* find_Customer(DList *list);
DList*  Customer_searchMethod(DList *list,int method);
int Find_id(DList *list,char *temp);
#endif
/* end of file */
