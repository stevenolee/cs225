


## Score: 91/150 (60.67%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c hashes.cpp -o .objs/hashes.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c textfile.cpp -o .objs/textfile.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c tests/test-lp.cpp -o .objs/tests/test-lp.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c tests/test-dh.cpp -o .objs/tests/test-dh.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c tests/test-sc.cpp -o .objs/tests/test-sc.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/hashes.o .objs/textfile.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/test-lp.o .objs/tests/test-dh.o .objs/tests/test-sc.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lpthread -o test

```


### ✗ - [0/6] - LP::testRemoveEASY

- **Points**: 0 / 6

```
==3644== Memcheck, a memory error detector
==3644== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3644== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3644== Command: ./test -r xml "LP::testRemoveEASY"
==3644== 
==3644== 
==3644== HEAP SUMMARY:
==3644==     in use at exit: 32 bytes in 1 blocks
==3644==   total heap usage: 1,900 allocs, 1,899 frees, 242,741 bytes allocated
==3644== 
==3644== 32 bytes in 1 blocks are definitely lost in loss record 1 of 1
==3644==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==3644==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==3644==    by 0x430AB0: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:98)
==3644==    by 0x42AD87: ____C_A_T_C_H____T_E_S_T____0() (test-lp.cpp:19)
==3644==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==3644==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==3644==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==3644==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==3644==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==3644==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==3644==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==3644==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==3644== 
==3644== LEAK SUMMARY:
==3644==    definitely lost: 32 bytes in 1 blocks
==3644==    indirectly lost: 0 bytes in 0 blocks
==3644==      possibly lost: 0 bytes in 0 blocks
==3644==    still reachable: 0 bytes in 0 blocks
==3644==         suppressed: 0 bytes in 0 blocks
==3644== 
==3644== For counts of detected and suppressed errors, rerun with: -v
==3644== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="LP::testRemoveEASY" tags="[valgrind][weight=6]" filename="tests/test-lp.cpp" line="13">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✗ - [0/10] - LP::testRemoveHard

- **Points**: 0 / 10

```
==3700== Memcheck, a memory error detector
==3700== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3700== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3700== Command: ./test -r xml "LP::testRemoveHard"
==3700== 
==3700== 
==3700== HEAP SUMMARY:
==3700==     in use at exit: 96 bytes in 3 blocks
==3700==   total heap usage: 1,922 allocs, 1,919 frees, 243,445 bytes allocated
==3700== 
==3700== 96 bytes in 3 blocks are definitely lost in loss record 1 of 1
==3700==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==3700==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==3700==    by 0x430AB0: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:98)
==3700==    by 0x42BF99: ____C_A_T_C_H____T_E_S_T____2() (test-lp.cpp:48)
==3700==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==3700==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==3700==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==3700==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==3700==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==3700==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==3700==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==3700==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==3700== 
==3700== LEAK SUMMARY:
==3700==    definitely lost: 96 bytes in 3 blocks
==3700==    indirectly lost: 0 bytes in 0 blocks
==3700==      possibly lost: 0 bytes in 0 blocks
==3700==    still reachable: 0 bytes in 0 blocks
==3700==         suppressed: 0 bytes in 0 blocks
==3700== 
==3700== For counts of detected and suppressed errors, rerun with: -v
==3700== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="LP::testRemoveHard" tags="[valgrind][weight=10]" filename="tests/test-lp.cpp" line="35">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✗ - [0/7] - LP::testResizeOnce

- **Points**: 0 / 7

```
==3705== Memcheck, a memory error detector
==3705== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3705== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3705== Command: ./test -r xml "LP::testResizeOnce"
==3705== 
==3705== 
==3705== HEAP SUMMARY:
==3705==     in use at exit: 224 bytes in 7 blocks
==3705==   total heap usage: 2,054 allocs, 2,047 frees, 248,405 bytes allocated
==3705== 
==3705== 224 bytes in 7 blocks are definitely lost in loss record 1 of 1
==3705==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==3705==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==3705==    by 0x43197F: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::resizeTable() (lphashtable.cpp:310)
==3705==    by 0x430A6C: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:93)
==3705==    by 0x42CE55: ____C_A_T_C_H____T_E_S_T____4() (test-lp.cpp:72)
==3705==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==3705==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==3705==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==3705==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==3705==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==3705==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==3705==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==3705== 
==3705== LEAK SUMMARY:
==3705==    definitely lost: 224 bytes in 7 blocks
==3705==    indirectly lost: 0 bytes in 0 blocks
==3705==      possibly lost: 0 bytes in 0 blocks
==3705==    still reachable: 0 bytes in 0 blocks
==3705==         suppressed: 0 bytes in 0 blocks
==3705== 
==3705== For counts of detected and suppressed errors, rerun with: -v
==3705== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="LP::testResizeOnce" tags="[valgrind][weight=7]" filename="tests/test-lp.cpp" line="63">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="2" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="2" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [11/11] - LP::testResizeAll

