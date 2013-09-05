package list


/**************************
			list	
2.list func
3.has list head
**************************/




func New() *Node {
	head := Node{0,nil}
	return &head
}

func Last(node *Node) *Node {
	p := node
	for ; p.Next != nil; p = p.Next {

	}
	return p
}


func Add(head *Node,value int32) {
	new_node := &Node{value,nil}
	if head.Next == nil {
		head.Next = new_node
	} else {
		last_node := Last(head.Next)
		last_node.Next = new_node
	}
}

func Find(head *Node, value int32) *Node {
	p := head.Next
	for ; p != nil; p = p.Next {
		if p.Value == value {
			break
		}
	}
	return p
}


func Del(head *Node, value int32) {
	p1 := head
	p2 := p1.Next
	for ; p2 != nil; {
		if p2.Value == value {
			p1.Next = p2.Next
			break			
		}
		p1 = p2
		p2 = p1.Next
	}
}
