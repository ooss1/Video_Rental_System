#include "dlist.h"
#include "common.h"
#include "Customer.h"
#include "Video.h"

int main(void){
	system("mode con cols=140  lines=40");
	int end_check=1;
	int main_menu=-1;
	DListElmt *element;
	
	DList Customer_list,Video_list;
	
	//리스트 초기화 
	dlist_init(&Customer_list,free);
    dlist_init(&Video_list,free);
    
    	
	//폴더 생성 및 리스트 불러오기 
	Make_dir();
	Customer_list_open(&Customer_list);
	Video_list_open(&Video_list);
	

  while(main_menu==-1){
   main_menu=Login(&Customer_list);
}
    
	while(end_check!=0){
		switch(main_menu){
		case 1:
		end_check=admirSystem(&Customer_list,&Video_list);
		break;
		case 2: 
		end_check=CustomerSystem(&Customer_list,&Video_list);
		break;
		default: break;
		}
	}
	Customer_list_close(&Customer_list);
	Video_list_close(&Video_list);
	
	dlist_destroy(&Customer_list);
	dlist_destroy(&Video_list);
	return 0;
		
}


