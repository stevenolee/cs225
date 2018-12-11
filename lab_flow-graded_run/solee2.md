


## Score: 10/10 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c graph.cpp -o .objs/graph.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c NetworkFlow.cpp -o .objs/NetworkFlow.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c tests/unit_tests.cpp -o .objs/tests/unit_tests.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/graph.o .objs/NetworkFlow.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/unit_tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lpthread -o test

```


### ✓ - [1/1] - Graph a - 4 -> b  has flow of 4.

- **Points**: 1 / 1

```
==23070== Memcheck, a memory error detector
==23070== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23070== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23070== Command: ./test -r xml "Graph\ a\ -\ 4\ -\>\ b\ \ has\ flow\ of\ 4."
==23070== 
==23070== 
==23070== HEAP SUMMARY:
==23070==     in use at exit: 0 bytes in 0 blocks
==23070==   total heap usage: 2,023 allocs, 2,023 frees, 237,096 bytes allocated
==23070== 
==23070== All heap blocks were freed -- no leaks are possible
==23070== 
==23070== For counts of detected and suppressed errors, rerun with: -v
==23070== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Graph a - 4 -> b  has flow of 4." tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="10">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing flow through two pipes - secret test

- **Points**: 1 / 1

```
==23076== Memcheck, a memory error detector
==23076== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23076== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23076== Command: ./test -r xml "Testing\ flow\ through\ two\ pipes\ -\ secret\ test"
==23076== 
==23076== 
==23076== HEAP SUMMARY:
==23076==     in use at exit: 0 bytes in 0 blocks
==23076==   total heap usage: 2,066 allocs, 2,066 frees, 240,416 bytes allocated
==23076== 
==23076== All heap blocks were freed -- no leaks are possible
==23076== 
==23076== For counts of detected and suppressed errors, rerun with: -v
==23076== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing flow through two pipes - secret test" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="23">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Graph a - 10 -> b  has flow of 10.

- **Points**: 1 / 1

```
==23084== Memcheck, a memory error detector
==23084== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23084== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23084== Command: ./test -r xml "Graph\ a\ -\ 10\ -\>\ b\ \ has\ flow\ of\ 10."
==23084== 
==23084== 
==23084== HEAP SUMMARY:
==23084==     in use at exit: 0 bytes in 0 blocks
==23084==   total heap usage: 2,023 allocs, 2,023 frees, 237,096 bytes allocated
==23084== 
==23084== All heap blocks were freed -- no leaks are possible
==23084== 
==23084== For counts of detected and suppressed errors, rerun with: -v
==23084== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Graph a - 10 -> b  has flow of 10." tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="40">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing flow through two pipes

- **Points**: 1 / 1

```
==23090== Memcheck, a memory error detector
==23090== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23090== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23090== Command: ./test -r xml "Testing\ flow\ through\ two\ pipes"
==23090== 
==23090== 
==23090== HEAP SUMMARY:
==23090==     in use at exit: 0 bytes in 0 blocks
==23090==   total heap usage: 2,066 allocs, 2,066 frees, 240,192 bytes allocated
==23090== 
==23090== All heap blocks were freed -- no leaks are possible
==23090== 
==23090== For counts of detected and suppressed errors, rerun with: -v
==23090== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing flow through two pipes" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="53">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing simple backflow - secret

- **Points**: 1 / 1

```
==23098== Memcheck, a memory error detector
==23098== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23098== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23098== Command: ./test -r xml "Testing\ simple\ backflow\ -\ secret"
==23098== 
==23098== 
==23098== HEAP SUMMARY:
==23098==     in use at exit: 0 bytes in 0 blocks
==23098==   total heap usage: 2,148 allocs, 2,148 frees, 248,248 bytes allocated
==23098== 
==23098== All heap blocks were freed -- no leaks are possible
==23098== 
==23098== For counts of detected and suppressed errors, rerun with: -v
==23098== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing simple backflow - secret" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="70">
      <OverallResult success="true">
        <StdErr>
