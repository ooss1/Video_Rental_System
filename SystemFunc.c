#include "SystemFunc.h"	


#include "common.h"
#include "dlist.h"
#include "Customer.h"

extern DListElmt *Login_id;
int Login(DList *list){
	char temp[20];
	int is_id_right;
	Customer *temp_data;
	print_Login();
	printf("			ID : ");
	gets(temp);
	if((strcmp(temp,"admir"))==0)
	{
		printf("			Password: ");
		gets(temp);
		if((strcmp(temp,"오윤석"))==0) return 1; 
		else return -1;
	}
	
	is_id_right=Find_id(list,temp);
	
	if(is_id_right==1)
	{
		printf("			존재하지않는 아이디 입니다!!!\n");
		getch();
		return -1;
	}
		temp_data =dlist_data(Login_id);
		
		printf("			Password: ");
		gets(temp);
		if((strcmp(temp,temp_data->password))==0) {
			printf("--------------------------------------------------------------------------------------------------\n");
			printf("			              %s님 환영합니다.\n",temp_data->name);
			getch();
			return 2;
		} 
	printf("			잘못된 비밀번호 입니다. 다시 시도해주세요.\n");
	getch();
	return -1;	 
	
}
void Make_dir(void){

	int nResult = mkdir( "list_info" );

	if( nResult == 0 )
	{
		printf( "폴더 생성 성공" );
	}
	else if( nResult == -1 )
	{
		perror( "폴더 생성 실패 - 폴더가 이미 있거나 부정확함\n" );
		printf( "errorno : %n", errno );
	}
	system("cls");
}
int find_SameWord(char *str1,char *str2,int is_all_same){
	int i,j;
	i=0;j=0;
	char *find=NULL;
	
	switch(is_all_same){
		case 0:find = strstr(str1,str2); break; //문자열 str1안에 str2가 있는지 확인. 있으면 그 위치를 반환. 
		case 1:
			if(strcmp(str1,str2)==0) {
				return 1;
			}
	}
	if(find==NULL) return 0;
	else return 1;
}
bool check_list_empty(DList *list){
		if(dlist_size(list)==0) {
		print_empty_list();
		return true;
	}
	return false;
}
int Select_searchMethod(int kind){
	int input_data;
	switch(kind)
	{
		case CUSTOM:
			print_CustomerSearchMethod();
			scanf("%d",&input_data);
			system("cls");
			fflush(stdin);
			return input_data;
			break;
		case VIDEO:
			print_VideoSearchMethod();
			scanf("%d",&input_data);
			system("cls");
			fflush(stdin);
			return input_data;
			break;
			
	}
}
