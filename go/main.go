package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Node struct {
	x      int
	y      int
	number int
	l      *Node
	r      *Node
	p      *Node
}

func newNode(x, y, number int) *Node {
	return &Node{x: x, y: y, number: number}
}

func build(nodes []*Node) *Node {
	t := nodes[0]
	last := t

	for i := 1; i < len(nodes); i++ {
		if last.y < nodes[i].y {
			last.r = nodes[i]
			last.r.p = last
			last = last.r
		} else {
			cur := last
			for cur.p != nil && cur.y > nodes[i].y {
				cur = cur.p
			}
			if cur.y > nodes[i].y {
				last = nodes[i]
				last.l = cur
				cur.p = last
			} else {
				last = nodes[i]
				last.l = cur.r
				cur.r.p = last
				last.p = cur
				cur.r = last
			}
		}
	}

	for last.p != nil {
		last = last.p
	}
	return last
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	var n int
	fmt.Sscanf(scanner.Text(), "%d", &n)

	nodes := make([]*Node, n)
	originals := make([]*Node, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		var a, b int
		fmt.Sscanf(scanner.Text(), "%d %d", &a, &b)
		node := newNode(a, b, i+1)
		nodes[i] = node
		originals[i] = node
	}

	sort.Slice(nodes, func(i, j int) bool {
		return nodes[i].x < nodes[j].x
	})

	build(nodes)

	fmt.Println("YES")
	for i := 0; i < n; i++ {
		cur := originals[i]
		parentNum := 0
		leftNum := 0
		rightNum := 0
		if cur.p != nil {
			parentNum = cur.p.number
		}
		if cur.l != nil {
			leftNum = cur.l.number
		}
		if cur.r != nil {
			rightNum = cur.r.number
		}
		fmt.Printf("%d %d %d\n", parentNum, leftNum, rightNum)
	}
}
