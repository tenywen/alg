/*******************************************
   
   
   				@ Black Tree
				@ int binary
				@ complete 
						

********************************************/
#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"

extern PBTreeNode NIL;
// 调整红黑属性
int _insert_fixed(PBTreeHead head,PBTreeNode z) {
	PBTreeNode uncle = NULL;
	while(_BTREE_PARENT(z) && _BTREE_COLOR((_BTREE_PARENT(z))) == RED) {
		if (!(_BTREE_PARENT(_BTREE_PARENT(z)))) 
			break;
		if(_BTREE_PARENT(z) == _BTREE_LEFT(_BTREE_PARENT(_BTREE_PARENT(z))))
			uncle = _BTREE_RIGHT(_BTREE_PARENT(_BTREE_PARENT(z)));
		else 
			uncle = _BTREE_LEFT(_BTREE_PARENT(_BTREE_PARENT(z)));
		// 节点z的叔叔节点为红色，此为情况1:
		// 将z的父节点和叔叔节点置为黑，z变更为祖父节点。重复while循环
		if(_BTREE_COLOR(uncle) == RED) {
			uncle->Color = BLACK;
			_BTREE_PARENT(z)->Color = BLACK;
			_BTREE_PARENT(_BTREE_PARENT(z))->Color = RED;
			z = _BTREE_PARENT(_BTREE_PARENT(z));
		} else {
			// 节点z的叔叔节点为黑色，此为情况2，3:
			if(z == _BTREE_RIGHT(_BTREE_PARENT(z))) {
				// z上升一层
				z = _BTREE_PARENT(z);	
				_LEFT_ROTATE(head,z);
			}
			_BTREE_PARENT(z)->Color = BLACK;
			_BTREE_PARENT(_BTREE_PARENT(z))->Color = RED;
			if(_BTREE_PARENT(z) == _BTREE_LEFT(_BTREE_PARENT(_BTREE_PARENT(z))))
				_RIGHT_ROTATE(head,_BTREE_PARENT(_BTREE_PARENT(z)));
			else 
				_LEFT_ROTATE(head,_BTREE_PARENT(_BTREE_PARENT(z)));
		}
	}
	head->Next->Color = BLACK;
}

// return min node when root is node
PBTreeNode BTreeMin(PBTreeNode node) {
	PBTreeNode left = _BTREE_LEFT(node);
	PBTreeNode min = node;
	while(left && !_IS_NIL(left)) {
		min = left;
		left = _BTREE_LEFT(left);
	}
	return min;
}

// return node succeed
PBTreeNode BTreeSucceed(PBTreeNode node) {
	PBTreeNode right = _BTREE_RIGHT(node);
	PBTreeNode next = node;
	PBTreeNode parent = _BTREE_PARENT(node);
	if (right && !_IS_NIL(right)) {
		return BTreeMin(right);	
	}
	while(parent && next == _BTREE_RIGHT(parent)) { 
		next = parent;
		parent = _BTREE_PARENT(next);	
	}
	return parent;
}
/*
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
*/

PBTreeHead BTreeNew() {
	PBTreeHead head = (PBTreeHead)malloc(sizeof(PBTreeHead));
	head->Next = NIL;
	return head;
}

int BTreeInsert(PBTreeHead head,PBTreeNode node) {
	PBTreeNode next = head->Next;
	PBTreeNode y = NIL;
	while(next != NIL) {
		y = next;
		if(_BTREE_VALUE(next) > _BTREE_VALUE(node))	
			next = _BTREE_LEFT(next);
		else
			next = _BTREE_RIGHT(next);
	}
	if(y != NIL) {
		if(_BTREE_VALUE(y) > _BTREE_VALUE(node))	
			y->Left = node;
		else
			y->Right = node;
		node->Parent = y;
	} else {
		head->Next = node;		
	}
	node->Left = NULL;
	node->Right = NULL;
	node->Color = RED;
	_insert_fixed(head,node);
	return 0;
}

int BTreeMidTraverse(PBTreeNode node) {
	if (node == NIL) 
		return 0;
	BTreeMidTraverse(node->Left);
	if (node != NIL) {
		printf("color : %d(1 = red,2 = black)\n",node->Color);
		printf("value : %d\n",node->Value);
	}
	BTreeMidTraverse(node->Right);
	return 0;	
}

int main() {
	PBTreeHead head = BTreeNew();
	PBTreeNode p1 = (PBTreeNode)malloc(sizeof(PBTreeNode));
	p1->Value = 555;
	BTreeInsert(head,p1);
	
	PBTreeNode p2 = (PBTreeNode)malloc(sizeof(PBTreeNode));
	p2->Value = 444;
	BTreeInsert(head,p2);

	PBTreeNode p3 = (PBTreeNode)malloc(sizeof(PBTreeNode));
	p3->Value = 666;
	BTreeInsert(head,p3);

	PBTreeNode p4 = (PBTreeNode)malloc(sizeof(PBTreeNode));
	p4->Value = 333;
	BTreeInsert(head,p4);

	PBTreeNode p5 = (PBTreeNode)malloc(sizeof(PBTreeNode));
	p5->Value = 222;
	BTreeInsert(head,p5);

	return 0;
}
