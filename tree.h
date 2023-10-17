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

/* ������			ȷ�����Ƿ����� */
/* ǰ��������		ptreeָ��һ���� */
/* ����������		�����Ϊ�գ��ú�������true */
/*						���򣬷���false */
bool TreeIsFull(const Tree* ptree);

/* ������			ȷ���������� */
/* ǰ��������		ptreeָ��һ���� */
/* ����������		������������ */
int TreeItemCount(const Tree* ptree);

/* ������			���������һ���� */
/* ǰ��������		pi�Ǵ������ĵ�ַ */
/*						ptreeָ��һ���ѳ�ʼ������ */
/* ����������		���������ӣ��ú��������������һ���� */
/*						������true�����򣬷���false */
bool AddItem(const Item* pi, Tree* ptree);

/* ������			�����в���һ���� */
/* ǰ��������		piָ��һ���� */
/*						ptreeָ��һ���ѳ�ʼ������ */
/* ����������		������������һ����ú�������true */
/*						���򣬷���false */
bool InTree(const Item* pi, const Tree* ptree);

/* ������			������ɾ��һ���� */
/* ǰ��������		pi��ɾ����ĵ�ַ */
/*						ptreeָ��һ���ѳ�ʼ������ */
/* ����������		��������гɹ�ɾ��һ����ú�������true */
/*						���򣬷���false */
bool DeleteItem(const Item* pi, Tree* ptree);

/* ������			�Ѻ���Ӧ�������е�ÿһ�� */
/* ǰ��������		ptreeָ��һ���� */
/*						pfunָ��һ������ */
/*						�ú�������һ��Item���͵Ĳ��������޷���ֵ */
/* ����������		pfunָ����������Ϊ���е�ÿһ��ִ��һ�� */
void Traverse(const Tree* ptree, void(*pfun)(Item item));

/* ������			ɾ�����е��������� */
/* ǰ��������		ptreeָ��һ���ѳ�ʼ������ */
/* ����������		��Ϊ�� */
void DeleteAll(Tree* ptree);

#endif
/*						������true�����򣬷���false */