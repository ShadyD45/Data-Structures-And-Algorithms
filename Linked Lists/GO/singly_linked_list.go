package main

import (
	"fmt"
)

type Node struct {
	data int
	next *Node
}

type SinglyLinkedList struct {
	head *Node
}

func newNode(data int, next *Node) *Node {
	n := Node{data: data}
	n.next = next
	return &n
}

func newList() *SinglyLinkedList {
	l := SinglyLinkedList{head: newNode(0, nil)}
	return &l
}

func (ll *SinglyLinkedList) insert_start(data int) {
	node := newNode(data, ll.head.next)
	ll.head.next = node
}

func (ll *SinglyLinkedList) isEmpty() bool {
	if ll.head.next == nil {
		return true
	} else {
		return false
	}
}

func (ll *SinglyLinkedList) insert_end(data int) {
	run := ll.head

	node := newNode(data, nil)
	for { // Traverse to the last node
		if run.next == nil {
			break
		}
		run = run.next
	}

	run.next = node
}

func (ll *SinglyLinkedList) search(data int) (*Node, error) {
	run := ll.head.next

	for {
		if run == nil {
			return nil, fmt.Errorf("Can't find %d in list", data)
		}

		if run.data == data {
			return run, nil
		}

		run = run.next
	}
}

func (ll *SinglyLinkedList) insert_after(newData int, data int) (bool, error) {
	node, err := ll.search(data)

	if err != nil {
		return false, fmt.Errorf("Can't insert after non-existent value: %d", data)
	}

	newNode := newNode(newData, node.next)
	node.next = newNode

	return true, nil
}

func (ll *SinglyLinkedList) insert_before(newData int, data int) (bool, error) {
	run := ll.head
	// Search for the node before given "data"
	for {
		if run.next == nil {
			return false, fmt.Errorf("Can't find %d in list", data)
		}

		if run.next.data == data {
			break
		}

		run = run.next
	}

	node := newNode(newData, run.next)
	run.next = node

	return true, nil
}

func (ll *SinglyLinkedList) print() {
	run := ll.head.next
	fmt.Println("##################")
	fmt.Printf("[HEAD]->")
	for {
		if run == nil {
			break
		}

		fmt.Printf("[%d]->", run.data)

		run = run.next
	}
	fmt.Println("NULL")
	fmt.Print("##################")
}

func main() {
	fmt.Println("Creating list")
	l_list := newList()

	fmt.Println("Inserting 20 at start")
	l_list.insert_start(20)

	fmt.Println("Inserting 30 at start")
	l_list.insert_start(30)

	fmt.Println("Inserting 40 at end")
	l_list.insert_end(40)

	fmt.Println("Inserting 50 after 30")
	l_list.insert_after(50, 30)

	fmt.Println("Inserting -100 before 30")
	l_list.insert_before(-100, 30)

	l_list.print()
}
