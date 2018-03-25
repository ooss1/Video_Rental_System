

#ifndef __Video_H__
#define __Video_H__

#include "dlist.h"

typedef struct{
	char *name;
	char *key_word;
	enum {ACTION=1,DRAMA,COMEDY,SF,LOVE} kind;
	enum {N=0,Y}able_rental;
	int number;		
}Video;
void Find_Return_Video(DList *list,char *Video_name);
void Return_Video(DList *list);
void Rent_Video(DList *list,int num);
void Video_list_close(DList *Video_list);
void Video_list_open(DList *Video_list);
void Video_menu(DList *list,int ins_menu);
void del_Video(DList *list);
void fix_Video(DList *list);
void cp_VideoData(Video *data1,Video *data2);
void VideoList_sort(DList *list);

DList* find_Video(DList *list);
DList* Video_searchMethod(DList *list,int method);
Video* ins_Video_data(DList *list);

#endif
/* end of file */
