/* Name: phoneFunc.h  ver 1.0
 * Content: 전화번호 컨트롤 함수 선언.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#ifndef __SYSTEMFUNC_H__
#define __SYSTEMFUNC_H__
typedef enum {false, true} bool;

#include "Customer.h"
#include "Video.h"
#include "dlist.h"
enum {CUSTOM=1,VIDEO};



bool check_list_empty(DList *list);
int find_SameWord(char *str1,char *str2,int is_all_same);
int Select_searchMethod(int a);

#endif

/* end of file */
