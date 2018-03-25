
#include "common.h"
#include "Customer.h"
#include "screenOut.h"
#include "SystemFunc.h"
#include "dlist.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define LIST_NUM   100

DListElmt *Login_id;

int Find_id(DList *list,char *temp){
	DListElmt *element1,*element2;
	Customer *data1,*data2;
	int find,i;
	int loop;
	element1=dlist_head(list);  //맨앞 
	element2=dlist_tail(list);  //맨뒤
	
	if(dlist_size(list)%2==0) loop = dlist_size(list)/2;
	else loop = dlist_size(list)/2+1;
	
		for(i=0;i<loop;i++){//서치 부분. 
			data1 = dlist_data(element1);
			data2 = dlist_data(element2);
			find=find_SameWord(data1->id,temp,1);
			
			if(find==1) { Login_id = element1; return 0;}
			find=find_SameWord(data2->id,temp,1);	
			
			if(find==1) { Login_id = element2;  return 0;}
			element1=dlist_next(element1);
			element2=dlist_prev(element2);
	}
	return 1;
}
		 
void 	Customer_list_close(DList *Customer_list){
	FILE *Customer_listFile;
	Customer *data;
	DListElmt *element;
	element = dlist_head(Customer_list);
	int i;
	
	if((Customer_listFile = fopen("list_info\\Customer_list.txt","r+"))==NULL) 
		if((Customer_listFile = fopen("list_info\\Customer_list.txt","w+"))==NULL) {
			printf("고객정보 리스트 열기 실패\n ");
		}
		
	for(i=0;i<dlist_size(Customer_list);i++){
		data = dlist_data(element);
		fprintf(Customer_listFile,"%s %d %s %s %s %s\n",data->name ,data->age,data->phone_num,data->id,data->password,data->Rent_Video);
		element = dlist_next(element);	
	}
	fclose(Customer_listFile);
}
void 	Customer_list_open(DList *Customer_list){
	
	int temp_age,count;
	int number =0;
	char temp_name[20],temp_phonenumber[20],temp_id[20],temp_password[20],temp_Rent_Video[20];
	
	
	FILE *Customer_listFile;	
	Customer *input_data;
	DListElmt *element;
	element = dlist_head(Customer_list);
	
	
	if((Customer_listFile = fopen("list_info\\Customer_list.txt","r+"))==NULL) 
		if((Customer_listFile = fopen("list_info\\Customer_list.txt","w+"))==NULL) {
			printf("고객정보 리스트 열기 실패\n ");
		}
		
	while(0==feof( Customer_listFile )){
		
		if((input_data=(Customer *)malloc(sizeof(Customer)))==NULL) return;
		count = fscanf(Customer_listFile,"%s %d %s %s %s %s",temp_name, &temp_age,temp_phonenumber,temp_id,temp_password,temp_Rent_Video );
		if(count == EOF) {free(input_data); break;}
		if((input_data->name=(char *)malloc(strlen(temp_name)+1))==NULL) return;
		strcpy(input_data->name,temp_name);
		if((input_data->phone_num=(char *)malloc(strlen(temp_phonenumber)+1))==NULL) return;
		strcpy(input_data->phone_num,temp_phonenumber);
		input_data->age =temp_age;
		if((input_data->id=(char *)malloc(strlen(temp_id)+1))==NULL) return;
		strcpy(input_data->id,temp_id);
		if((input_data->password=(char *)malloc(strlen(temp_password)+1))==NULL) return;
		strcpy(input_data->password,temp_password);
		if((input_data->Rent_Video=(char *)malloc(strlen(temp_Rent_Video)+1))==NULL) return;
		strcpy(input_data->Rent_Video,temp_Rent_Video);
		input_data->age =temp_age;
		input_data->number = number;
		number++;
		Customer_list->number++;
		dlist_ins_next(Customer_list,dlist_tail(Customer_list),input_data);
	}
	fclose(Customer_listFile);
}
void CustomerList_sort(DList *list){
	int i=0,j=0;
	int temp;
	DListElmt *element1;
	DListElmt *element2;
	Customer *data1,*data2;
	
//	element1 = dlist_head(list);
//	element2 = dlist_next(element1);
	
	
	for(i=0;i<dlist_size(list);i++){
		element1 = dlist_head(list);
		element2 = dlist_next(element1);
	
		for(j=0;j<dlist_size(list)-1;j++){
			data1 = dlist_data(element1);
			data2 = dlist_data(element2);
			if(data1->number>data2->number){
				temp = data1->number;
				data1->number = data2->number;
				data2->number = temp;
			}
		element1 = element2;
		element2 = dlist_next(element1);
			
		}
	}
}

