#Not correct :(
x2 = int(input())

def smallestPrime(n):
    p = 2
    n_real = n
    ret = []
    while True:
        if n % p == 0:
            return p
        p += 1

def modpow(a, p):
    if p == 0:
        return 1
    ret = 1
    while p:
        if p&1:
            ret = (ret * a) % p
            p -= 1
        if p >= 1:
            ret = ret * ret
            p /= 2

def isPrime(n):
    return modpow(n, 1000000006) == 1 and modpow(n, 1000000008) == 1


def solve(n):
    mn = 1000000000
    n2_pot = int(n / smallestPrime(n))
    for i in range(n2_pot, n + 1):
        f2 = smallestPrime(i)
        mn = min(int(i / f2), mn)
    return mn
    

print(solve(x2))





