

#include "common.h"
#include "Video.h"
#include "screenOut.h"
#include "SystemFunc.h"
#include "dlist.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
extern DListElmt *Login_id;
void 	Find_Return_Video(DList *list,char *Video_name){
	DListElmt *element1,*element2;
	Video *data1,*data2;
	Video *copy_data; 
	char temp[20];
	int find,i;
	int loop;
	int input_num;
	static	DList find_infoList;
	
	dlist_init(&find_infoList,NULL);
	
	element1=dlist_head(list);  //맨앞 
	element2=dlist_tail(list);  //맨뒤
	if(dlist_size(list)%2==0) loop = dlist_size(list)/2;
	else loop = dlist_size(list)/2+1;
	 		for(i=0;i<loop;i++){//서치 부분. 
				data1 = dlist_data(element1);
				data2 = dlist_data(element2);
				find=find_SameWord(data1->name,Video_name,0);
				if(find==1){
					if(data1->able_rental == N){
						data1->able_rental=Y;
						printf("반납성공 ! \n");
						getch();
						return;
					}  
				}
				find=find_SameWord(data2->name,Video_name,0);
		
					if(find==1){
					if(data2->able_rental == N){
						data2->able_rental=Y;
						printf("반납성공 ! \n");
						getch();
						return;
					}  
				}
				element1=dlist_next(element1);
				element2=dlist_prev(element2);
			}
		
}
void Return_Video(DList *list){
	Customer *temp_data;
	temp_data =dlist_data(Login_id);
	
	if((strcmp("X",temp_data->Rent_Video))==0){
		printf("대여한 비디오가 없습니다.\n");
		getch();
		return;
	}
	Find_Return_Video(list,temp_data->Rent_Video);
	strcpy(temp_data->Rent_Video,"X");
	
	
}

void Rent_Video(DList *list,int num){
	DListElmt *element1,*element2;
	Video *data1,*data2;
	Video *copy_data; 
	Customer *temp_data;
	char temp[20];
	int find,i;
	int loop;
	static	DList find_infoList;
	
	temp_data =dlist_data(Login_id);
	if(num==-1) return;
	if((strcmp("X",temp_data->Rent_Video))!=0) {
		printf("이미 대여한 비디오가 있습니다.!\n");
		getch();
		return;
	}
 
	element1=dlist_head(list);  //맨앞 
	element2=dlist_tail(list);  //맨뒤
	if(dlist_size(list)%2==0) loop = dlist_size(list)/2;
	else loop = dlist_size(list)/2+1;

	 		for(i=0;i<loop;i++){//서치 부분. 
				data1 = dlist_data(element1);
				data2 = dlist_data(element2);
				if(num == data1->number && data1->able_rental ==Y) {
					if((temp_data->Rent_Video=(char *)malloc(strlen(data1->name)+1))==NULL) return;
					strcpy(temp_data->Rent_Video,data1->name);
					data1->able_rental = N;
					return;
				}
				else if(num == data2->number && data2->able_rental ==Y) {	
					if((temp_data->Rent_Video=(char *)malloc(strlen(data2->name)+1))==NULL) return;
					strcpy(temp_data->Rent_Video,data2->name);
					data2->able_rental = N;
					return;
				}
				element1=dlist_next(element1);
				element2=dlist_prev(element2);
			}
	printf("이미 대여중이거나 잘못된 번호 입력 !!\n");
	getch();
	return;
}
void 	Video_list_close(DList *Video_list){
	FILE *Video_listFile;
	Video *data;
	DListElmt *element;
	element = dlist_head(Video_list);
	int i;
	
	if((Video_listFile = fopen("list_info\\Video_list.txt","r+"))==NULL) 
		if((Video_listFile = fopen("list_info\\Video_list.txt","w+"))==NULL) {
			printf("고객정보 리스트 열기 실패\n ");
		}
		
	for(i=0;i<dlist_size(Video_list);i++){
		data = dlist_data(element);
		fprintf(Video_listFile,"%s %d %s %d\n",data->name ,data->kind,data->key_word,data->able_rental);
		element = dlist_next(element);	
	}
	fclose(Video_listFile);
}

