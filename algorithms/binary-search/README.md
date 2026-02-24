# Binary Search - Java vs C++

## Experiment

Comparing binary search performance between Java (JVM) and C++
on 10 million elements, 1000 searches.

## Results

| Language | Time   |
|----------|--------|
| Java (JVM) | 1 ms   |
| C++ (-O2) | 4 ms |

## Why is Java faster here?

C++ compiles code once, before runtime.  
JVM starts by interpreting bytecode, but the JIT compiler
monitors "hot" code and compiles it to native machine code
optimized for your specific CPU.

After 1000 searches, JVM has already compiled the hot path.
C++ would win at 10 searches - Java wins at 1000+.

## Key lessons

**Safe mid calculation:**
```java
int mid = left + (right - left) / 2; // ✅ prevents integer overflow
// NOT: (left + right) / 2           // ❌
```

**Common bug:**
```java
if (mid == target)           // ❌ mid is an INDEX, not a value!
if (collection[mid] == target) // ✅
```

## How to run

**Java:**
```bash
javac BinarySearch.java
java BinarySearch
```

**C++:**
```bash
g++ -O2 -o binary_search binary_search.cpp
./binary_search
```