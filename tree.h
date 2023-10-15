/* tree.h -- 二叉树找数 */
/* 树种不允许有重复的项 */
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

/* 根据具体情况重新定义Item */
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

/* 函数原型 */

/* 操作：			把树初始化为空 */
/* 前提条件：		ptree指向一个树 */
/* 后置条件：		树被初始化为空 */
void InitializeTree(Tree* prtee);

/* 操作：			确定树是否为空 */
/* 前提条件：		ptree指向一个树 */
/* 后置条件：		如果树为空，该函数返回true */
/*						否则，返回false */
bool TreeIsEmpty(const Tree* ptree);