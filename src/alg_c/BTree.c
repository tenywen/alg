/*******************************************
   
   
   				@ Black Tree
				@ int binary
				@ complete 
						

********************************************/
#include <stdlib.h>
#include "BTree.h"

PBTreeNode BTreeNew() {
	PBTreeNode head = (PBTreeNode)malloc(sizeof(BTreeNode));
	if (!head)
		return NULL;
	head->Parent = NULL;
	head->Left = NULL;
	head->Right = NULL;
	head->Value = 0;	
	return head;	
}

PBTreeNode BTreeNIL(PBTreeNode p) {
	PBTreeNode node = (PBTreeNode)malloc(sizeof(BTreeNode));
	if (!node)
		return NULL;
	node->Parent = p;
	node->Left = NULL;
	node->Right = NULL;
	node->Value = 0;
	p = node;
	return node;
}

int main() {
	
}
