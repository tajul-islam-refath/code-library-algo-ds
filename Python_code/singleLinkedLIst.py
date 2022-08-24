
class Node:
    def __init__(self, data=0, next=None):
        self.data = data,
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, val):
        node = Node(val)
        if self.head is None:
            self.head = node
            return
        temp = self.head
        while(temp.next is not None):
            temp = temp.next
        temp.next = node

    def delete(self, val):
        temp = self.head
        prev = None
        while(temp):
            print(temp.data)
            if temp.data == val:
                print(f"deleted value {temp.data}")
                if prev == None:
                    self.head = temp.next
                    break
                else:
                    prev.next = temp.next
                    break
            else:
                prev = temp
                temp = temp.next

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next


def append(val, head: Node):
    node = Node(val)
    if head is None:
        head = node
        return
    temp = head
    while(temp.next is not None):
        temp = temp.next
    temp.next = node


def printList(head: Node):
    temp = head
    while(temp):
        print(temp.data)
        temp = temp.next


def main():
    n = 5
    list = LinkedList()
    head = Node()
    for _ in range(n):
        append(int(input("Enter number")), head)
        # list.append(int(input("Enter any number : ")))
        # list.printList()
        # list.delete(int(input("Enter number to delete : ")))
        # list.printList()
    printList(head)


if __name__ == '__main__':
    main()
