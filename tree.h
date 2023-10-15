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

typedef struct trnode {
	Item item;
	struct trnode* left;
	struct trnode* right;
}Trnode;

typedef struct tree {
	Trnode* root;
	int size;
}Tree;

/* ����ԭ�� */

/* ������			������ʼ��Ϊ�� */
/* ǰ��������		ptreeָ��һ���� */
/* ����������		������ʼ��Ϊ�� */
void InitializeTree(Tree* prtee);

/* ������			ȷ�����Ƿ�Ϊ�� */
/* ǰ��������		ptreeָ��һ���� */
/* ����������		�����Ϊ�գ��ú�������true */
/*						���򣬷���false */
bool TreeIsEmpty(const Tree* ptree);