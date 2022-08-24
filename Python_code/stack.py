
class Stack:
    def __init__(self, max_stack_size):
        self.top_pointer = -1
        self.stack = [None for i in range(max_stack_size)]

    def push(self, value):
        self.top_pointer += 1
        self.stack[self.top_pointer] = value

    def pop(self):
        return_value = self.stack[self.top_pointer]
        self.top_pointer -= 1
        return return_value

    def top(self):
        return self.stack[self.top_pointer]

    def is_empty(self):
        return self.top_pointer == -1


def main():
    stack = Stack(20)
    stack.push(int(input('Enter a number to push \n')))
    print(stack.top())


if __name__ == '__main__':
    main()
