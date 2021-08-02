// Can you get the loop? 
// https://www.codewars.com/kata/52a89c2ea8ddc5547a000863

#include <set>
#include <iostream>

struct Node
{
    Node *next;

    Node *getNext()
    {
        return next;
    }
};

int getLoopSize(Node *n)
{
    Node *lastNode = n;
    int count = 1;
    std::set<Node *> nodes;
    while (nodes.find(n) == nodes.end())
    {
        nodes.insert(n);
        lastNode = n;
        n = n->getNext();
    }

    while (n != lastNode)
    {
        count++;
        n = n->getNext();
    }
    return count;
}

int main()
{
    Node n1, n2, n3, n4, n5;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n3;

    std::cout << getLoopSize(&n1) << "\n";
    return 0;
}