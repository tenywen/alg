/*******************************************
   
   
   				@ Black Tree
				@ int binary
				@ complete 
						

********************************************/
#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"

// 调整红黑属性
int _fixed(PBTreeHead head,PBTreeNode node) {
	PBTreeNode z = node;
	PBTreeNode parent = _BTREE_PARENT(node);
	PBTreeNode gparent = NULL; 
	PBTreeNode uncle = NULL;
	while(parent && _BTREE_COLOR(parent) == RED) {
		gparent = _BTREE_PARENT(parent);
		if (!gparent) 
			break;
		if(parent == _BTREE_LEFT(gparent))
			uncle = _BTREE_RIGHT(gparent);
		else 
			uncle = _BTREE_LEFT(gparent);
		// 节点z的叔叔节点为红色，此为情况1:
		// 将z的父节点和叔叔节点置为黑，z变更为祖父节点。重复while循环
		if(_BTREE_COLOR(uncle) == RED) {
			uncle->Color = BLACK;
			parent->Color = BLACK;
			gparent->Color = RED;
			z = gparent;
			parent = _BTREE_PARENT(z);
		} else {
			// 节点z的叔叔节点为黑色，此为情况2，3:
			if(z == _BTREE_RIGHT(parent)) {
				_LEFT_ROTATE(head,parent,z);
			}
			if(z == _BTREE_LEFT(gparent))
				_RIGHT_ROTATE(head,gparent,z);
			else 
				_LEFT_ROTATE(head,gparent,z);
			z->Color = BLACK;
			gparent->Color = RED;
		}
	}
	head->Next->Color = BLACK;
}

int BTreeNIL(PBTreeNode p) {
	PBTreeNode left = (PBTreeNode)malloc(sizeof(BTreeNode));
	PBTreeNode right = (PBTreeNode)malloc(sizeof(BTreeNode));
	if (!left || !right)
		return NULL;
	_INIT_BTREE_NODE(left);	
	_INIT_BTREE_NODE(right);	
	p->Left = left;
	p->Right = right;
	left->Parent = p;
	right->Parent = p;
	return 0; 
}

PBTreeNode BTreeCreateNode(int value) {
	PBTreeNode node = (PBTreeNode)malloc(sizeof(BTreeNode));
	if(!node)
		return NULL;
	_INIT_BTREE_NODE(node);
	node->Value = value;
	BTreeNIL(node);
	return node;
}

PBTreeHead BTreeNew() {
	PBTreeHead head = (PBTreeHead)malloc(sizeof(PBTreeHead));
	_INIT_BTREE_HEAD(head);
	return head;
}

int BTreeInsert(PBTreeHead head,PBTreeNode node) {
	PBTreeNode parent = NULL;
	PBTreeNode next = head->Next;
	if(!next) {
		head->Next = node;
		return 0;		
	}
	while(_IS_NIL(next) == false) {
		parent = next;
		if(_BTREE_VALUE(next) > _BTREE_VALUE(node))	
			next = _BTREE_LEFT(next);
		else 
			next = _BTREE_RIGHT(next);
	}
	if (parent) {
		if (_BTREE_VALUE(parent) > _BTREE_VALUE(node))
			parent->Left = node;
		else 
			parent->Right = node;
		node->Parent = parent;	
	} 	
	
	node->Color = RED;
	_fixed(head,node);
	free(next);
	return 0;
}

int BTreeMidTraverse(PBTreeNode node) {
	if (!node) 
		return 0;	
	BTreeMidTraverse(node->Left);
	if (_IS_NIL(node) == false) {
		printf("color : %d(1 = red,2 = black)\n",node->Color);
		printf("value : %d\n",node->Value);
	}
	BTreeMidTraverse(node->Right);
	return 0;	
}

int main() {
	PBTreeHead head = BTreeNew();
	PBTreeNode p1 = BTreeCreateNode(222);
	BTreeInsert(head,p1);
	BTreeMidTraverse(head->Next);
	PBTreeNode p2 = BTreeCreateNode(333);
	BTreeInsert(head,p2);
	
	BTreeMidTraverse(head->Next);
	PBTreeNode p3 = BTreeCreateNode(444);
	BTreeInsert(head,p3);

	BTreeMidTraverse(head->Next);
	PBTreeNode p4 = BTreeCreateNode(555);
	BTreeInsert(head,p4);

	BTreeMidTraverse(head->Next);
	return 0;
}