- **Points**: 11 / 11

```
==3708== Memcheck, a memory error detector
==3708== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3708== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3708== Command: ./test -r xml "LP::testResizeAll"
==3708== 
==3708== 
==3708== HEAP SUMMARY:
==3708==     in use at exit: 0 bytes in 0 blocks
==3708==   total heap usage: 1,953 allocs, 1,953 frees, 241,893 bytes allocated
==3708== 
==3708== All heap blocks were freed -- no leaks are possible
==3708== 
==3708== For counts of detected and suppressed errors, rerun with: -v
==3708== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="LP::testResizeAll" tags="[valgrind][weight=11]" filename="tests/test-lp.cpp" line="84">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="2" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="2" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [6/6] - LP::testInsertEasy

- **Points**: 6 / 6

```
==3711== Memcheck, a memory error detector
==3711== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3711== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3711== Command: ./test -r xml "LP::testInsertEasy"
==3711== 
==3711== 
==3711== HEAP SUMMARY:
==3711==     in use at exit: 0 bytes in 0 blocks
==3711==   total heap usage: 1,899 allocs, 1,899 frees, 242,709 bytes allocated
==3711== 
==3711== All heap blocks were freed -- no leaks are possible
==3711== 
==3711== For counts of detected and suppressed errors, rerun with: -v
==3711== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="LP::testInsertEasy" tags="[valgrind][weight=6]" filename="tests/test-lp.cpp" line="111">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✗ - [0/10] - LP::testInsertHard

- **Points**: 0 / 10


```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="LP::testInsertHard" tags="[valgrind][weight=10]" filename="tests/test-lp.cpp" line="131">
      <Failure filename="tests/test-lp.cpp" line="143">
        Did not insert properly key: 'has'
      </Failure>
      <OverallResult success="false"/>
    </TestCase>
    <OverallResults successes="0" failures="1" expectedFailures="0"/>
  </Group>
  <OverallResults successes="0" failures="1" expectedFailures="0"/>
</Catch>

```


### ✗ - [0/6] - DH::testRemoveEASY

- **Points**: 0 / 6

```
==3715== Memcheck, a memory error detector
==3715== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3715== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3715== Command: ./test -r xml "DH::testRemoveEASY"
==3715== 
==3715== 
==3715== HEAP SUMMARY:
==3715==     in use at exit: 32 bytes in 1 blocks
==3715==   total heap usage: 1,899 allocs, 1,898 frees, 242,709 bytes allocated
==3715== 
==3715== 32 bytes in 1 blocks are definitely lost in loss record 1 of 1
==3715==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==3715==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==3715==    by 0x43C880: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:98)
==3715==    by 0x4366C7: ____C_A_T_C_H____T_E_S_T____0() (test-dh.cpp:21)
==3715==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==3715==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==3715==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==3715==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==3715==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==3715==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==3715==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==3715==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==3715== 
==3715== LEAK SUMMARY:
==3715==    definitely lost: 32 bytes in 1 blocks
==3715==    indirectly lost: 0 bytes in 0 blocks
==3715==      possibly lost: 0 bytes in 0 blocks
==3715==    still reachable: 0 bytes in 0 blocks
==3715==         suppressed: 0 bytes in 0 blocks
==3715== 
==3715== For counts of detected and suppressed errors, rerun with: -v
==3715== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="DH::testRemoveEASY" tags="[valgrind][weight=6]" filename="tests/test-dh.cpp" line="15">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✗ - [0/10] - DH::testRemoveHard

- **Points**: 0 / 10

```
==3743== Memcheck, a memory error detector
==3743== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3743== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3743== Command: ./test -r xml "DH::testRemoveHard"
==3743== 
==3743== 
==3743== HEAP SUMMARY:
==3743==     in use at exit: 64 bytes in 2 blocks
==3743==   total heap usage: 1,919 allocs, 1,917 frees, 243,349 bytes allocated
==3743== 
==3743== 64 bytes in 2 blocks are definitely lost in loss record 1 of 1
==3743==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==3743==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==3743==    by 0x43C880: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:98)
==3743==    by 0x4378D9: ____C_A_T_C_H____T_E_S_T____2() (test-dh.cpp:49)
==3743==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==3743==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==3743==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==3743==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==3743==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==3743==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==3743==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==3743==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==3743== 
==3743== LEAK SUMMARY:
==3743==    definitely lost: 64 bytes in 2 blocks
==3743==    indirectly lost: 0 bytes in 0 blocks
==3743==      possibly lost: 0 bytes in 0 blocks
==3743==    still reachable: 0 bytes in 0 blocks
==3743==         suppressed: 0 bytes in 0 blocks
==3743== 
==3743== For counts of detected and suppressed errors, rerun with: -v
==3743== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="DH::testRemoveHard" tags="[valgrind][weight=10]" filename="tests/test-dh.cpp" line="36">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [7/7] - DH::testResizeOnce

