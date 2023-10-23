/* tree.c -- 树的支持函数 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

/* 局部数据类型 */
typedef struct pair {
	Trnode* parent;
	Trnode* child;
}Pair;

/* 局部函数的原型 */
static Trnode* MakeNode(const Item* pi);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static void AddNode(Trnode* new_node, Trnode* root);
static void InOrder(const Trnode* root, void(*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Trnode** ptr);
static void DeleteAllNodes(Trnode* ptr);

/* 函数定义 */
void InitialzeTree(Tree* ptree) {
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree* ptree) {
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree* ptree) {
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree* ptree) {
	return ptree->size;
}

bool AddItem(const Item* pi, Tree* ptree) {
	Trnode* new_node;

	if (TreeIsFull(ptree)) {
		fprintf(stderr, "Tree is full\n");

		return false;
	}
	if (SeekItem(pi, ptree).child != NULL) {
		fprintf(stderr, "Attempted to add dupicate item\n");

		return false;
	}
	new_node = MakeNode(pi);	//指向新节点
	if (new_node == NULL) {
		fpintf(stderr, "Couldn't create node\n");
		
		return false;
	}
	/* 成功创建一个新节点 */
	ptree->size++;

	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);

	return true;
}

bool InTree(const Item* pi, const Tree* ptree) {
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item* pi, Tree* ptree) {
	Pair look;

	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;

	if (look.parent == NULL)	//删除根节点项
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

void Traverse(const Tree* ptree, void(*pfun)(Item item)) {
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree* ptree) {
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

/* 局部函数 */
static void InOrder(const Trnode* root, void(*pfun)(Item item)) {
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode* root) {
	Trnode* pright;

	if (root != NULL) {
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}