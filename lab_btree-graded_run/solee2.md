


## Score: 35/45 (77.78%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c tests/basic.cpp -o .objs/tests/basic.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/basic.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lpthread -o test

```


### ✓ - [5/5] - test_insertion_idx_emp

- **Points**: 5 / 5





### ✓ - [5/5] - test_insertion_idx_small

- **Points**: 5 / 5





### ✗ - [0/5] - test_btree3_small

- **Points**: 0 / 5

```
==24100== Memcheck, a memory error detector
==24100== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24100== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24100== Command: ./test -r xml "test_btree3_small"
==24100== 
==24100== Conditional jump or move depends on uninitialised value(s)
==24100==    at 0x44316D: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:51)
==24100==    by 0x442D86: BTree<int, int>::find(int const&) const (btree.cpp:21)
==24100==    by 0x43F5CC: void verify_finds<int, int>(std::__1::vector<std::__1::pair<int, int>, std::__1::allocator<std::__1::pair<int, int> > >&, BTree<int, int>&) (basic.cpp:59)
==24100==    by 0x4268B1: ____C_A_T_C_H____T_E_S_T____4() (basic.cpp:120)
==24100==    by 0x47A8D2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==24100==    by 0x46B186: Catch::TestCase::invoke() const (catch.hpp:9771)
==24100==    by 0x46B0B8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==24100==    by 0x467E56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==24100==    by 0x4664B1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==24100==    by 0x46F213: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==24100==    by 0x46DC9E: Catch::Session::runInternal() (catch.hpp:9151)
==24100==    by 0x46D97E: Catch::Session::run() (catch.hpp:9108)
==24100== 
==24100== Conditional jump or move depends on uninitialised value(s)
==24100==    at 0x44316D: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:51)
==24100==    by 0x4431E3: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:56)
==24100==    by 0x442D86: BTree<int, int>::find(int const&) const (btree.cpp:21)
==24100==    by 0x43F5CC: void verify_finds<int, int>(std::__1::vector<std::__1::pair<int, int>, std::__1::allocator<std::__1::pair<int, int> > >&, BTree<int, int>&) (basic.cpp:59)
==24100==    by 0x4268B1: ____C_A_T_C_H____T_E_S_T____4() (basic.cpp:120)
==24100==    by 0x47A8D2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==24100==    by 0x46B186: Catch::TestCase::invoke() const (catch.hpp:9771)
==24100==    by 0x46B0B8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==24100==    by 0x467E56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==24100==    by 0x4664B1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==24100==    by 0x46F213: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==24100==    by 0x46DC9E: Catch::Session::runInternal() (catch.hpp:9151)
==24100== 
==24100== 
==24100== HEAP SUMMARY:
==24100==     in use at exit: 0 bytes in 0 blocks
==24100==   total heap usage: 1,765 allocs, 1,765 frees, 222,808 bytes allocated
==24100== 
==24100== All heap blocks were freed -- no leaks are possible
==24100== 
==24100== For counts of detected and suppressed errors, rerun with: -v
==24100== Use --track-origins=yes to see where uninitialised values come from
==24100== ERROR SUMMARY: 5 errors from 2 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="test_btree3_small" tags="[valgrind][weight=5]" filename="tests/basic.cpp" line="114">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="10" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="10" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [5/5] - test_btree3_large_seq

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree3_large_rand

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree64_large_seq

- **Points**: 5 / 5





### ✓ - [5/5] - test_btree64_large_rand

- **Points**: 5 / 5





### ✗ - [0/5] - test_btree128_med_rand

- **Points**: 0 / 5

```
==24126== Memcheck, a memory error detector
==24126== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24126== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24126== Command: ./test -r xml "test_btree128_med_rand"
==24126== 
==24126== Conditional jump or move depends on uninitialised value(s)
==24126==    at 0x44316D: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:51)
==24126==    by 0x442D86: BTree<int, int>::find(int const&) const (btree.cpp:21)
==24126==    by 0x43F5CC: void verify_finds<int, int>(std::__1::vector<std::__1::pair<int, int>, std::__1::allocator<std::__1::pair<int, int> > >&, BTree<int, int>&) (basic.cpp:59)
==24126==    by 0x427C39: ____C_A_T_C_H____T_E_S_T____14() (basic.cpp:175)
==24126==    by 0x47A8D2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==24126==    by 0x46B186: Catch::TestCase::invoke() const (catch.hpp:9771)
==24126==    by 0x46B0B8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==24126==    by 0x467E56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==24126==    by 0x4664B1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==24126==    by 0x46F213: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==24126==    by 0x46DC9E: Catch::Session::runInternal() (catch.hpp:9151)
==24126==    by 0x46D97E: Catch::Session::run() (catch.hpp:9108)
==24126== 
==24126== Conditional jump or move depends on uninitialised value(s)
==24126==    at 0x44316D: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:51)
==24126==    by 0x4431E3: BTree<int, int>::find(BTree<int, int>::BTreeNode const*, int const&) const (btree.cpp:56)
==24126==    by 0x442D86: BTree<int, int>::find(int const&) const (btree.cpp:21)
==24126==    by 0x43F5CC: void verify_finds<int, int>(std::__1::vector<std::__1::pair<int, int>, std::__1::allocator<std::__1::pair<int, int> > >&, BTree<int, int>&) (basic.cpp:59)
==24126==    by 0x427C39: ____C_A_T_C_H____T_E_S_T____14() (basic.cpp:175)
==24126==    by 0x47A8D2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:9870)
==24126==    by 0x46B186: Catch::TestCase::invoke() const (catch.hpp:9771)
==24126==    by 0x46B0B8: Catch::RunContext::invokeActiveTestCase() (catch.hpp:8655)
==24126==    by 0x467E56: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:8624)
==24126==    by 0x4664B1: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:8419)
==24126==    by 0x46F213: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:8967)
==24126==    by 0x46DC9E: Catch::Session::runInternal() (catch.hpp:9151)
==24126== 
==24126== 
==24126== HEAP SUMMARY:
==24126==     in use at exit: 0 bytes in 0 blocks
==24126==   total heap usage: 2,615 allocs, 2,615 frees, 1,575,760 bytes allocated
==24126== 
==24126== All heap blocks were freed -- no leaks are possible
==24126== 
==24126== For counts of detected and suppressed errors, rerun with: -v
==24126== Use --track-origins=yes to see where uninitialised values come from
==24126== ERROR SUMMARY: 9706 errors from 2 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="test_btree128_med_rand" tags="[valgrind][weight=5]" filename="tests/basic.cpp" line="169">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="20001" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="20001" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [5/5] - test_btree12_strings

- **Points**: 5 / 5





---

This report was generated for **solee2** using **4a178b6b73d82af679be2e86c21c8f4001394eee** (from **October 29th 2018, 12:15:00 am**)
