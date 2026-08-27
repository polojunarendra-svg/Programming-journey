# name = "eceab"
# k=2
# uniq=""
# count=0;
# for ch in name:
#     if ch not in uniq:
#         count = count + 1
#         uniq+=ch
#         if count==k:
#             print(uniq)
#             break
def prime(i, j):
    ls = []
    ans = i * j

    if is_prime(ans):
        ls.append(ans)

    return ls


def is_prime(n):
    if n <= 1:
        return False

    if n == 2:
        return True

    if n % 2 == 0:
        return False

    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False

    return True

#
# for i in range(101):
#     for j in range(101):
#         if is_prime(i * j):
#             print(i,"x", j, "=", i * j)
def fibonacci(limit: int):
        """Yield Fibonacci numbers up to `limit`.

        Memory: O(1) — only two variables are held at any time.
        Time:   O(limit) — one iteration per number.
        """
        a, b = 0, 1
        while a < limit:
            yield a             # Suspend here, resume on next()
            a, b = b, a + b
print(f"Fibonacci < 100: {list(fibonacci(100))}")