void 	Video_list_open(DList *Video_list){
	
	int temp_kind,count;
	int temp_rental_able;
	int number =0;
	char temp_name[20],temp_keyword[20];
	
	FILE *Video_listFile;	
	Video *input_data;
	DListElmt *element;
	element = dlist_head(Video_list);
	
	
	if((Video_listFile = fopen("list_info\\Video_list.txt","r+"))==NULL) 
		if((Video_listFile = fopen("list_info\\Video_list.txt","w+"))==NULL) {
			printf("비디오정보 리스트 열기 실패\n ");
		}
		
	while(!feof( Video_listFile )){
		
		if((input_data=(Video *)malloc(sizeof(Video)))==NULL) return;
		count = fscanf(Video_listFile,"%s %d %s %d",temp_name, &temp_kind,temp_keyword,&temp_rental_able );
		if(count == EOF) {free(input_data); break;}
		if((input_data->name=(char *)malloc(strlen(temp_name)+1))==NULL) return;
		strcpy(input_data->name,temp_name);
		if((input_data->key_word=(char *)malloc(strlen(temp_keyword)+1))==NULL) return;
		strcpy(input_data->key_word,temp_keyword);
		input_data->kind =temp_kind;
		input_data->number = number;
		input_data->able_rental = temp_rental_able;
		number++;
		Video_list->number++;
		dlist_ins_next(Video_list,dlist_tail(Video_list),input_data);
	}
	fclose(Video_listFile);
}

char* change_kind(int kind){
	switch(kind){
		case ACTION:
			return "ACTION";
		case DRAMA:
			return "DRAMA";
		case COMEDY:
			return "COMEDY";
		case SF:
			return "SF";
		case LOVE:
			return "LOVE";
	}
}

char* change_able_rental(int a){
	switch(a){
		case N:
			return "N";
		case Y:
			return "Y";
	}
}

