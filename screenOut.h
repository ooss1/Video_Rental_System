/* Name: screenOut.h  ver 1.0
 * Content: 콘솔 출력을 위한 함수 선언
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "Customer.h"
#include "Video.h"
#include "dlist.h"

// 고객 관련
void ShowMenu_Customer(void);
void ShowCustomerAllInfo(DList *list);
void print_CustomerData(Customer *data);
void print_CustomerSearchMethod(void);
//비디오 관련
void ShowMenu_Video(void);
void ShowVideoAllInfo(DList *list);
void print_videoData(Video *data);
void print_VideoSearchMethod(void);
//시스템 관련
void SystemMenu(void);
void print_empty_list(void);

#endif

/* end of file */
