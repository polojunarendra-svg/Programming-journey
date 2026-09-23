# # --- Bytes vs Bytearray ---
# raw = b"\x00\x01\x02"  # immutable
# ba = bytearray(raw)  # mutable copy
# ba[0] = 0xFF
# print(f"\nbytes = {raw}, bytearray after mutation = {ba}")
# # --- Type hierarchy summary ---
# print("\n--- Type Hierarchy Summary ---")
# for obj in (42, 3.14, True, "hi", b"hi", (1,), [1], {1}, frozenset([1]), {"a": 1}):
#     print(f"  {str(obj):20s}  type={type(obj).__name__:12s}"f"mutable={'Yes' if isinstance(obj, (list, dict, set, bytearray)) else 'No'}")
# n = int(input(":"))
# status = "Elgible" if n >18 else "Not Elgible"
# print(status)
#n = int(input(":"))
# type = "Even" if n%2==0 else "Odd"
# print(type)
# target = [1, 5, 12, 3, 18, 7]
# ans=[x for x in target if x%2==0 ]
# print(ans)
# ans1 =[x*x for x in target]
# print(ans1)
word = "abracadabra"
freq = {ch: word.count(ch) for ch in set(word)}
print(f"Letter frequencies: {freq}")
paragraph ="abcdefghijklmnopqrstuvwxyaz"
letfreq={ch:paragraph.count(ch) for ch in set(paragraph)}
print(f"Letter frequencies: {letfreq}")