- **Points**: 7 / 7

```
==3748== Memcheck, a memory error detector
==3748== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3748== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3748== Command: ./test -r xml "DH::testResizeOnce"
==3748== 
==3748== 
==3748== HEAP SUMMARY:
==3748==     in use at exit: 0 bytes in 0 blocks
==3748==   total heap usage: 2,007 allocs, 2,007 frees, 246,901 bytes allocated
==3748== 
==3748== All heap blocks were freed -- no leaks are possible
==3748== 
==3748== For counts of detected and suppressed errors, rerun with: -v
==3748== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="DH::testResizeOnce" tags="[valgrind][weight=7]" filename="tests/test-dh.cpp" line="64">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="2" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="2" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [11/11] - DH::testResizeAll

- **Points**: 11 / 11

```
==3753== Memcheck, a memory error detector
==3753== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3753== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3753== Command: ./test -r xml "DH::testResizeAll"
==3753== 
==3753== 
==3753== HEAP SUMMARY:
==3753==     in use at exit: 0 bytes in 0 blocks
==3753==   total heap usage: 1,917 allocs, 1,917 frees, 240,741 bytes allocated
==3753== 
==3753== All heap blocks were freed -- no leaks are possible
==3753== 
==3753== For counts of detected and suppressed errors, rerun with: -v
==3753== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="DH::testResizeAll" tags="[valgrind][weight=11]" filename="tests/test-dh.cpp" line="85">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="2" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="2" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [6/6] - DH::testInsertEasy

- **Points**: 6 / 6

```
==3758== Memcheck, a memory error detector
==3758== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3758== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3758== Command: ./test -r xml "DH::testInsertEasy"
==3758== 
==3758== 
==3758== HEAP SUMMARY:
==3758==     in use at exit: 0 bytes in 0 blocks
==3758==   total heap usage: 1,898 allocs, 1,898 frees, 242,677 bytes allocated
==3758== 
==3758== All heap blocks were freed -- no leaks are possible
==3758== 
==3758== For counts of detected and suppressed errors, rerun with: -v
==3758== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="DH::testInsertEasy" tags="[valgrind][weight=6]" filename="tests/test-dh.cpp" line="111">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✗ - [0/10] - DH::testInsertHard

- **Points**: 0 / 10


```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="DH::testInsertHard" tags="[valgrind][weight=10]" filename="tests/test-dh.cpp" line="131">
      <Failure filename="tests/test-dh.cpp" line="143">
        Did not insert properly key: 'has'
      </Failure>
      <OverallResult success="false"/>
    </TestCase>
    <OverallResults successes="0" failures="1" expectedFailures="0"/>
  </Group>
  <OverallResults successes="0" failures="1" expectedFailures="0"/>
</Catch>