void cp_CustomerData(Customer *data1,Customer *data2)
{
	data1->age = data2->age;
	data1->name = data2->name;
	data1->number = data2->number;
	data1->phone_num = data2->phone_num;
	data1->password = data2->password;
	data1->id = data2->id;
	data1->Rent_Video = data2->Rent_Video;
}
DList* Customer_searchMethod(DList *list,int method){
	DListElmt *element1,*element2;
	Customer *data1,*data2;
	Customer *copy_data; 
	char temp[20];
	int find,i;
	int loop;
	static	DList find_infoList;
	
	dlist_init(&find_infoList,NULL);
	
	element1=dlist_head(list);  //맨앞 
	element2=dlist_tail(list);  //맨뒤
	if(dlist_size(list)%2==0) loop = dlist_size(list)/2;
	else loop = dlist_size(list)/2+1;
	switch(method){
		case 1:	//이름으로 찾기 
			printf("찾으실 성함:");
			gets(temp);
	 		for(i=0;i<loop;i++){//서치 부분. 
				data1 = dlist_data(element1);
				data2 = dlist_data(element2);
				find=find_SameWord(data1->name,temp,0);
				//찾으면 정보 리스트에 입력. 
				if(find==1){
					if((copy_data = (Customer *)malloc(sizeof(Customer)))==NULL) return;
					cp_CustomerData(copy_data,data1);
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				find=find_SameWord(data2->name,temp,0);
		
				if(find==1){
					if((copy_data = (Customer *)malloc(sizeof(Customer)))==NULL) return;
					cp_CustomerData(copy_data,data2);
					if(copy_data->number!=data1->number)
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				element1=dlist_next(element1);
				element2=dlist_prev(element2);
			}
			CustomerList_sort(&find_infoList);
			if(dlist_size(&find_infoList)!=0) ShowCustomerAllInfo(&find_infoList);
			else print_empty_list();
			getchar();
			return &find_infoList;
		break; 
	case 2:
		printf("휴대폰 번호를 입력하시오.\n");
		gets(temp);	
		 	for(i=0;i<loop;i++){//서치 부분. 	
				data1 = dlist_data(element1);
				data2 = dlist_data(element2);
				find=find_SameWord(data1->phone_num,temp,0);
				printf("find = %d\n",find);
				//찾으면 정보 출력. 
				if(find==1){
				
					if((copy_data = (Customer *)malloc(sizeof(Customer)))==NULL) return;
					cp_CustomerData(copy_data,data1);
					if(copy_data->number!=data1->number)
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				find=find_SameWord(data2->phone_num,temp,0);
				
				//찾으면 정보 출력. 
				if(find==1){
				
					if((copy_data = (Customer *)malloc(sizeof(Customer)))==NULL) return;
					cp_CustomerData(copy_data,data2);
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				element1=dlist_next(element1);
				element2=dlist_prev(element2);
			}
			CustomerList_sort(&find_infoList);
			if(dlist_size(&find_infoList)!=0) ShowCustomerAllInfo(&find_infoList);
			else print_empty_list();
			getchar();
			return &find_infoList;
		break; 
	}
}
//CustomerSearchMethod
DList* find_Customer(DList *list){
	int input_data,Is_list_empty;
	DList *find_list;
		system("cls");
		//리스트가 비어있는지 확인 
		Is_list_empty=check_list_empty(list);
		if(Is_list_empty==1) return;
		
		//어떤 방식으로 찾을지  
		input_data =Select_searchMethod(CUSTOM);
		//서치 시 작 
		find_list = Customer_searchMethod(list,input_data); 
		
		if(find_list==NULL)	{		dlist_destroy(find_list); return 0;}	
		return find_list;

}

Customer* ins_Customer_data(DList *list)
{
	system("cls"); 
	char temp[20];
	int check_id=1;
	static Customer *data;
	DListElmt *element;
	element = dlist_tail(list);
	
	fflush(stdin);

	if((data=(Customer *)malloc(sizeof(Customer)))==NULL) return;
	printf("이름:");
	gets(temp);
 	if((data->name=(char *)malloc(strlen(temp)+1))==NULL) return;
 	strcpy(data->name,temp);
 	printf("나이 :");
 	scanf("%d",&data->age);
 	fflush(stdin);
 	
 	printf("핸드폰 번호:");
	gets(temp);
 	if((data->phone_num=(char *)malloc(strlen(temp)+1))==NULL) return;
 	strcpy(data->phone_num,temp);
 	
 	do{
 	if(check_id==0) printf("중복된 id입니다. 다시 입력해 주세요!\n");
 	printf("id:");
	gets(temp);
	check_id = Find_id(list,temp);
	}while(check_id!=1);	
	
 	if((data->id=(char *)malloc(strlen(temp)+1))==NULL) return;
 	strcpy(data->id,temp);
 	
 	printf("password:");
	gets(temp);
 	if((data->password=(char *)malloc(strlen(temp)+1))==NULL) return;
 	strcpy(data->password,temp);
 	if((data->Rent_Video=(char *)malloc(strlen("X")+1))==NULL) return;
 	strcpy(data->Rent_Video,"X");
 	data->number=list->number;
 	
 	return data;
}
void fix_Customer(DList *list){
	DListElmt *element1,*element2;
	DList *find_list;
	Customer *input_data,*temp_data;
	int input_number;
	char ch;
			element1 = dlist_head(list);
			element2 = dlist_tail(list);
			find_list = find_Customer(list);
			if(find_list==NULL||dlist_size(list)==0) return; 
			 fflush(stdin);
			printf("수정하시겠습니까?\n");
			printf("'Y'' 이외의 값을 입력시 초기화면으로 돌아갑니다\n");
			ch=getch(ch);
			if(ch=='Y'||ch=='y'){
			printf("\n수정할곳의  번호를 입력하시오 : ");
			scanf("%d",&input_number);
			while(1){
			
				temp_data = dlist_data(element1);
				if(temp_data->number ==input_number) break;
				temp_data = dlist_data(element2);
				if(temp_data->number ==input_number) break;
				
				element1 = dlist_next(element1);
				element2 = dlist_prev(element2);
			} 
			input_data = ins_Customer_data(list);
			temp_data->name = input_data->name;
			temp_data->age = input_data->age;
			temp_data->phone_num = input_data->phone_num;
	}
		dlist_destroy(find_list);
}
void del_Customer(DList *list){
	DListElmt *element1,*element2;
	DList *find_list;
	Customer *input_data,*temp_data;
	int input_number;
	char ch;
			element1 = dlist_head(list);
			element2 = dlist_tail(list);
			find_list = find_Customer(list);
			if(find_list==NULL||dlist_size(list)==0) return; 
			 fflush(stdin);
			printf("삭제 하시겠습니까??\n");
			printf("'Y'' 이외의 값을 입력시 초기화면으로 돌아갑니다\n");
			ch=getch(ch);
			if(ch=='Y'||ch=='y'){
			printf("\n삭제할곳의 번호를 입력하시오 : ");
			scanf("%d",&input_number);
			while(1){
			
				temp_data = dlist_data(element1);
				if(temp_data->number ==input_number) {
					dlist_remove(list,element1,(void **)&temp_data);
					dlist_destroy(find_list);
					break;
				}
				temp_data = dlist_data(element2);
				if(temp_data->number ==input_number){
					dlist_remove(list,element2,(void **)&temp_data);
					dlist_destroy(find_list);
				break;
				}
				
				element1 = dlist_next(element1);
				element2 = dlist_prev(element2);
			}
	}
	
}
void Customer_menu(DList *list,int ins_menu){
	Customer *input_data,*temp_data;
	DListElmt *element;
	char ch;
	switch(ins_menu){
		case 0: break;
		case 1:
			input_data=ins_Customer_data(list);
			dlist_ins_next(list,dlist_tail(list),input_data);
			list->number++;
			break;
		case 2:
			printf("데이터를 찾습니다.\n");
			Sleep(700);
			find_Customer(list);
			break;
		case 3:	
			printf("수정할 데이터를 찾습니다.\n");
			Sleep(700);
			fix_Customer(list);
			break;
		case 4:
			printf("삭제할 데이터를 찾습니다.\n");
			Sleep(700);
			del_Customer(list);
			break;
		case 5:
			ShowCustomerAllInfo(list);
			getchar(); 
			break;
		default:
			break;
	}
}
