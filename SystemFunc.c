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
		if((strcmp(temp,"������"))==0) return 1; 
		else return -1;
	}
	
	is_id_right=Find_id(list,temp);
	
	if(is_id_right==1)
	{
		printf("			���������ʴ� ���̵� �Դϴ�!!!\n");
		getch();
		return -1;
	}
		temp_data =dlist_data(Login_id);
		
		printf("			Password: ");
		gets(temp);
		if((strcmp(temp,temp_data->password))==0) {
			printf("--------------------------------------------------------------------------------------------------\n");
			printf("			              %s�� ȯ���մϴ�.\n",temp_data->name);
			getch();
			return 2;
		} 
	printf("			�߸��� ��й�ȣ �Դϴ�. �ٽ� �õ����ּ���.\n");
	getch();
	return -1;	 
	
}
void Make_dir(void){

	int nResult = mkdir( "list_info" );

	if( nResult == 0 )
	{
		printf( "���� ���� ����" );
	}
	else if( nResult == -1 )
	{
		perror( "���� ���� ���� - ������ �̹� �ְų� ����Ȯ��\n" );
		printf( "errorno : %n", errno );
	}
	system("cls");
}
int find_SameWord(char *str1,char *str2,int is_all_same){
	int i,j;
	i=0;j=0;
	char *find=NULL;
	
	switch(is_all_same){
		case 0:find = strstr(str1,str2); break; //���ڿ� str1�ȿ� str2�� �ִ��� Ȯ��. ������ �� ��ġ�� ��ȯ. 
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