```


### ✓ - [6/6] - SC::testRemoveEASY

- **Points**: 6 / 6

```
==3766== Memcheck, a memory error detector
==3766== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3766== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3766== Command: ./test -r xml "SC::testRemoveEASY"
==3766== 
==3766== 
==3766== HEAP SUMMARY:
==3766==     in use at exit: 0 bytes in 0 blocks
==3766==   total heap usage: 1,899 allocs, 1,899 frees, 243,448 bytes allocated
==3766== 
==3766== All heap blocks were freed -- no leaks are possible
==3766== 
==3766== For counts of detected and suppressed errors, rerun with: -v
==3766== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="SC::testRemoveEASY" tags="[valgrind][weight=6]" filename="tests/test-sc.cpp" line="14">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [10/10] - SC::testRemoveHard

- **Points**: 10 / 10

```
==3775== Memcheck, a memory error detector
==3775== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3775== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3775== Command: ./test -r xml "SC::testRemoveHard"
==3775== 
==3775== 
==3775== HEAP SUMMARY:
==3775==     in use at exit: 0 bytes in 0 blocks
==3775==   total heap usage: 1,921 allocs, 1,921 frees, 244,328 bytes allocated
==3775== 
==3775== All heap blocks were freed -- no leaks are possible
==3775== 
==3775== For counts of detected and suppressed errors, rerun with: -v
==3775== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="SC::testRemoveHard" tags="[valgrind][weight=10]" filename="tests/test-sc.cpp" line="35">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [7/7] - SC::testResizeOnce

- **Points**: 7 / 7

```
==3843== Memcheck, a memory error detector
==3843== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3843== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3843== Command: ./test -r xml "SC::testResizeOnce"
==3843== 
==3843== 
==3843== HEAP SUMMARY:
==3843==     in use at exit: 0 bytes in 0 blocks
==3843==   total heap usage: 2,053 allocs, 2,053 frees, 251,816 bytes allocated
==3843== 
==3843== All heap blocks were freed -- no leaks are possible
==3843== 
==3843== For counts of detected and suppressed errors, rerun with: -v
==3843== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="SC::testResizeOnce" tags="[valgrind][weight=7]" filename="tests/test-sc.cpp" line="63">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="2" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="2" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [11/11] - SC::testResizeAll

- **Points**: 11 / 11

```
==3848== Memcheck, a memory error detector
==3848== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3848== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3848== Command: ./test -r xml "SC::testResizeAll"
==3848== 
==3848== 
==3848== HEAP SUMMARY:
==3848==     in use at exit: 0 bytes in 0 blocks
==3848==   total heap usage: 1,952 allocs, 1,952 frees, 245,000 bytes allocated
==3848== 
==3848== All heap blocks were freed -- no leaks are possible
==3848== 
==3848== For counts of detected and suppressed errors, rerun with: -v
==3848== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="SC::testResizeAll" tags="[valgrind][weight=11]" filename="tests/test-sc.cpp" line="84">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="2" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="2" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [6/6] - SC::testInsertEasy

- **Points**: 6 / 6

```
==3853== Memcheck, a memory error detector
==3853== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3853== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3853== Command: ./test -r xml "SC::testInsertEasy"
==3853== 
==3853== 
==3853== HEAP SUMMARY:
==3853==     in use at exit: 0 bytes in 0 blocks
==3853==   total heap usage: 1,898 allocs, 1,898 frees, 243,400 bytes allocated
==3853== 
==3853== All heap blocks were freed -- no leaks are possible
==3853== 
==3853== For counts of detected and suppressed errors, rerun with: -v
==3853== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="SC::testInsertEasy" tags="[valgrind][weight=6]" filename="tests/test-sc.cpp" line="110">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [10/10] - SC::testInsertHard

- **Points**: 10 / 10

```
==3858== Memcheck, a memory error detector
==3858== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3858== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==3858== Command: ./test -r xml "SC::testInsertHard"
==3858== 
==3858== 
==3858== HEAP SUMMARY:
==3858==     in use at exit: 0 bytes in 0 blocks
==3858==   total heap usage: 1,920 allocs, 1,920 frees, 244,280 bytes allocated
==3858== 
==3858== All heap blocks were freed -- no leaks are possible
==3858== 
==3858== For counts of detected and suppressed errors, rerun with: -v
==3858== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="SC::testInsertHard" tags="[valgrind][weight=10]" filename="tests/test-sc.cpp" line="130">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


---

This report was generated for **solee2** using **de49c12ead41eeb3e721c831d3f34f0f7e6efcf9** (from **November 5th 2018, 12:15:00 am**)