\x1B[1;31m[Graph Error]\x1B[0m getEdgeWeight called on nonexistent edge c -> b
\x1B[1;31m[Graph Error]\x1B[0m setEdgeWeight called on nonexistent edge d -> b
\x1B[1;31m[Graph Error]\x1B[0m setEdgeWeight called on nonexistent edge d -> a
        </StdErr>
      </OverallResult>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing simple backflow

- **Points**: 1 / 1

```
==23102== Memcheck, a memory error detector
==23102== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23102== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23102== Command: ./test -r xml "Testing\ simple\ backflow"
==23102== 
==23102== 
==23102== HEAP SUMMARY:
==23102==     in use at exit: 0 bytes in 0 blocks
==23102==   total heap usage: 2,125 allocs, 2,125 frees, 243,296 bytes allocated
==23102== 
==23102== All heap blocks were freed -- no leaks are possible
==23102== 
==23102== For counts of detected and suppressed errors, rerun with: -v
==23102== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing simple backflow" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="93">
      <OverallResult success="true">
        <StdErr>
\x1B[1;31m[Graph Error]\x1B[0m getEdgeWeight called on nonexistent edge c -> b
\x1B[1;31m[Graph Error]\x1B[0m setEdgeWeight called on nonexistent edge d -> b
        </StdErr>
      </OverallResult>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing full pipe usage - secret

- **Points**: 1 / 1

```
==23106== Memcheck, a memory error detector
==23106== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23106== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23106== Command: ./test -r xml "Testing\ full\ pipe\ usage\ -\ secret"
==23106== 
==23106== 
==23106== HEAP SUMMARY:
==23106==     in use at exit: 0 bytes in 0 blocks
==23106==   total heap usage: 2,146 allocs, 2,146 frees, 247,104 bytes allocated
==23106== 
==23106== All heap blocks were freed -- no leaks are possible
==23106== 
==23106== For counts of detected and suppressed errors, rerun with: -v
==23106== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing full pipe usage - secret" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="114">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing full pipe usage

- **Points**: 1 / 1

```
==23117== Memcheck, a memory error detector
==23117== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23117== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23117== Command: ./test -r xml "Testing\ full\ pipe\ usage"
==23117== 
==23117== 
==23117== HEAP SUMMARY:
==23117==     in use at exit: 0 bytes in 0 blocks
==23117==   total heap usage: 2,160 allocs, 2,160 frees, 245,312 bytes allocated
==23117== 
==23117== All heap blocks were freed -- no leaks are possible
==23117== 
==23117== For counts of detected and suppressed errors, rerun with: -v
==23117== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing full pipe usage" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="139">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing 3 x 3 plumbing - secret

- **Points**: 1 / 1

```
==23131== Memcheck, a memory error detector
==23131== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23131== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23131== Command: ./test -r xml "Testing\ 3\ x\ 3\ plumbing\ -\ secret"
==23131== 
==23131== 
==23131== HEAP SUMMARY:
==23131==     in use at exit: 0 bytes in 0 blocks
==23131==   total heap usage: 2,230 allocs, 2,230 frees, 254,944 bytes allocated
==23131== 
==23131== All heap blocks were freed -- no leaks are possible
==23131== 
==23131== For counts of detected and suppressed errors, rerun with: -v
==23131== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing 3 x 3 plumbing - secret" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="164">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


### ✓ - [1/1] - Testing 3 x 3 plumbing

- **Points**: 1 / 1

```
==23146== Memcheck, a memory error detector
==23146== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23146== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==23146== Command: ./test -r xml "Testing\ 3\ x\ 3\ plumbing"
==23146== 
==23146== 
==23146== HEAP SUMMARY:
==23146==     in use at exit: 0 bytes in 0 blocks
==23146==   total heap usage: 2,231 allocs, 2,231 frees, 252,984 bytes allocated
==23146== 
==23146== All heap blocks were freed -- no leaks are possible
==23146== 
==23146== For counts of detected and suppressed errors, rerun with: -v
==23146== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
```
<?xml version="1.0" encoding="UTF-8"?>
<Catch name="test">
  <Group name="test">
    <TestCase name="Testing 3 x 3 plumbing" tags="[valgrind][weight=1]" filename="tests/unit_tests.cpp" line="203">
      <OverallResult success="true"/>
    </TestCase>
    <OverallResults successes="1" failures="0" expectedFailures="0"/>
  </Group>
  <OverallResults successes="1" failures="0" expectedFailures="0"/>
</Catch>

```


---

This report was generated for **solee2** using **c2bed9a2ddd627c1f39850205e253f5759d884a4** (from **December 10th 2018, 12:15:00 am**)
