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

typedef