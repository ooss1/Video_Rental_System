

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "Customer.h"
#include "Video.h"
#include "dlist.h"

// �� ����
void ShowMenu_Customer(void);
void ShowCustomerAllInfo(DList *list);
void print_CustomerData(Customer *data);
void print_CustomerSearchMethod(void);
//���� ����
void ShowMenu_Video(void);
void ShowVideoAllInfo(DList *list);
void print_videoData(Video *data);
void print_VideoSearchMethod(void);
//�ý��� ����
void SystemMenu(void);
void print_empty_list(void);

#endif

/* end of file */
