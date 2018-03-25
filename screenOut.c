/* Name: screenOut.c  ver 1.0
 * Content: �ܼ� ����� ���� �Լ� ����
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "Customer.h"
#include "Video.h"
#include "dlist.h"
/* ��    ��: void ShowMenu(void)
 * ��    ��: ������ ���� �޴� ���. 
 * ��    ȯ: void.
 *
 */
 
 //������
 
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
		printf("1.insert information...\n"); //���� 
		printf("2.find information...\n");; //���� 
		printf("3.fix information... \n"); //���� 
		printf("4.delete informaiton...\n"); // ���� 
		printf("5.print all information...\n"); //���� 
		printf("0.exit...\n");
		printf("insert menu:");
}

void ShowMenu_Video(void)
{
  	  //stdlib.h
   	printf("--------------------------------------------------------------------------------------------------\n");
		printf("1.insert information...\n"); //���� 
		printf("2.find information...\n");; //���� 
		printf("3.fix information... \n"); //���� 
		printf("4.delete informaiton...\n"); // ���� 
		printf("5.print all information...\n"); //���� 
		printf("0.exit...\n");
		printf("insert menu:");
}


void print_CustomerData(Customer *data){
	printf("---------------------------------------------------------------------\n");
	printf("�̸� : %5s  ���� : %5d  �޴�����ȣ : %10s \n",data->name,data->age,data->phone_num);
	printf("���� �Ϸ��� �ƹ�Ű�� �����ÿ�.\n");
}

 void ShowCustomerAllInfo(DList *list){
 	int i;
	DListElmt *element;
	Customer *data;
	element = dlist_head(list);
	system("cls");
	printf("number		  �̸�		����		  �޴�����ȣ			   ��������		      id		  password\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<dlist_size(list);i++){
		data = dlist_data(element);
		printf("%03d\t\t %5s\t\t %d\t\t %10s\t\t %15s\t\t %10s\t\t %10s\n",data->number,data->name,data->age,data->phone_num,data->Rent_Video,data->id,data->password);
		element = dlist_next(element);
	}
	printf("���� �Ϸ��� �ƹ�Ű�� �����ÿ�.\n");
}

void print_CustomerSearchMethod(void){
		printf("ã���� ����� �����Ͻÿ�.\n");
		printf("1.�̸����� ã�� \n");
		printf("2.�޴��� ��ȣ�� ã�� \n");
		return;
}
void print_VideoSearchMethod(void){
		printf("ã���� ����� �����Ͻÿ�.\n");
		printf("1.�̸����� ã�� \n");
		printf("2.Ű����� ã�� \n");
		printf("3.�帣�� ã��\n");
		return;
}
 
 
 //��������
 void print_videoData(Video *data){
	printf("---------------------------------------------------------------------\n");
	printf("�̸� : %5s  �帣 : %5s  Ű���� : %10s \n",data->name,change_kind(data),data->key_word);
	printf("���� �Ϸ��� �ƹ�Ű�� �����ÿ�.\n");
	getchar();
}

 void ShowVideoAllInfo(DList *list){
 	int i;
	DListElmt *element;
	Video *data;
	element = dlist_head(list);
	system("cls");
	printf("number		      �̸�		      ����		    Ű����		�뿩���ɿ���		\n");
	printf("------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<dlist_size(list);i++){
		data = dlist_data(element);
	//	printf("%d %s %s %s %d",data->number,data->name,change_kind(data->kind),data->key_word,data->able_rental);
		printf("%5d %20s\t\t %10s %20s\t\t %5s \n",data->number,data->name,change_kind(data->kind),data->key_word,change_able_rental(data->able_rental));
		element = dlist_next(element);
	}
	printf("------------------------------------------------------------------------------------------------------\n");
}


 //�ý��۰���
void print_MainSystem(){
		printf("�����Ͻ� �ý����� ��� �ּ���.\n");
		printf("1. ������ 			2.����� \n");
		printf("�Է� :"); 
}
void SystemMenu(void){
	system("cls"); 
	printf("1.�� ���� �ý���.\n");
    printf("2.���� ���� �ý���.\n");
    printf("0.����\n");
    printf("------------------------------------------\n");
    printf("insert :");
}
void CustomerMenu(void){
	system("cls");
	printf("1.���� ������.\n");
	printf("2.���� ã��.\n");
	printf("3.���� �ݳ��ϱ�.\n"); 
	printf("0.����\n");
	printf("------------------------------------------\n");
	printf("insert :");
}
void print_empty_list(void){
			printf("��ϵ� �������� �����ϴ�.\n"); 
			printf("���� �Ϸ��� �ƹ�Ű�� �����ÿ�.\n");
			getchar(); 
			return;
}
/* ��    ��: void ShowPhoneInfo(phoneData phone)
 * ��    ��: �̸��� ��ȭ��ȣ ���� ���.
 * ��    ȯ: void.
 *
 */



	



/* end of file */
