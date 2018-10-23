


## Score: 25/50 (50.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c coloredout.cpp -o .objs/coloredout.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c tests/basic.cpp -o .objs/tests/basic.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/coloredout.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/basic.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lpthread -o test

```


### ✓ - [10/10] - test_find

- **Points**: 10 / 10

```
==19525== Memcheck, a memory error detector
==19525== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==19525== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==19525== Command: ./test -r xml "test_find"
==19525== 
==19525== 
==19525== HEAP SUMMARY:
==19525==     in use at exit: 0 bytes in 0 blocks
==19525==   total heap usage: 1,697 allocs, 1,697 frees, 219,080 bytes allocated
==19525== 
==19525== All heap blocks were freed -- no leaks are possible
==19525== 
==19525== For counts of detected and suppressed errors, rerun with: -v
==19525== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="test_find" tags="[valgrind][weight=10]" filename="tests/basic.cpp" line="34">
      <OverallResult success="true">
        <StdOut>
______________________________________for rotateRight (r, m, l): 0x60a7b600x60a7ad00x60a7b60
______________________________________for rotateRight (r, m, l): 0x60a7bf00x60a7b600x60a7bf0
        </StdOut>
      </OverallResult>
    </TestCase>
    <OverallResults successes="5" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="5" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [5/5] - test_insert_small

- **Points**: 5 / 5





### ✓ - [10/10] - test_insert_find

- **Points**: 10 / 10





### ✗ - [0/10] - test_insert_big

- **Points**: 0 / 10


```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="test_insert_big" tags="[valgrind][weight=10]" filename="tests/basic.cpp" line="104">
      <Expression success="false" type="REQUIRE" filename="tests/basic.cpp" line="138">
        <Original>
          solnFuncCalls == funcCalls
        </Original>
        <Expanded>
          { "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateLeft", "rotateLeft", "rotateLeft" }
==
{ "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateRight", "rotateLeft", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeftRight", "rotateLeft", "rotateRight", "rotateRight", "rotateLeft", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeftRight", "rotateLeft", "rotateRight", "rotateRight" }
        </Expanded>
      </Expression>
      <OverallResult success="false"/>
    </TestCase>
    <OverallResults successes="0" failures="1" expectedFailures="0"/>
  </Group>
  <OverallResults successes="0" failures="1" expectedFailures="0"/>
</Catch>

```


### ✗ - [0/5] - test_remove_small

- **Points**: 0 / 5


```
Original: tree_equals_output(str, "tests/soln_test_remove_small.out")
Expanded: false
```


### ✗ - [0/10] - test_remove_big

- **Points**: 0 / 10


```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="test_remove_big" tags="[valgrind][weight=10]" filename="tests/basic.cpp" line="172">
      <FatalErrorCondition filename="tests/basic.cpp" line="172">
        SIGSEGV - Segmentation violation signal
      </FatalErrorCondition>
      <OverallResult success="false"/>
    </TestCase>
    <OverallResults successes="0" failures="1" expectedFailures="0"/>
  </Group>
  <OverallResults successes="0" failures="1" expectedFailures="0"/>
</Catch>

```


---

This report was generated for **solee2** using **743dc6d4f06e2b300241a3c6923e36a7cdef9258** (from **October 22nd 2018, 12:15:00 am**)
