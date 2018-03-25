

#include "common.h"
#include "dlist.h"
#include "screenOut.h"
#include "SystemFunc.h"
#include "Customer.h"



int CustomerSystem(DList *Customer_list,DList *Video_list )
{
    int input_num,system_sel;
   
		system("cls");
	
    while(1)
    {
    CustomerMenu();
	scanf("%d",&system_sel);
		 
    	switch(system_sel)
		{
		case 1:
        	ShowVideoAllInfo(Video_list);
        	printf("대여하실 비디오의 번호를 입력해 주세요(-1입력시 종료) :");
        	scanf("%d", &input_num);
        	fflush(stdin);
  			Rent_Video(Video_list,input_num);
  			break;
  		
  		case 2:
  			find_Video(Video_list);
  			break;
  		break;	
  		case 3:
  			Return_Video(Video_list);
  			break;
  		}
  		if(system_sel==0) break;
	}
    return 0;

}

/* end of file */