void VideoList_sort(DList *list){
	int i=0,j=0;
	int temp;
	DListElmt *element1;
	DListElmt *element2;
	Video *data1,*data2;
	
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

void cp_VideoData(Video *data1,Video *data2)
{
	data1->key_word = data2->key_word;
	data1->name = data2->name;
	data1->number = data2->number;
	data1->kind = data2->kind;
	data1->able_rental = data2->able_rental;
	
}
DList* Video_searchMethod(DList *list,int method){
	DListElmt *element1,*element2;
	Video *data1,*data2;
	Video *copy_data; 
	char temp[20];
	int find,i;
	int loop;
	int input_num;
	static	DList find_infoList;
	
	dlist_init(&find_infoList,NULL);
	
	element1=dlist_head(list);  //맨앞 
	element2=dlist_tail(list);  //맨뒤
	if(dlist_size(list)%2==0) loop = dlist_size(list)/2;
	else loop = dlist_size(list)/2+1;
	switch(method){
		case 1:	//이름으로 찾기 
			printf("영화 이름:");
			gets(temp);
	 		for(i=0;i<loop;i++){//서치 부분. 
				data1 = dlist_data(element1);
				data2 = dlist_data(element2);
				find=find_SameWord(data1->name,temp,0);
				//찾으면 정보 리스트에 입력. 
				if(find==1){
					if((copy_data = (Video *)malloc(sizeof(Video)))==NULL) return;
					cp_VideoData(copy_data,data1);
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				find=find_SameWord(data2->name,temp,0);
		
				if(find==1){
					if((copy_data = (Video *)malloc(sizeof(Video)))==NULL) return;
					cp_VideoData(copy_data,data2);
					if(copy_data->number!=data1->number)
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				element1=dlist_next(element1);
				element2=dlist_prev(element2);
			}
			VideoList_sort(&find_infoList);
			if(dlist_size(&find_infoList)!=0) ShowVideoAllInfo(&find_infoList);
			else print_empty_list();
			getchar();
			return &find_infoList;
		break; 
	case 2:
		printf("Keyword를 입력하시오.\n");
		gets(temp);	
		 	for(i=0;i<loop;i++){//서치 부분. 
				data1 = dlist_data(element1);
				data2 = dlist_data(element2);
				find=find_SameWord(data1->key_word,temp,0);
				printf("find = %d\n",find);
				//찾으면 정보 출력. 
				if(find==1){
					if((copy_data = (Video *)malloc(sizeof(Video)))==NULL) return;
					cp_VideoData(copy_data,data1);
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				find=find_SameWord(data2->key_word,temp,0);
				
				//찾으면 정보 출력. 
				if(find==1){
				
					if((copy_data = (Video *)malloc(sizeof(Video)))==NULL) return;
					cp_VideoData(copy_data,data2);
					if(copy_data->number!=data1->number)
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				element1=dlist_next(element1);
				element2=dlist_prev(element2);
			}
			VideoList_sort(&find_infoList);
			if(dlist_size(&find_infoList)!=0) ShowVideoAllInfo(&find_infoList);
			else print_empty_list();
			getchar();
			return &find_infoList;
		break; 
	case 3:
		printf("장르를 입력하시오.\n");
		printf("1. ACTION 	2.DRAMA 	3.COMEDY 	4.SF 	5.LOVE\n");
		scanf("%d",&input_num);
		if(input_num<1||input_num>5) { printf("잘못된 입력. 다시 시도하시오.\n"); return NULL;} 
		
		 	for(i=0;i<loop;i++){//서치 부분. 
				data1 = dlist_data(element1);
				data2 = dlist_data(element2);
				//찾으면 정보 출력. 
				if(input_num == data1->kind){
					if((copy_data = (Video *)malloc(sizeof(Video)))==NULL) return;
					cp_VideoData(copy_data,data1);
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				//찾으면 정보 출력. 
				if(input_num == data2->kind){
					if((copy_data = (Video *)malloc(sizeof(Video)))==NULL) return;
					cp_VideoData(copy_data,data2);
					if(copy_data->number!=data1->number)
					dlist_ins_next(&find_infoList,dlist_tail(&find_infoList),copy_data); 
				}
				element1=dlist_next(element1);
				element2=dlist_prev(element2);
			}
			VideoList_sort(&find_infoList);
			if(dlist_size(&find_infoList)!=0) ShowVideoAllInfo(&find_infoList);
			else print_empty_list();
			fflush(stdin);
			getchar();
			return &find_infoList;
		break; 
	}
}
//VideoSearchMethod
DList* find_Video(DList *list){
	int input_data,Is_list_empty;
	DList *find_list;
		system("cls");
		//리스트가 비어있는지 확인 
		Is_list_empty=check_list_empty(list);
		if(Is_list_empty==1) return;
		
		//어떤 방식으로 찾을지  
		input_data =Select_searchMethod(VIDEO);
		//서치 시 작 
		find_list = Video_searchMethod(list,input_data); 
		
		if(find_list==NULL)	{
				dlist_destroy(find_list); return 0;
		}
		return find_list;

}

Video* ins_Video_data(DList *list)
{
	system("cls"); 
	char temp[100];
	static Video *data;
	DListElmt *element;
	element = dlist_tail(list);
	
	fflush(stdin);

	if((data=(Video *)malloc(sizeof(Video)))==NULL) return;
	printf("이름:");
	gets(temp);
 	if((data->name=(char *)malloc(strlen(temp)+1))==NULL) return;
 	strcpy(data->name,temp);
 	printf("1. ACTION 	2.DRAMA 	3.COMEDY 	4.SF 	5.LOVE\n");
 	printf("장르 :");
 	scanf("%d",&data->kind);
 	if(data->kind<1||data->kind>5) { printf("잘못된 입력. 처음부터 다시 시도하십시오.\n"); return NULL;} 
 	fflush(stdin);
 	
 	printf("키워드:");
	gets(temp);
 	if((data->key_word=(char *)malloc(strlen(temp)+1))==NULL) return;
 	strcpy(data->key_word,temp);
 	data->number=list->number;
 	data->able_rental=Y;
 	return data;
}
void fix_Video(DList *list){
	DListElmt *element1,*element2;
	DList *find_list;
	Video *input_data,*temp_data;
	int input_number;
	char ch;
			element1 = dlist_head(list);
			element2 = dlist_tail(list);
			find_list = find_Video(list);
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
			input_data = ins_Video_data(list);
			temp_data->name = input_data->name;
			temp_data->key_word = input_data->key_word;
			temp_data->kind = input_data->kind;
			temp_data->able_rental = input_data->able_rental;
	}
	dlist_destroy(find_list);
}
void del_Video(DList *list){
	DListElmt *element1,*element2;
	DList *find_list;
	Video *input_data,*temp_data;
	int input_number;
	char ch;
			element1 = dlist_head(list);
			element2 = dlist_tail(list);
			find_list = find_Video(list);
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
		dlist_destroy(find_list);
	}
}
void Video_menu(DList *list,int ins_menu){
	Video *input_data,*temp_data;
	DListElmt *element;
	char ch;
	switch(ins_menu){
		case 1:
			input_data=ins_Video_data(list);
			dlist_ins_next(list,dlist_tail(list),input_data);
			list->number++;
			break;
		case 2:
			printf("데이터를 찾습니다.\n");
			Sleep(700);
			find_Video(list);
			break;
		case 3:	
			printf("수정할 데이터를 찾습니다.\n");
			Sleep(700);
			fix_Video(list);
			break;
		case 4:
			printf("삭제할 데이터를 찾습니다.\n");
			Sleep(700);
			del_Video(list);
			break;
		case 5:
			ShowVideoAllInfo(list);
			getchar(); 
			break;
		default:
			break;
	}
}
