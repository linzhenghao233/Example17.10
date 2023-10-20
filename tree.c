/* tree.c -- ����֧�ֺ��� */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

/* �ֲ��������� */
typedef struct pair {
	Trnode* parent;
	Trnode* child;
}Pair;

/* �ֲ�������ԭ�� */
static Trnode* MakeNode(const Item* pi);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static void AddNode(Trnode* new_node, Trnode* root);
static void InOrder(const Trnode* root, void(*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Trnode** ptr);
static void DeleteAllNodes(Trnode* ptr);