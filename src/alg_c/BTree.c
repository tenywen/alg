/*******************************************
   
   
   				@ Black Tree
				@ int binary
				@ complete 
						

********************************************/
#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"

extern pBTreeNode NIL;
// 调整红黑属性
int _insert_fixed(pBTreeHead head,pBTreeNode z) {
	pBTreeNode uncle = NULL;
	while(_BTREE_PARENT(z) != NIL && _BTREE_COLOR((_BTREE_PARENT(z))) == RED) {
		if ((_BTREE_PARENT(_BTREE_PARENT(z))) == NIL) 
			break;
		if(_BTREE_PARENT(z) == _BTREE_LEFT(_BTREE_PARENT(_BTREE_PARENT(z))))
			uncle = _BTREE_RIGHT(_BTREE_PARENT(_BTREE_PARENT(z)));
		else 
			uncle = _BTREE_LEFT(_BTREE_PARENT(_BTREE_PARENT(z)));
		// 节点z的叔叔节点为红色，此为情况1:
		// 将z的父节点和叔叔节点置为黑，z变更为祖父节点。重复while循环
		if(_BTREE_COLOR(uncle) == RED) {
			_SET_COLOR(uncle,BLACK);
			_SET_COLOR(_BTREE_PARENT(z),BLACK);
			_SET_COLOR(_BTREE_PARENT(_BTREE_PARENT(z)),RED);
			z = _BTREE_PARENT(_BTREE_PARENT(z));	
		} else {
			// 节点z的叔叔节点为黑色，此为情况2，3:
			if(z == _BTREE_RIGHT(_BTREE_PARENT(z))) {
				// z上升一层
				z = _BTREE_PARENT(z);	
				_LEFT_ROTATE(head,z);
			}
			_SET_COLOR(_BTREE_PARENT(z),BLACK);
			_SET_COLOR(_BTREE_PARENT(_BTREE_PARENT(z)),RED);
			// 这里必须用一个变量x 来存储z的祖父节点，传递给下面的左转或者右转
			// 否则左转或者右转的宏，会改变z->Parent
			pBTreeNode x = _BTREE_PARENT(_BTREE_PARENT(z));
			if(_BTREE_PARENT(z) == _BTREE_LEFT(_BTREE_PARENT(_BTREE_PARENT(z))))
				_RIGHT_ROTATE(head,x);
			else 
				_LEFT_ROTATE(head,x);
		}
	}
	_SET_COLOR(head->Next,BLACK);
}

// return min node when root is node
pBTreeNode BTreeMin(pBTreeNode node) {
	pBTreeNode left = _BTREE_LEFT(node);
	pBTreeNode min = node;
	while(left && !_IS_NIL(left)) {
		min = left;
		left = _BTREE_LEFT(left);
	}
	return min;
}

// return node succeed
pBTreeNode BTreeSucceed(pBTreeNode node) {
	pBTreeNode right = _BTREE_RIGHT(node);
	pBTreeNode next = node;
	pBTreeNode parent = _BTREE_PARENT(node);
	if (right && !_IS_NIL(right)) {
		return BTreeMin(right);	
	}
	while(parent && next == _BTREE_RIGHT(parent)) { 
		next = parent;
		parent = _BTREE_PARENT(next);	
	}
	return parent;
}

pBTreeHead BTreeNew() {
	pBTreeHead head = (pBTreeHead)malloc(sizeof(BTreeHead));
	head->Next = NULL;
	return head;
}

int BTreeInsert(pBTreeHead head,pBTreeNode node) {
	pBTreeNode next = head->Next;
	pBTreeNode y = NULL;
	while(next != NULL) {
		y = next;
		if(_BTREE_VALUE(next) > _BTREE_VALUE(node))	
			next = _BTREE_LEFT(next);
		else
			next = _BTREE_RIGHT(next);
	}
	if(y != NULL) {
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

int BTreeDel(pBTreeHead head, pBTreeNode node) {
	pBTreeNode y = NIL;
	pBTreeNode x = NIL;
	if (_BTREE_LEFT(node) == NIL || _BTREE_RIGHT(node) == NIL)
		y = node;
	else 
		y = BTreeSucceed(node);
	
	// y最多只有一个孩子节点(非NIL节点)
	x = _BTREE_LEFT(y);
	if (x == NIL)
		x = _BTREE_RIGHT(y);
	_BTREE_PARENT(x) = _BTREE_PARENT(y);
	// y为root
	if (y == head->Next)
		head->Next = x;
	else if (_BTREE_LEFT(y) == y)
		_BTREE_LEFT(_BTREE_PARENT(y)) = x;
	else
		_BTREE_RIGHT(_BTREE_PARENT(y)) = x;
	if (y != node)
		_BTREE_VALUE(node) = _BTREE_VALUE(y);
	
	return 0;
}

int BTreeMidTraverse(pBTreeNode node) {
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
	pBTreeHead head = BTreeNew();
	pBTreeNode p1 = (pBTreeNode)malloc(sizeof(BTreeNode));
	p1->Value = 555;
	BTreeInsert(head,p1);
	
	pBTreeNode p2 = (pBTreeNode)malloc(sizeof(BTreeNode));
	p2->Value = 444;
	BTreeInsert(head,p2);

	pBTreeNode p3 = (pBTreeNode)malloc(sizeof(BTreeNode));
	p3->Value = 666;
	BTreeInsert(head,p3);

	pBTreeNode p4 = (pBTreeNode)malloc(sizeof(BTreeNode));
	p4->Value = 333;
	BTreeInsert(head,p4);

	pBTreeNode p5 = (pBTreeNode)malloc(sizeof(BTreeNode));
	p5->Value = 222;
	BTreeInsert(head,p5);
	return 0;
}
