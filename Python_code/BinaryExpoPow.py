
def binaryExpoPow(a, b):
    if b == 0:
        return 1
    res = binaryExpoPow(a, b//2)
    if (b & 1) == 1:
        return a * res * res
    else:
        return res * res


def main():
    a, b = 2, 3
    print(binaryExpoPow(a, b))


if __name__ == "__main__":
    main()
