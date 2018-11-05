


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
==17255== Memcheck, a memory error detector
==17255== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17255== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17255== Command: ./test -r xml "LP::testRemoveEASY"
==17255== 
==17255== 
==17255== HEAP SUMMARY:
==17255==     in use at exit: 32 bytes in 1 blocks
==17255==   total heap usage: 1,900 allocs, 1,899 frees, 242,741 bytes allocated
==17255== 
==17255== 32 bytes in 1 blocks are definitely lost in loss record 1 of 1
==17255==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==17255==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==17255==    by 0x430AB0: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:98)
==17255==    by 0x42AD87: ____C_A_T_C_H____T_E_S_T____0() (test-lp.cpp:19)
==17255==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==17255==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==17255==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==17255==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==17255==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==17255==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==17255==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==17255==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==17255== 
==17255== LEAK SUMMARY:
==17255==    definitely lost: 32 bytes in 1 blocks
==17255==    indirectly lost: 0 bytes in 0 blocks
==17255==      possibly lost: 0 bytes in 0 blocks
==17255==    still reachable: 0 bytes in 0 blocks
==17255==         suppressed: 0 bytes in 0 blocks
==17255== 
==17255== For counts of detected and suppressed errors, rerun with: -v
==17255== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

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
==17258== Memcheck, a memory error detector
==17258== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17258== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17258== Command: ./test -r xml "LP::testRemoveHard"
==17258== 
==17258== 
==17258== HEAP SUMMARY:
==17258==     in use at exit: 96 bytes in 3 blocks
==17258==   total heap usage: 1,922 allocs, 1,919 frees, 243,445 bytes allocated
==17258== 
==17258== 96 bytes in 3 blocks are definitely lost in loss record 1 of 1
==17258==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==17258==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==17258==    by 0x430AB0: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:98)
==17258==    by 0x42BF99: ____C_A_T_C_H____T_E_S_T____2() (test-lp.cpp:48)
==17258==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==17258==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==17258==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==17258==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==17258==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==17258==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==17258==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==17258==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==17258== 
==17258== LEAK SUMMARY:
==17258==    definitely lost: 96 bytes in 3 blocks
==17258==    indirectly lost: 0 bytes in 0 blocks
==17258==      possibly lost: 0 bytes in 0 blocks
==17258==    still reachable: 0 bytes in 0 blocks
==17258==         suppressed: 0 bytes in 0 blocks
==17258== 
==17258== For counts of detected and suppressed errors, rerun with: -v
==17258== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

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
==17261== Memcheck, a memory error detector
==17261== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17261== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17261== Command: ./test -r xml "LP::testResizeOnce"
==17261== 
==17261== 
==17261== HEAP SUMMARY:
==17261==     in use at exit: 224 bytes in 7 blocks
==17261==   total heap usage: 2,054 allocs, 2,047 frees, 248,405 bytes allocated
==17261== 
==17261== 224 bytes in 7 blocks are definitely lost in loss record 1 of 1
==17261==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==17261==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==17261==    by 0x43197F: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::resizeTable() (lphashtable.cpp:310)
==17261==    by 0x430A6C: LPHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (lphashtable.cpp:93)
==17261==    by 0x42CE55: ____C_A_T_C_H____T_E_S_T____4() (test-lp.cpp:72)
==17261==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==17261==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==17261==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==17261==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==17261==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==17261==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==17261==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==17261== 
==17261== LEAK SUMMARY:
==17261==    definitely lost: 224 bytes in 7 blocks
==17261==    indirectly lost: 0 bytes in 0 blocks
==17261==      possibly lost: 0 bytes in 0 blocks
==17261==    still reachable: 0 bytes in 0 blocks
==17261==         suppressed: 0 bytes in 0 blocks
==17261== 
==17261== For counts of detected and suppressed errors, rerun with: -v
==17261== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

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
==17264== Memcheck, a memory error detector
==17264== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17264== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17264== Command: ./test -r xml "LP::testResizeAll"
==17264== 
==17264== 
==17264== HEAP SUMMARY:
==17264==     in use at exit: 0 bytes in 0 blocks
==17264==   total heap usage: 1,953 allocs, 1,953 frees, 241,893 bytes allocated
==17264== 
==17264== All heap blocks were freed -- no leaks are possible
==17264== 
==17264== For counts of detected and suppressed errors, rerun with: -v
==17264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17267== Memcheck, a memory error detector
==17267== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17267== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17267== Command: ./test -r xml "LP::testInsertEasy"
==17267== 
==17267== 
==17267== HEAP SUMMARY:
==17267==     in use at exit: 0 bytes in 0 blocks
==17267==   total heap usage: 1,899 allocs, 1,899 frees, 242,709 bytes allocated
==17267== 
==17267== All heap blocks were freed -- no leaks are possible
==17267== 
==17267== For counts of detected and suppressed errors, rerun with: -v
==17267== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17271== Memcheck, a memory error detector
==17271== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17271== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17271== Command: ./test -r xml "DH::testRemoveEASY"
==17271== 
==17271== 
==17271== HEAP SUMMARY:
==17271==     in use at exit: 32 bytes in 1 blocks
==17271==   total heap usage: 1,899 allocs, 1,898 frees, 242,709 bytes allocated
==17271== 
==17271== 32 bytes in 1 blocks are definitely lost in loss record 1 of 1
==17271==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==17271==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==17271==    by 0x43C880: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:98)
==17271==    by 0x4366C7: ____C_A_T_C_H____T_E_S_T____0() (test-dh.cpp:21)
==17271==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==17271==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==17271==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==17271==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==17271==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==17271==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==17271==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==17271==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==17271== 
==17271== LEAK SUMMARY:
==17271==    definitely lost: 32 bytes in 1 blocks
==17271==    indirectly lost: 0 bytes in 0 blocks
==17271==      possibly lost: 0 bytes in 0 blocks
==17271==    still reachable: 0 bytes in 0 blocks
==17271==         suppressed: 0 bytes in 0 blocks
==17271== 
==17271== For counts of detected and suppressed errors, rerun with: -v
==17271== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

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
==17274== Memcheck, a memory error detector
==17274== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17274== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17274== Command: ./test -r xml "DH::testRemoveHard"
==17274== 
==17274== 
==17274== HEAP SUMMARY:
==17274==     in use at exit: 64 bytes in 2 blocks
==17274==   total heap usage: 1,919 allocs, 1,917 frees, 243,349 bytes allocated
==17274== 
==17274== 64 bytes in 2 blocks are definitely lost in loss record 1 of 1
==17274==    at 0x4C29C23: malloc (vg_replace_malloc.c:299)
==17274==    by 0x50EED29: operator new(unsigned long) (in /class/cs225/lm35/lib/libc++.so.1.0)
==17274==    by 0x43C880: DHHashTable<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>::insert(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int const&) (dhhashtable.cpp:98)
==17274==    by 0x4378D9: ____C_A_T_C_H____T_E_S_T____2() (test-dh.cpp:49)
==17274==    by 0x476B02: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==17274==    by 0x4673B6: Catch::TestCase::invoke() const (catch.hpp:9771)
==17274==    by 0x4672E8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==17274==    by 0x464086: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==17274==    by 0x4626E1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==17274==    by 0x46B443: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==17274==    by 0x469ECE: Catch::Session::runInternal() (catch.hpp:9151)
==17274==    by 0x469BAE: Catch::Session::run() (catch.hpp:9108)
==17274== 
==17274== LEAK SUMMARY:
==17274==    definitely lost: 64 bytes in 2 blocks
==17274==    indirectly lost: 0 bytes in 0 blocks
==17274==      possibly lost: 0 bytes in 0 blocks
==17274==    still reachable: 0 bytes in 0 blocks
==17274==         suppressed: 0 bytes in 0 blocks
==17274== 
==17274== For counts of detected and suppressed errors, rerun with: -v
==17274== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

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
==17277== Memcheck, a memory error detector
==17277== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17277== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17277== Command: ./test -r xml "DH::testResizeOnce"
==17277== 
==17277== 
==17277== HEAP SUMMARY:
==17277==     in use at exit: 0 bytes in 0 blocks
==17277==   total heap usage: 2,007 allocs, 2,007 frees, 246,901 bytes allocated
==17277== 
==17277== All heap blocks were freed -- no leaks are possible
==17277== 
==17277== For counts of detected and suppressed errors, rerun with: -v
==17277== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17280== Memcheck, a memory error detector
==17280== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17280== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17280== Command: ./test -r xml "DH::testResizeAll"
==17280== 
==17280== 
==17280== HEAP SUMMARY:
==17280==     in use at exit: 0 bytes in 0 blocks
==17280==   total heap usage: 1,917 allocs, 1,917 frees, 240,741 bytes allocated
==17280== 
==17280== All heap blocks were freed -- no leaks are possible
==17280== 
==17280== For counts of detected and suppressed errors, rerun with: -v
==17280== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17283== Memcheck, a memory error detector
==17283== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17283== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17283== Command: ./test -r xml "DH::testInsertEasy"
==17283== 
==17283== 
==17283== HEAP SUMMARY:
==17283==     in use at exit: 0 bytes in 0 blocks
==17283==   total heap usage: 1,898 allocs, 1,898 frees, 242,677 bytes allocated
==17283== 
==17283== All heap blocks were freed -- no leaks are possible
==17283== 
==17283== For counts of detected and suppressed errors, rerun with: -v
==17283== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17288== Memcheck, a memory error detector
==17288== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17288== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17288== Command: ./test -r xml "SC::testRemoveEASY"
==17288== 
==17288== 
==17288== HEAP SUMMARY:
==17288==     in use at exit: 0 bytes in 0 blocks
==17288==   total heap usage: 1,899 allocs, 1,899 frees, 243,448 bytes allocated
==17288== 
==17288== All heap blocks were freed -- no leaks are possible
==17288== 
==17288== For counts of detected and suppressed errors, rerun with: -v
==17288== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17292== Memcheck, a memory error detector
==17292== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17292== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17292== Command: ./test -r xml "SC::testRemoveHard"
==17292== 
==17292== 
==17292== HEAP SUMMARY:
==17292==     in use at exit: 0 bytes in 0 blocks
==17292==   total heap usage: 1,921 allocs, 1,921 frees, 244,328 bytes allocated
==17292== 
==17292== All heap blocks were freed -- no leaks are possible
==17292== 
==17292== For counts of detected and suppressed errors, rerun with: -v
==17292== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17296== Memcheck, a memory error detector
==17296== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17296== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17296== Command: ./test -r xml "SC::testResizeOnce"
==17296== 
==17296== 
==17296== HEAP SUMMARY:
==17296==     in use at exit: 0 bytes in 0 blocks
==17296==   total heap usage: 2,053 allocs, 2,053 frees, 251,816 bytes allocated
==17296== 
==17296== All heap blocks were freed -- no leaks are possible
==17296== 
==17296== For counts of detected and suppressed errors, rerun with: -v
==17296== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17301== Memcheck, a memory error detector
==17301== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17301== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17301== Command: ./test -r xml "SC::testResizeAll"
==17301== 
==17301== 
==17301== HEAP SUMMARY:
==17301==     in use at exit: 0 bytes in 0 blocks
==17301==   total heap usage: 1,952 allocs, 1,952 frees, 245,000 bytes allocated
==17301== 
==17301== All heap blocks were freed -- no leaks are possible
==17301== 
==17301== For counts of detected and suppressed errors, rerun with: -v
==17301== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17304== Memcheck, a memory error detector
==17304== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17304== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17304== Command: ./test -r xml "SC::testInsertEasy"
==17304== 
==17304== 
==17304== HEAP SUMMARY:
==17304==     in use at exit: 0 bytes in 0 blocks
==17304==   total heap usage: 1,898 allocs, 1,898 frees, 243,400 bytes allocated
==17304== 
==17304== All heap blocks were freed -- no leaks are possible
==17304== 
==17304== For counts of detected and suppressed errors, rerun with: -v
==17304== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
==17307== Memcheck, a memory error detector
==17307== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17307== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==17307== Command: ./test -r xml "SC::testInsertHard"
==17307== 
==17307== 
==17307== HEAP SUMMARY:
==17307==     in use at exit: 0 bytes in 0 blocks
==17307==   total heap usage: 1,920 allocs, 1,920 frees, 244,280 bytes allocated
==17307== 
==17307== All heap blocks were freed -- no leaks are possible
==17307== 
==17307== For counts of detected and suppressed errors, rerun with: -v
==17307== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

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
