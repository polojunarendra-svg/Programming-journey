
def control_flow_demo():
    """Control flow constructs and Pythonic iteration patterns.

    Covers
    ------
    * if/elif/else, ternary expressions, walrus operator (:=)
    * for/while loops, break/continue/else-on-loop
    * List, dict, set, and nested comprehensions
    * Iterator protocol (__iter__ / __next__)
    * Generator functions (yield) and generator expressions
    * itertools highlights

    Big-O Notes
    -----------
    * Comprehensions: O(n) — one pass over the iterable.
    * Generators: O(1) memory per yielded item (lazy evaluation).
    """
    import itertools

    # --- Ternary expression ---
    age = 20
    status = "adult" if age >= 18 else "minor"
    print(f"Age {age} → {status}")

    # --- Walrus operator (:=) — Python 3.8+ ---
    # Assigns inside an expression, reducing redundant computation.
    data = [1, 5, 12, 3, 18, 7]
    large = [x for x in data if (sq := x * x) > 50]
    print(f"Elements whose square > 50: {large}")

    # --- for/else — the else block runs if the loop was NOT broken ---
    primes = [2, 3, 5, 7, 11]
    target = 6
    for p in primes:
        if p == target:
            print(f"Found {target} in primes")
            break
    else:
        # This runs because we never hit `break`
        print(f"{target} is NOT in the primes list (for/else executed)")

    # --- List comprehension ---
    squares = [x ** 2 for x in range(10)]
    print(f"Squares: {squares}")

    # --- Dict comprehension ---
    word = "abracadabra"
    freq = {ch: word.count(ch) for ch in set(word)}
    print(f"Letter frequencies: {freq}")

    # --- Set comprehension ---
    evens = {x for x in range(20) if x % 2 == 0}
    print(f"Even numbers: {evens}")

    # --- Nested comprehension (matrix transpose) ---
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    transposed = [[row[i] for row in matrix] for i in range(len(matrix[0]))]
    print(f"Transposed matrix: {transposed}")

    # --- Iterator Protocol ---
    class Countdown:
        """A custom iterator that counts down from `start` to 1.
        Implements __iter__ (returns self) and __next__ (yields values)."""
        def __init__(self, start: int):
            self.current = start

        def __iter__(self):
            return self          # An iterator returns itself

        def __next__(self):
            if self.current <= 0:
                raise StopIteration   # Signal exhaustion
            val = self.current
            self.current -= 1
            return val

    print(f"Countdown: {list(Countdown(5))}")

    # --- Generator Function (yield) ---
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

    # --- Generator Expression (lazy, memory-efficient) ---
    # Unlike a list comprehension [x**2 for ...], this uses () and is lazy.
    gen_expr = (x ** 2 for x in range(1_000_000))
    first_five = [next(gen_expr) for _ in range(5)]
    print(f"First 5 from generator expression: {first_five}")

    # --- itertools highlights ---
    # chain: flatten multiple iterables
    print(f"chain: {list(itertools.chain([1, 2], [3, 4], [5]))}")
    # combinations
    print(f"C(4,2): {list(itertools.combinations(range(4), 2))}")
    # product (Cartesian product)
    print(f"product: {list(itertools.product('AB', '12'))}")
    # groupby (data must be sorted by key first)
    data_sorted = sorted(["apple", "avocado", "banana", "blueberry"], key=lambda w: w[0])
    for key, group in itertools.groupby(data_sorted, key=lambda w: w[0]):
        print(f"  groupby '{key}': {list(group)}")

# control_flow_demo()
# age = int(input("Enter the age:"))
# message = "adult" if age>=18 else "minor"
# print(message)
# Warlus operator in normal way we will be implementing this ok
# data = [1, 5, 12, 3, 18, 7]
# if n := len(data)>5:
#     print(n)
# data = [1, 5, 12, 3, 18, 7]
# ans = [x for x in data  if(sq:= x * x) > 50]
# print(ans)
matrix =[
    [1,2,3],
    [4,5,6],
]
# Normal way
# for i in range(len(matrix)):
#     for j in range(len(matrix[i])):
#         matrix[i][j] = matrix[i][j] * 10
# print(matrix)
res =[x * 10 for row in matrix for x in row]
print(res)