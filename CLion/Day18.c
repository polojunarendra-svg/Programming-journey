//
// Created by poloj on 21-09-2026.
//
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include<string.h>
int DataTypeKeywords() {
    /* =============================================================================== C DATA TYPES ===============================================================================
     * This program demonstrates:
     * 1. Data type
     * 2. Value stored
     * 3. Size in bytes
     * 4. Number of bits
     * 5. Memory address
     * 6. Minimum and maximum range IMPORTANT: signed and unsigned are TYPE MODIFIERS.
     * They are not separate data types by themselves.
     * For example: int signed int unsigned int are integer types with different ranges.
     * =============================================================================== */
    /* =============================================================================== VARIABLES =============================================================================== */
    char charValue = 'A';
    short shortValue = -100;
    int intValue = 1000;
    long longValue = 100000L;
    long long longLongValue = 10000000000LL;
    float floatValue = 99.99f;
    double doubleValue = 3.141592653589793;
    signed int signedIntValue = -500;
    unsigned int unsignedIntValue = 4000000000U;
    unsigned char unsignedCharValue = 250;
    /* =============================================================================== PROGRAM INFORMATION =============================================================================== */
    printf("\n");
    printf("===============================================================================\n");
    printf(" C DATA TYPE INFORMATION\n");
    printf("===============================================================================\n");
    /* =============================================================================== CHAR =============================================================================== */
    printf("\n");
    printf("------------------------------ CHAR -----------------------------------------\n");
    printf("Data Type : char\n");
    printf("Value : %c\n", charValue);
    printf("ASCII Value : %d\n", charValue);
    printf("Size : %zu byte(s)\n", sizeof(charValue));
    printf("Bits : %zu bits\n", sizeof(charValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&charValue);
    printf("Signed Range : %d to %d\n", CHAR_MIN, CHAR_MAX);
    /* =============================================================================== SHORT =============================================================================== */
    printf("\n");
    printf("------------------------------ SHORT ----------------------------------------\n");
    printf("Data Type : short\n");
    printf("Value : %hd\n", shortValue);
    printf("Size : %zu byte(s)\n", sizeof(shortValue));
    printf("Bits : %zu bits\n", sizeof(shortValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&shortValue);
    printf("Signed Range : %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned Range : 0 to %u\n", USHRT_MAX);
    /* =============================================================================== INT =============================================================================== */
    printf("\n");
    printf("------------------------------ INT ------------------------------------------\n");
    printf("Data Type : int\n");
    printf("Value : %d\n", intValue);
    printf("Size : %zu byte(s)\n", sizeof(intValue));
    printf("Bits : %zu bits\n", sizeof(intValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&intValue);
    printf("Signed Range : %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned Range : 0 to %u\n", UINT_MAX);
    /* =============================================================================== LONG =============================================================================== */
    printf("\n");
    printf("------------------------------ LONG -----------------------------------------\n");
    printf("Data Type : long\n");
    printf("Value : %ld\n", longValue);
    printf("Size : %zu byte(s)\n", sizeof(longValue));
    printf("Bits : %zu bits\n", sizeof(longValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&longValue);
    printf("Signed Range : %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned Range : 0 to %lu\n", ULONG_MAX);
    /* =============================================================================== LONG LONG =============================================================================== */
    printf("\n");
    printf("---------------------------- LONG LONG --------------------------------------\n");
    printf("Data Type : long long\n");
    printf("Value : %lld\n", longLongValue);
    printf("Size : %zu byte(s)\n", sizeof(longLongValue));
    printf("Bits : %zu bits\n", sizeof(longLongValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&longLongValue);
    printf("Signed Range : %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Unsigned Range : 0 to %llu\n", ULLONG_MAX);
    /* =============================================================================== FLOAT =============================================================================== */
    printf("\n");
    printf("------------------------------ FLOAT ----------------------------------------\n");
    printf("Data Type : float\n");
    printf("Value : %f\n", floatValue);
    printf("Size : %zu byte(s)\n", sizeof(floatValue));
    printf("Bits : %zu bits\n", sizeof(floatValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&floatValue);
    printf("Minimum Range : %e\n", -FLT_MAX);
    printf("Maximum Range : %e\n", FLT_MAX);
    printf("Precision : %d decimal digits\n", FLT_DIG);
    /* =============================================================================== DOUBLE =============================================================================== */
    printf("\n");
    printf("----------------------------- DOUBLE ----------------------------------------\n");
    printf("Data Type : double\n");
    printf("Value : %.15f\n", doubleValue);
    printf("Size : %zu byte(s)\n", sizeof(doubleValue));
    printf("Bits : %zu bits\n", sizeof(doubleValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&doubleValue);
    printf("Minimum Range : %e\n", -DBL_MAX);
    printf("Maximum Range : %e\n", DBL_MAX);
    printf("Precision : %d decimal digits\n", DBL_DIG);
    /* =============================================================================== SIGNED INT =============================================================================== */
    printf("\n");
    printf("--------------------------- SIGNED INT --------------------------------------\n");
    printf("Data Type : signed int\n");
    printf("Value : %d\n", signedIntValue);
    printf("Size : %zu byte(s)\n", sizeof(signedIntValue));
    printf("Bits : %zu bits\n", sizeof(signedIntValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&signedIntValue);
    printf("Range : %d to %d\n", INT_MIN, INT_MAX);
    /* =============================================================================== UNSIGNED INT =============================================================================== */
    printf("\n");
    printf("-------------------------- UNSIGNED INT -------------------------------------\n");
    printf("Data Type : unsigned int\n");
    printf("Value : %u\n", unsignedIntValue);
    printf("Size : %zu byte(s)\n", sizeof(unsignedIntValue));
    printf("Bits : %zu bits\n", sizeof(unsignedIntValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&unsignedIntValue);
    printf("Range : 0 to %u\n", UINT_MAX);
    /* =============================================================================== UNSIGNED CHAR =============================================================================== */
    printf("\n");
    printf("------------------------- UNSIGNED CHAR -------------------------------------\n");
    printf("Data Type : unsigned char\n");
    printf("Value : %u\n", unsignedCharValue);
    printf("Size : %zu byte(s)\n", sizeof(unsignedCharValue));
    printf("Bits : %zu bits\n", sizeof(unsignedCharValue) * CHAR_BIT);
    printf("Address : %p\n", (void *)&unsignedCharValue);
    printf("Range : 0 to %u\n", UCHAR_MAX);
    /* =============================================================================== VOID =============================================================================== */
    printf("\n");
    printf("------------------------------ VOID -----------------------------------------\n");
    printf("Data Type : void\n");
    printf("Size : No object size\n");
    printf("Bits : No object bits\n");
    printf("Address : No address\n");
    printf("Meaning : No value / no type\n");
    /* =============================================================================== SUMMARY TABLE =============================================================================== */
    printf("\n\n");
    printf("===============================================================================\n");
    printf(" SUMMARY\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("%-20s %-10s %-10s %-20s\n", "DATA TYPE", "BYTES", "BITS", "ADDRESS");
    printf("-------------------------------------------------------------------------------\n");
    printf("%-20s %-10zu %-10zu %p\n", "char", sizeof(charValue), sizeof(charValue) * CHAR_BIT, (void *)&charValue);
    printf("%-20s %-10zu %-10zu %p\n", "short", sizeof(shortValue), sizeof(shortValue) * CHAR_BIT, (void *)&shortValue);
    printf("%-20s %-10zu %-10zu %p\n", "int", sizeof(intValue), sizeof(intValue) * CHAR_BIT, (void *)&intValue);
    printf("%-20s %-10zu %-10zu %p\n", "long", sizeof(longValue), sizeof(longValue) * CHAR_BIT, (void *)&longValue);
    printf("%-20s %-10zu %-10zu %p\n", "long long", sizeof(longLongValue), sizeof(longLongValue) * CHAR_BIT, (void *)&longLongValue);
    printf("%-20s %-10zu %-10zu %p\n", "float", sizeof(floatValue), sizeof(floatValue) * CHAR_BIT, (void *)&floatValue);
    printf("%-20s %-10zu %-10zu %p\n", "double", sizeof(doubleValue), sizeof(doubleValue) * CHAR_BIT, (void *)&doubleValue);
    printf("%-20s %-10zu %-10zu %p\n", "signed int", sizeof(signedIntValue), sizeof(signedIntValue) * CHAR_BIT, (void *)&signedIntValue);
    printf("%-20s %-10zu %-10zu %p\n", "unsigned int", sizeof(unsignedIntValue), sizeof(unsignedIntValue) * CHAR_BIT, (void *)&unsignedIntValue);
    /* =============================================================================== IMPORTANT CONCEPT =====================================================================
     * ========== &variable gives the ADDRESS of the variable.
     * Example: &intValue means: "Give me the memory address where intValue is stored."
     * %p is used with printf() to print a pointer/address. Therefore: printf("%p", (void *)&intValue);
     * prints the memory address of intValue. =============================================================================== */
    return 0;
}
   /* =============================================================================== C STORAGE CLASSES ===============================================================================
    * Storage classes tell us important properties about a variable/function:
    * 1. Scope
    * 2. Lifetime / Storage Duration
    * 3. Linkage
    * 4. Where the object can be accessed
    * 5. How long the object exists Main storage-class specifiers:
    * 1. auto
    * 2. register
    * 3. static
    * 4. extern C11 also introduced:
    * 5. _Thread_local
    * =============================================================================== */
    /* =============================================================================== 1. AUTO ===============================================================================
     * auto is the default storage class for local variables.
     * Example: auto int x = 10;
     * The "auto" keyword is normally omitted: int x = 10;
     * Both mean the same thing inside a block/function.
     * Properties: Scope: Block scope Lifetime: Created when execution enters the block.
     * Destroyed when execution leaves the block.
     * Default value: Indeterminate value if not initialized.
     * Linkage: No linkage. Storage duration: Automatic storage duration.
     * IMPORTANT: You normally DO NOT write "auto". Instead of: auto int x = 10;
     * simply write: int x = 10;
     * =============================================================================== */
    void demonstrate_auto()
    {
        auto int x = 100;
        printf("\n");
        printf("--------------- AUTO ----------------\n");
        printf("Variable : x\n");
        printf("Value : %d\n", x);
        printf("Size : %zu bytes\n", sizeof(x));
        printf("Address : %p\n", (void *)&x);
        /* x is created when this function/block starts and destroyed when this function/block ends. */
    }
    /* =============================================================================== 2. REGISTER ===============================================================================
     * register is a request to the compiler: "This variable may be accessed frequently, so consider keeping it in a CPU register.
     * " Example: register int counter = 0; IMPORTANT: Modern compilers usually optimize variables automatically.
     * Therefore, the compiler may completely ignore the register suggestion. Properties: Scope: Block scope Lifetime: Automatic storage duration Default value: Indeterminate if not initialized.
     * Linkage: No linkage. IMPORTANT: You generally cannot use the & operator on a register variable. Example: register int x = 10; &x;
     * // NOT allowed Why? A register variable may be stored in a CPU register rather than in an addressable memory location.
     * =============================================================================== */
void demonstrate_register() {
    register int counter = 100;
    printf("\n");
    printf("------------- REGISTER -------------\n");
    printf("Variable : counter\n"); printf("Value : %d\n", counter);
    printf("Size : %zu bytes\n", sizeof(counter));
    /* DO NOT do this: printf("%p", (void *)&counter); because the address of a register variable cannot be requested. */
    printf("Address : Cannot be requested with &\n");
}
/* =============================================================================== 3. STATIC ===============================================================================
 * static is one of the most important storage classes in C. static has TWO important uses: ----------------------------------------------------------- A. static LOCAL VARIABLE -----------------------------------------------------------
 * A local static variable: static int count = 0; has: Block scope Static storage duration No linkage Unlike a normal local variable, it is NOT destroyed when the function returns.
 * Its value is preserved between function calls. Example:
 * void counter()
 * {
 * static int count = 0;
 * count++;
 * printf("%d\n", count);
 * } Calling: counter();
 * counter();
 * counter();
 * produces: 1 2 3
 * ----------------------------------------------------------- B. static GLOBAL VARIABLE -----------------------------------------------------------
 * A global static variable: static int number = 100;
 * has: File scope Static storage duration Internal linkage This means the variable can be accessed only from the source file where it is declared.
 * =============================================================================== */
void demonstrate_static_local() {
    static int count = 0; count++;
    printf("\n");
    printf("----------- STATIC LOCAL -----------\n");
    printf("Variable : count\n"); printf("Value : %d\n", count);
    printf("Size : %zu bytes\n", sizeof(count));
    printf("Address : %p\n", (void *)&count);
    /* Notice: The address remains the same between function calls. The value also remains between function calls. This is the major difference between: int count = 0; and: static int count = 0; */
} /* =============================================================================== STATIC GLOBAL =============================================================================== */
static int staticGlobalVariable = 500;
/* staticGlobalVariable: Scope: File scope Lifetime: Entire execution of the program
 * Linkage: Internal linkage Meaning: It can be accessed only from this source file. */
void demonstrate_static_global() {
    /*
     * Main purpose of the static keyword with this example ok
    * #include <stdio.h>

void withdraw_money_secure(int amount) {
    // This line runs ONLY ONCE when the program starts.
    // It is NOT reset to 0 on subsequent function calls.
    static int total_transactions = 0;

    total_transactions++;
    printf("Withdrew $%d. Total transactions done today: %d\n", amount, total_transactions);
}

int main() {
    withdraw_money_secure(100); // User 1 withdraws
    withdraw_money_secure(50);  // User 2 withdraws
    withdraw_money_secure(200); // User 3 withdraws
    return 0;
}

     */
    printf("\n");
    printf("----------- STATIC GLOBAL ----------\n");
    printf("Variable : staticGlobalVariable\n");
    printf("Value : %d\n", staticGlobalVariable);
    printf("Size : %zu bytes\n", sizeof(staticGlobalVariable));
    printf("Address : %p\n", (void *)&staticGlobalVariable);
} /* =============================================================================== 4. EXTERN ===============================================================================
extern tells the compiler: "This variable/function is defined somewhere else." Example: extern int globalValue; This declaration does NOT normally create a new variable.
It tells the compiler that globalValue exists elsewhere. Example: File 1: int globalValue = 100; File 2: extern int globalValue; printf("%d", globalValue);
Properties: Scope: Usually file scope when declared globally. Lifetime: Static storage duration for the referred object. Linkage: Usually external linkage.
Purpose: Access a global variable or function defined in another source file. IMPORTANT: extern does NOT mean: "Create a new variable." It generally means: "The variable exists somewhere else."
=============================================================================== */
int externGlobalVariable = 1000;
/* This variable has external linkage because it is a global variable without static.
 * Another .c file could declare: extern int externGlobalVariable; and access it. */
void demonstrate_extern() {
    /* We are declaring that this variable exists elsewhere.
     * In this same program it happens to be defined above. */
    extern int externGlobalVariable; printf("\n");
    printf("------------- EXTERN --------------\n");
    printf("Variable : externGlobalVariable\n");
    printf("Value : %d\n", externGlobalVariable);
    printf("Size : %zu bytes\n", sizeof(externGlobalVariable));
    printf("Address : %p\n", (void *)&externGlobalVariable);
} /* =============================================================================== 5. _THREAD_LOCAL ===============================================================================
_Thread_local was introduced in C11.
It creates a separate copy of a variable for each thread.
Example: _Thread_local int threadValue = 100;
Each thread gets its own independent threadValue.
Properties: Storage duration: Thread storage duration Lifetime: Exists for the lifetime of the thread.
Scope: Depends on where it is declared.
This is mainly useful in: Multithreaded programming Concurrent applications Thread-specific data IMPORTANT: You will usually encounter this much later when learning threads and concurrency.
=============================================================================== */
/* =============================================================================== STORAGE CLASS DEMONSTRATION =============================================================================== */
void stoargeclasses() { /* =========================================================================== STORAGE CLASS DEMO =========================================================================== */
printf("\n");
    printf("===============================================================================\n");
    printf(" C STORAGE CLASSES\n");
    printf("===============================================================================\n");
    /* =========================================================================== AUTO =========================================================================== */
    demonstrate_auto();
    /* =========================================================================== REGISTER =========================================================================== */
    demonstrate_register(); /* =========================================================================== STATIC LOCAL =========================================================================== */
    printf("\nCalling static function first time:");
    demonstrate_static_local();
    printf("\nCalling static function second time:");
    demonstrate_static_local();
    printf("\nCalling static function third time:");
    demonstrate_static_local();
    /* =========================================================================== STATIC GLOBAL =========================================================================== */
    demonstrate_static_global();
    /* =========================================================================== EXTERN =========================================================================== */
    demonstrate_extern();
    /* =========================================================================== STORAGE CLASS SUMMARY =========================================================================== */
    printf("\n\n");
    printf("===============================================================================\n");
    printf(" STORAGE CLASS SUMMARY\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("%-15s %-20s %-25s %-20s\n", "CLASS", "SCOPE", "STORAGE DURATION", "LINKAGE");
    printf("-------------------------------------------------------------------------------\n");
    printf("%-15s %-20s %-25s %-20s\n", "auto", "Block", "Automatic", "None");
    printf("%-15s %-20s %-25s %-20s\n", "register", "Block", "Automatic", "None");
    printf("%-15s %-20s %-25s %-20s\n", "static local", "Block", "Static", "None");
    printf("%-15s %-20s %-25s %-20s\n", "static global", "File", "Static", "Internal");
    printf("%-15s %-20s %-25s %-20s\n", "extern", "File", "Static", "External");
    printf("%-15s %-20s %-25s %-20s\n", "_Thread_local", "Depends", "Thread", "Depends");
    /* =========================================================================== IMPORTANT DIFFERENCE ===========================================================================
     * NORMAL LOCAL VARIABLE:
     * void test() {
     * int x = 0; x++;
     * } Every time test() is called: x is created x starts at 0 x is destroyed when test() ends STATIC LOCAL VARIABLE:
     * void test() {
     * static int x = 0; x++;
     * }
     * First call: x = 1 Second call: x = 2 Third call: x = 3 The variable keeps its value between function calls.
     * =========================================================================== MEMORY / LIFETIME IDEA ===========================================================================
     * Automatic variable: Function starts | v [ x created ] | | [ x exists ] | v Function ends | v [ x destroyed ] Static variable: Program starts | v [ x created ] | | [ x exists ] | | v Program ends | v [ x destroyed ]
     * =========================================================================== */
}
/* =============================================================================== C USER-DEFINED TYPES ===============================================================================
 * IMPORTANT: C does NOT allow us to create our own KEYWORDS.
 * For example, we cannot create: myint myif myreturn and make them C keywords.
 * What we CAN create are USER-DEFINED TYPES. Main concepts:
 * 1. struct
 * 2. union
 * 3. enum
 * 4. typedef
 * =============================================================================== */
/* =============================================================================== 1. STRUCT ===============================================================================
 * struct allows us to group DIFFERENT types of data together.
 * Example: struct Student
 * { int id; char name[50];
 * float marks;
 * };
 * A structure can contain: int float char double arrays pointers other structures etc.
 * Each member gets its own storage.
 * =============================================================================== */
struct Student {
    int id;
    char name[50];
    float marks;
};
/* =============================================================================== 2. UNION ===============================================================================
 * union is similar to struct. BUT: All members share the SAME memory location.
 * Example: union Data { int i; float f; char c; };
 * A union can hold a value for ONE member at a time.
 * The size of a union is generally based on its largest member, subject to alignment requirements.
 * =============================================================================== */
union Data {
    int i;
    float f;
    char c;
};
/* =============================================================================== 3. ENUM ===============================================================================
 * enum means ENUMERATION.
 * It allows us to create a set of named integer constants.
 * Example: enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
 * By default: SUNDAY = 0 MONDAY = 1 TUESDAY = 2 ... We can also assign our own values.
 * =============================================================================== */
enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
/* =============================================================================== ENUM WITH VALUES =============================================================================== */ enum Status { FAILED = 0, SUCCESS = 1, PENDING = 2 }; /* =============================================================================== 4. TYPEDEF ===============================================================================
typedef creates an ALIAS / another name for an existing type.
Example: typedef int Integer; Now: Integer x = 100; is equivalent to: int x = 100;
IMPORTANT: typedef does NOT create a completely new type. It creates another name for an existing type.
=============================================================================== */
typedef int Integer; typedef float Decimal;
/* =============================================================================== TYPEDEF WITH STRUCT ===============================================================================
 * Without typedef: struct Employee employee1; With typedef: Employee employee1; This is extremely common in C programs. =============================================================================== */
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;
/* =============================================================================== TYPEDEF WITH UNION =============================================================================== */
typedef union {
    int integer;
    float decimal;
    char character;
} Value;
/* =============================================================================== TYPEDEF WITH ENUM =============================================================================== */
typedef enum {
    RED, GREEN, BLUE
} Color;
/* =============================================================================== FUNCTION: STRUCT DEMONSTRATION =============================================================================== */
void demonstrate_struct()
{ struct Student student; student.id = 101;
    /* strcpy() is used because name is a character array. */
    strcpy(student.name, "Narendra");
    student.marks = 95.5f;
    printf("\n");
    printf("===============================================================================\n");
    printf(" STRUCT\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("Data Type : struct Student\n");
    printf("Student ID : %d\n", student.id);
    printf("Student Name : %s\n", student.name);
    printf("Student Marks : %.2f\n", student.marks);
    printf("\n"); printf("Size of struct : %zu bytes\n", sizeof(student));
    printf("Address of : %p\n", (void *)&student);
    printf("Address of id : %p\n", (void *)&student.id);
    printf("Address of name : %p\n", (void *)student.name);
    printf("Address of marks: %p\n", (void *)&student.marks);
    /* =========================================================================== STRUCT MEMORY ===========================================================================
     * Each member has its own storage. Conceptually: struct Student
     *           ┌─────────────────────────────┐
     * │ id │    ├─────────────────────────────┤
     * │ name │  ├─────────────────────────────┤
     * │ marks │ └─────────────────────────────┘
     * IMPORTANT: The actual size may be larger than: sizeof(int) + sizeof(name) + sizeof(float) because the compiler may insert PADDING for memory alignment.
     * =========================================================================== */
}
/* =============================================================================== FUNCTION: UNION DEMONSTRATION =============================================================================== */
void demonstrate_union() {
    union Data data;
    printf("\n");
    printf("===============================================================================\n");
    printf(" UNION\n");
    printf("===============================================================================\n");
    printf("\n"); printf("Data Type : union Data\n");
    printf("Size of union : %zu bytes\n", sizeof(data));
    printf("Address of union: %p\n", (void *)&data);
    /* =========================================================================== UNION INTEGER =========================================================================== */
    data.i = 100;
    printf("\n");
    printf("After storing int:\n");
    printf("data.i : %d\n", data.i);
    printf("Address of i : %p\n", (void *)&data.i);
    /* =========================================================================== UNION FLOAT =========================================================================== */
    data.f = 99.99f;
    printf("\n");
    printf("After storing float:\n");
    printf("data.f : %.2f\n", data.f);
    printf("Address of f : %p\n", (void *)&data.f);
    /* =========================================================================== UNION CHARACTER =========================================================================== */
    data.c = 'A';
    printf("\n");
    printf("After storing char:\n");
    printf("data.c : %c\n", data.c);
    printf("Address of c : %p\n", (void *)&data.c);
    /* =========================================================================== IMPORTANT UNION CONCEPT ===========================================================================
     * Notice the addresses: &data.i &data.f &data.c They will normally be the same starting address. Why? Because all union members share the same memory.
     * Conceptually: union Data ┌───────────────────────────┐
     *                      │ │ │ SHARED MEMORY             │ │ │
     *                          └───────────────────────────┘ ↑ ↑ ↑ int float char STRUCT: Each member gets separate storage.
     *                          UNION: Members share storage.
     *       ========================================================================== */
} /* =============================================================================== FUNCTION: ENUM DEMONSTRATION =============================================================================== */
void demonstrate_enum(){
    enum Day today;
    today = WEDNESDAY;
    printf("\n");
    printf("===============================================================================\n");
    printf(" ENUM\n"); printf("===============================================================================\n");
    printf("\n");
    printf("Data Type : enum Day\n");
    printf("Today value : %d\n", today);
    printf("\n");
    printf("SUNDAY : %d\n", SUNDAY);
    printf("MONDAY : %d\n", MONDAY);
    printf("TUESDAY : %d\n", TUESDAY);
    printf("WEDNESDAY : %d\n", WEDNESDAY);
    printf("THURSDAY : %d\n", THURSDAY);
    printf("FRIDAY : %d\n", FRIDAY);
    printf("SATURDAY : %d\n", SATURDAY);
    printf("\n");
    printf("Size of enum : %zu bytes\n", sizeof(today));
    printf("Address : %p\n", (void *)&today);
    /* =========================================================================== ENUM CONCEPT ===========================================================================
     * enum gives meaningful names to integer constants. Instead of: int day = 3; we can write: enum Day day = WEDNESDAY; This makes the code easier to understand.
     * =========================================================================== */
}
/* =============================================================================== FUNCTION: TYPEDEF DEMONSTRATION =============================================================================== */
void demonstrate_typedef() {
    Integer age = 25;
    Decimal salary = 50000.50f;
    Employee employee; Value value; Color color;
    /* =========================================================================== INTEGER ALIAS =========================================================================== */
    printf("\n");
    printf("===============================================================================\n");
    printf(" TYPEDEF\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("typedef int Integer;\n");
    printf("Age : %d\n", age);
    printf("Size : %zu bytes\n", sizeof(age));
    printf("Address : %p\n", (void *)&age);
    /* =========================================================================== FLOAT ALIAS =========================================================================== */
    printf("\n");
    printf("typedef float Decimal;\n");
    printf("Salary : %.2f\n", salary);
    printf("Size : %zu bytes\n", sizeof(salary));
    printf("Address : %p\n", (void *)&salary);
    /* =========================================================================== TYPEDEF STRUCT =========================================================================== */
    employee.id = 501;
    strcpy(employee.name, "Rahul");
    employee.salary = 75000.0f;
    printf("\n");
    printf("Employee ID : %d\n", employee.id);
    printf("Employee Name : %s\n", employee.name);
    printf("Employee Salary : %.2f\n", employee.salary);
    printf("Employee Size : %zu bytes\n", sizeof(employee));
    printf("Employee Address: %p\n", (void *)&employee);
    /* =========================================================================== TYPEDEF UNION =========================================================================== */
    value.integer = 500; printf("\n");
    printf("Value integer : %d\n", value.integer);
    printf("Value Size : %zu bytes\n", sizeof(value));
    printf("Value Address : %p\n", (void *)&value);
    /* =========================================================================== TYPEDEF ENUM =========================================================================== */
    color = GREEN;
    printf("\n");
    printf("Color value : %d\n", color);
    printf("Color Size : %zu bytes\n", sizeof(color));
    printf("Color Address : %p\n", (void *)&color);
} /* =============================================================================== STRUCT VS UNION =============================================================================== */
void compare_struct_union() {
    struct Student student;
    union Data data; printf("\n");
    printf("===============================================================================\n");
    printf(" STRUCT VS UNION\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("STRUCT SIZE : %zu bytes\n", sizeof(student));
    printf("UNION SIZE : %zu bytes\n", sizeof(data));
    printf("\n"); printf("STRUCT MEMBERS:\n");
    printf(" id address : %p\n", (void *)&student.id);
    printf(" name address : %p\n", (void *)student.name);
    printf(" marks address : %p\n", (void *)&student.marks);
    printf("\n"); printf("UNION MEMBERS:\n");
    printf(" int address : %p\n", (void *)&data.i);
    printf(" float address : %p\n", (void *)&data.f);
    printf(" char address : %p\n", (void *)&data.c);
    /* =========================================================================== MAIN DIFFERENCE ===========================================================================
     * STRUCT: Every member has separate memory. Example:
     * struct    ┌─────────────┐
     * │ int  │  ├─────────────┤
     * │ float │ ├─────────────┤
     *  │ char │ └─────────────┘
     *  UNION: All members share the same memory. union ┌─────────────┐
     *                                                  │ int/float/  │
     *                                         │ char │ └─────────────┘
     * =========================================================================== */
} /* =============================================================================== USER-DEFINED TYPES SUMMARY =============================================================================== */
void userdefinedkeywords() {
    printf("\n");
    printf("===============================================================================\n");
    printf(" C USER-DEFINED TYPES\n");
    printf("===============================================================================\n");
    /* =========================================================================== STRUCT =========================================================================== */
    demonstrate_struct();
    /* =========================================================================== UNION =========================================================================== */
    demonstrate_union();
    /* =========================================================================== ENUM =========================================================================== */
    demonstrate_enum();
    /* =========================================================================== TYPEDEF =========================================================================== */
    demonstrate_typedef();
    /* =========================================================================== STRUCT VS UNION =========================================================================== */
    compare_struct_union();
    /* =========================================================================== FINAL SUMMARY TABLE =========================================================================== */
    printf("\n\n");
    printf("===============================================================================\n");
    printf(" FINAL SUMMARY\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("%-15s %-45s\n", "TYPE", "PURPOSE");
    printf("-------------------------------------------------------------------------------\n");
    printf("%-15s %-45s\n", "struct", "Groups different variables together");
    printf("%-15s %-45s\n", "union", "Multiple members share the same memory");
    printf("%-15s %-45s\n", "enum", "Creates named integer constants");
    printf("%-15s %-45s\n", "typedef", "Creates an alias for an existing type");
    printf("\n");
    printf("===============================================================================\n");
    printf(" IMPORTANT NOTES\n");
    printf("===============================================================================\n");
    printf("\n");
    printf("1. struct members have separate storage.\n");
    printf("2. union members share the same storage.\n");
    printf("3. enum values are named integer constants.\n");
    printf("4. typedef creates an alias, not a completely new type.\n");
    printf("5. C does not allow users to create new C keywords.\n");
    printf("6. struct/union size can include padding for alignment.\n");
    printf("7. union size is generally based on its largest member,\n");
    printf(" subject to alignment requirements.\n");
    printf("\n");
}
int main(void) {
    DataTypeKeywords();
    printf("=======================\nSTORAGE CLASSES ARE STRAT FROM HERE \n==========================================");
    stoargeclasses();
    printf("=================================\n User defined keywords\n==========================");
    userdefinedkeywords();
    return 0;
}