/* Name: main.c  ver 1.0
 * Content: main ÇÔ¼ö.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "dlist.h"
#include "screenOut.h"
#include "SystemFunc.h"
#include "Customer.h"



int admirSystem(DList *Customer_list,DList *Video_list )
{
    int inputMenu,system_sel;
   
   	while(1){
	
    SystemMenu();
	scanf("%d",&system_sel);
	if(system_sel==0) return 0;
	    while(1)
	    {
	    	switch(system_sel)
			{
			case 1:
				system("cls"); 
				printf("				Customer managemenet System\n");
	        	ShowMenu_Customer();
	        	scanf("%d", &inputMenu);
	        	fflush(stdin);
	  			Customer_menu(Customer_list,inputMenu);
	  			break;
	  		case 2:
	  			system("cls"); 
	  			printf("				Video managemenet System\n");
	  			ShowMenu_Video();
	  			scanf("%d", &inputMenu);
	        	fflush(stdin);
	  			Video_menu(Video_list,inputMenu);
	  			break;
	  		}
	  		if(inputMenu==0||system_sel<1||system_sel>2) break;
	    }
	}

    return 0;

}

/* end of file */
