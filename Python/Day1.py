 # #In python while we compare to the C and java
 # Immutable : You cannot modify characters within an existing string;
 # modifications always generate a new string object.
 # Sequence Type : They are ordered collections, allowing character access via index numbers.
 # Iterable : You can traverse individual characters seamlessly using standard forloops.
 # No Character Type : Python treats a single character as a string of length
 # 1.Unicode Support : Strings natively support alphabets, numbers, symbols, and emojis across different languages.
 # String Creation & LiteralsYou can instantiate strings by enclosing characters inside single, double, or triple quotes.
 # python# Single or Double quotes for single-line text
 # s1 = 'Hello'
 # s2 = "Python"
 # Triple quotes for multi-line text or docstrings
 # s3 = """This is a
 # multi-line string."""
 # Use the code with caution.Essential Operations1.
 # Indexing & SlicingPython uses zero-based indexing for forward tracking, and negative indexing to read backward from the end.
 # Slicing extracts portions using the syntax [start:end:step].pythontext = "Python"
 # print(text[0])   # 'P' (First character)
 # print(text[-1])  # 'n' (Last character)
 # print(text[0:4]) # 'Pyth' (Indices 0 to 3)
 # print(text[::-1])# 'nohtyP' (Reverses string)
 # Use the code with caution.
 # 2. Concatenation & RepetitionCombine or repeat text patterns dynamically using arithmetic operators.
 # pythonprint("Hello" + " " + "World") # 'Hello World' (Concatenation)
 # print("Hi!" * 3)               # 'Hi!Hi!Hi!' (Repetition)
 # Use the code with caution.
 # 3. Membership TestingQuickly check if a substring exists within text using inor not inoperators
 # .pythonprint("Py" in "Python") # True
 # Use the code with caution.Important Built-In String MethodsBecause strings are immutable, these methods from the W3Schools Python String Reference return a completely new string instead of altering the original variable.
 # MethodDescriptionExamplelen(s)Returns total character length.len("Abc")→3s.
 # upper()/s.lower()Converts casing completely."Hi".lower()→"hi"s.
 # strip()Discards leading/trailing whitespace." x ".
 # strip()→"x"s.replace(old, new)Swaps target substrings cleanly.
 # "tezt".replace("z", "s")→"test"s.split(separator)Breaks string into a List of substrings.
 # "a,b".split(",")→['a', 'b']separator.join(list)Merges an iterable sequence into one string.
 # "-".join(['a', 'b'])→"a-b"Modern String Formatting (f-strings)Introduced in Python 3.6, f-strings (formatted string literals) provide a highly readable syntax to embed expressions inside string literals.
 # pythonname = "Alice"
 # age = 30
 # print(f"User {name} is {age} years old.")
 # # Output: User Alice is 30 years old.

paragraph = "Bold hit an bat"
j=0
word=""
temp =""
i=0
start=0
while(j<len(paragraph)):
    if(paragraph[j]==" "):
        print("\n")
        j+=1
        continue
    print(paragraph[j],end="")
    j+=1
