/* Name: screenOut.c  ver 1.0
 * Content: 콘솔 출력을 위한 함수 정의
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "Customer.h"
#include "Video.h"
#include "dlist.h"
/* 함    수: void ShowMenu(void)
 * 기    능: 선택을 위한 메뉴 출력. 
 * 반    환: void.
 *
 */
 
 //고객관련
 
void print_Login(void)
{
	system("cls");
	printf("--------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------Login--------------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------\n");
}
 void ShowMenu_Customer(void)
{
    //stdlib.h
   	printf("--------------------------------------------------------------------------------------------------\n");
		printf("1.insert information...\n"); //햇음 
		printf("2.find information...\n");; //햇음 
		printf("3.fix information... \n"); //햇음 
		printf("4.delete informaiton...\n"); // 햇음 
		printf("5.print all information...\n"); //햇음 
		printf("0.exit...\n");
		printf("insert menu:");
}

void ShowMenu_Video(void)
{
  	  //stdlib.h
   	printf("--------------------------------------------------------------------------------------------------\n");
		printf("1.insert information...\n"); //햇음 
		printf("2.find information...\n");; //햇음 
		printf("3.fix information... \n"); //햇음 
		printf("4.delete informaiton...\n"); // 햇음 
		printf("5.print all information...\n"); //햇음 
		printf("0.exit...\n");
		printf("insert menu:");
}


void print_CustomerData(Customer *data){
	printf("---------------------------------------------------------------------\n");
	printf("이름 : %5s  나이 : %5d  휴대폰번호 : %10s \n",data->name,data->age,data->phone_num);
	printf("진행 하려면 아무키나 누르시오.\n");
}

 void ShowCustomerAllInfo(DList *list){
 	int i;
	DListElmt *element;
	Customer *data;
	element = dlist_head(list);
	system("cls");
	printf("number		  이름		나이		  휴대폰번호			   빌린비디오		      id		  password\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<dlist_size(list);i++){
		data = dlist_data(element);
		printf("%03d\t\t %5s\t\t %d\t\t %10s\t\t %15s\t\t %10s\t\t %10s\n",data->number,data->name,data->age,data->phone_num,data->Rent_Video,data->id,data->password);
		element = dlist_next(element);
	}
	printf("진행 하려면 아무키나 누르시오.\n");
}

void print_CustomerSearchMethod(void){
		printf("찾으실 방법을 선택하시오.\n");
		printf("1.이름으로 찾기 \n");
		printf("2.휴대폰 번호로 찾기 \n");
		return;
}
void print_VideoSearchMethod(void){
		printf("찾으실 방법을 선택하시오.\n");
		printf("1.이름으로 찾기 \n");
		printf("2.키워드로 찾기 \n");
		printf("3.장르로 찾기\n");
		return;
}
 
 
 //비디오관련
 void print_videoData(Video *data){
	printf("---------------------------------------------------------------------\n");
	printf("이름 : %5s  장르 : %5s  키워드 : %10s \n",data->name,change_kind(data),data->key_word);
	printf("진행 하려면 아무키나 누르시오.\n");
	getchar();
}

 void ShowVideoAllInfo(DList *list){
 	int i;
	DListElmt *element;
	Video *data;
	element = dlist_head(list);
	system("cls");
	printf("number		      이름		      종류		    키워드		대여가능여부		\n");
	printf("------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<dlist_size(list);i++){
		data = dlist_data(element);
	//	printf("%d %s %s %s %d",data->number,data->name,change_kind(data->kind),data->key_word,data->able_rental);
		printf("%5d %20s\t\t %10s %20s\t\t %5s \n",data->number,data->name,change_kind(data->kind),data->key_word,change_able_rental(data->able_rental));
		element = dlist_next(element);
	}
	printf("------------------------------------------------------------------------------------------------------\n");
}


 //시스템관련
void print_MainSystem(){
		printf("접속하실 시스템을 골라 주세요.\n");
		printf("1. 관리자 			2.사용자 \n");
		printf("입력 :"); 
}
void SystemMenu(void){
	system("cls"); 
	printf("1.고객 관리 시스템.\n");
    printf("2.비디오 관리 시스템.\n");
    printf("0.종료\n");
    printf("------------------------------------------\n");
    printf("insert :");
}
void CustomerMenu(void){
	system("cls");
	printf("1.비디오 빌리기.\n");
	printf("2.비디오 찾기.\n");
	printf("3.비디오 반납하기.\n"); 
	printf("0.종료\n");
	printf("------------------------------------------\n");
	printf("insert :");
}
void print_empty_list(void){
			printf("등록된 정보가가 없습니다.\n"); 
			printf("진행 하려면 아무키나 누르시오.\n");
			getchar(); 
			return;
}
/* 함    수: void ShowPhoneInfo(phoneData phone)
 * 기    능: 이름과 전화번호 정보 출력.
 * 반    환: void.
 *
 */



	



/* end of file */
