/* tree.h -- ���������� */
/* ���ֲ��������ظ����� */
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

/* ���ݾ���������¶���Item */
#define SLEN 20
typedef struct item {
	char petname[SLEN];
	char petkind[SLEN];
}Item;

#define MAXITEMS 10

typedef