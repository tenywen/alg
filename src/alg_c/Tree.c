/*******************************************
   
   
   				@ Tree
				@ int binary
				@ complete
						

********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "common.h"

PTreeHead TreeNew(){
	PTreeHead head = (PTreeHead)malloc(sizeof(TreeHead));
	head->Next = NULL;
	return head; 
}

int TreeInsert(PTreeHead head,PTreeNode node) {
	PTreeNode next = _TREE_ROOT(head);
	PTreeNode parent = NULL;
	while(next) {
		parent = next;
		if(_TREE_NODE_KEY(next) > _TREE_NODE_KEY(node))	
			next = _TREE_LEFT(next);
		else
			next = _TREE_RIGHT(next);
	}
	if (parent) {
		if(_TREE_NODE_KEY(parent) > _TREE_NODE_KEY(node))	
			parent->Left = node;
		else 
			parent->Right = node;
		node->Parent = parent;
	} else {
		head->Next = node;		
	}
	return 0;	
}

int MidTraverse(PTreeNode node) {
	if (node) {
		MidTraverse(node->Left);
		printf("%d\n",node->Value);
		MidTraverse(node->Right);
	}
	return 0;
}

// return Tree min node
PTreeNode TreeMin(PTreeNode node) {
	PTreeNode left = _TREE_LEFT(node);
	PTreeNode min = node;
	while(left) {
		min = left;
		left = _TREE_LEFT(left);
	}
	return min;
}

// return Tree max node
PTreeNode TreeMax(PTreeNode node) {
	PTreeNode right = _TREE_RIGHT(node);
	PTreeNode max = node;
	while(right) {
		max = right;
		right = _TREE_RIGHT(right);
	}
	return max;
}

// return node succeed
PTreeNode TreeSucceed(PTreeNode node) {
	PTreeNode right = _TREE_RIGHT(node);
	// when node->left exist
	if(right) {
		return TreeMin(right);		
	}
	
	PTreeNode parent = _TREE_PARENT(node);
	PTreeNode p = node;
	while(parent && p == _TREE_RIGHT(parent)) {
		p = parent;
		parent = _TREE_PARENT(p);
	}
	printf("succeed:%d\n",parent->Value);
	return parent;
}

// Del node
// 删除节点有三种情况 1.节点的左右子树均存在；2.节点的左右子树只存在一个;3.节点的左右子树均不存在
// 第三种情况，最简单，将当前节点删除，并将指向当前的节点的父节点指针置空
// 第二种情况，将当前节点存在的左子树或者右子树替代当前节点
// 第一种情况，找出以当前节点为根节点的子树的后继节点。以后续节点代替当前节点。删除后继节点
int TreeDel(PTreeHead head,PTreeNode node) {
	PTreeNode replace = NULL;
	PTreeNode copy = NULL;
	// when node has child find its replace node
	if (_TREE_LEFT(node) && _TREE_RIGHT(node)) 
		replace = TreeSucceed(node);
	else if (_TREE_RIGHT(node))
		replace = (_TREE_RIGHT(node));
	else if (_TREE_LEFT(node))
		replace = (_TREE_LEFT(node));
	
	if (replace != NULL) {
		copy = (PTreeNode)malloc(sizeof(TreeNode));
		if (copy == NULL)
			return 0;
		// del replace node
		TreeDel(head,replace);
		//copy del node
		_COPY_NODE(copy,node);
		copy->Value = replace->Value;	
	}

	// reset parent node	
	PTreeNode parent = _TREE_PARENT(node);
	if(parent && node == _TREE_LEFT(parent))
		parent->Left = copy;
	else if(parent && node == _TREE_RIGHT(parent))
		parent->Right = copy;
	else if(!parent)
		head->Next = copy;
	
	if (parent && copy)
		copy->Parent = parent; 
	
	free(node);
	return 0;	
}

int main() {
	PTreeHead head = TreeNew();
	PTreeNode p = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(p,10);
	TreeInsert(head,p);
	PTreeNode pp = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(pp,5);
	TreeInsert(head,pp);
	PTreeNode ppp = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(ppp,20);
	TreeInsert(head,ppp);
	
	PTreeNode p1 = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(p1,4);
	TreeInsert(head,p1);
	
	PTreeNode p2 = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(p2,6);
	TreeInsert(head,p2);

	PTreeNode p3 = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(p3,18);
	TreeInsert(head,p3);
	
	PTreeNode p4 = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(p4,27);
	TreeInsert(head,p4);
	
	PTreeNode p5 = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(p5,25);
	TreeInsert(head,p5);

	PTreeNode p6 = (PTreeNode)malloc(sizeof(TreeNode));
	_INIT_NODE(p6,29);
	TreeInsert(head,p6);

	PTreeNode next = _TREE_ROOT(head);
	MidTraverse(next);
	TreeDel(head,p2);
	next = _TREE_ROOT(head);
	MidTraverse(next);
	//printf("succeed: %p\n",TreeSucceed(next));
	return 0;	
}
