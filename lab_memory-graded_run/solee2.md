


## Score: 100/100 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  tests/catchlib.cpp -o tests/catchlib.o
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  tests/unit_tests.cpp -o tests/unit_tests.o
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  tests/catch_main.cpp -o tests/catch_main.o
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  letter.cpp -o .objs/letter.o
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  room.cpp -o .objs/room.o
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  allocator.cpp -o .objs/allocator.o
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  fileio.cpp -o .objs/fileio.o
clang++ tests/catchlib.o tests/unit_tests.o tests/catch_main.o .objs/letter.o .objs/room.o .objs/allocator.o .objs/fileio.o -std=c++1y -stdlib=libc++ -lpthread  -o test

```


### ✓ - [5/5] - Test the constructor (valgrind)

- **Points**: 5 / 5

```
==26352== Memcheck, a memory error detector
==26352== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26352== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26352== Command: ./test -r xml "Test\ the\ constructor\ (valgrind)"
==26352== 
==26352== 
==26352== HEAP SUMMARY:
==26352==     in use at exit: 0 bytes in 0 blocks
==26352==   total heap usage: 2,522 allocs, 2,522 frees, 279,888 bytes allocated
==26352== 
==26352== All heap blocks were freed -- no leaks are possible
==26352== 
==26352== For counts of detected and suppressed errors, rerun with: -v
==26352== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Test the constructor (valgrind)" tags="[valgrind][weight=5]" filename="tests/unit_tests.cpp" line="17">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="0" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="0" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [5/5] - Test allocate() (valgrind)

- **Points**: 5 / 5

```
==26357== Memcheck, a memory error detector
==26357== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26357== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26357== Command: ./test -r xml "Test\ allocate()\ (valgrind)"
==26357== 
==26357== 
==26357== HEAP SUMMARY:
==26357==     in use at exit: 0 bytes in 0 blocks
==26357==   total heap usage: 2,522 allocs, 2,522 frees, 277,616 bytes allocated
==26357== 
==26357== All heap blocks were freed -- no leaks are possible
==26357== 
==26357== For counts of detected and suppressed errors, rerun with: -v
==26357== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Test allocate() (valgrind)" tags="[valgrind][weight=5]" filename="tests/unit_tests.cpp" line="24">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="0" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="0" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [20/20] - Test printRooms() (valgrind)

- **Points**: 20 / 20

```
==26385== Memcheck, a memory error detector
==26385== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26385== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26385== Command: ./test -r xml "Test\ printRooms()\ (valgrind)"
==26385== 
==26385== 
==26385== HEAP SUMMARY:
==26385==     in use at exit: 0 bytes in 0 blocks
==26385==   total heap usage: 2,526 allocs, 2,526 frees, 278,336 bytes allocated
==26385== 
==26385== All heap blocks were freed -- no leaks are possible
==26385== 
==26385== For counts of detected and suppressed errors, rerun with: -v
==26385== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Test printRooms() (valgrind)" tags="[valgrind][weight=20]" filename="tests/unit_tests.cpp" line="32">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="0" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="0" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [30/30] - Test printRooms() for overall output

- **Points**: 30 / 30





### ✓ - [40/40] - Test printRooms() for individual output

- **Points**: 40 / 40





---

This report was generated for **solee2** using **9532e72b280039597550c4d29bf82194e26b9581** (from **September 17th 2018, 1:00:00 am**)
