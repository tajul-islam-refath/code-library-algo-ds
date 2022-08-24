def gcd(a, b):
    # print("{} {}".format(a, b))
    if b == 0:
        return a
    return gcd(b, a % b)


def main():
    a, b = map(int, input().split())
    ans = gcd(a, b)
    print("Gcd : {}".format(ans))
    lcm = (a*b)//ans
    print("Lcm : {}".format(lcm))


if __name__ == '__main__':
    main()
