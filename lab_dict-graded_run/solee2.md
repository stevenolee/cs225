


## Score: 85/100 (85.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c anagram_dict.cpp -o .objs/anagram_dict.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c fib.cpp -o .objs/fib.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c pronounce_dict.cpp -o .objs/pronounce_dict.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cartalk_puzzle.cpp -o .objs/cartalk_puzzle.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c common_words.cpp -o .objs/common_words.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c tests/unit_tests.cpp -o .objs/tests/unit_tests.o
clang++  -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -msse2 -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/anagram_dict.o .objs/fib.o .objs/pronounce_dict.o .objs/cartalk_puzzle.o .objs/common_words.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/unit_tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lpthread -o test

```


### ✓ - [15/15] - test_get_anagrams

- **Points**: 15 / 15





### ✓ - [15/15] - test_get_all_anagrams

- **Points**: 15 / 15





### ✓ - [10/10] - test_fib

- **Points**: 10 / 10





### ✓ - [10/10] - test_memoized_fib

- **Points**: 10 / 10





### ✓ - [10/10] - test_homophones

- **Points**: 10 / 10





### ✓ - [10/10] - test_cartalk_puzzle

- **Points**: 10 / 10





### ✓ - [15/15] - test_get_common_words_3

- **Points**: 15 / 15





### ✗ - [0/15] - test_get_common_words_999

- **Points**: 0 / 15


```
Original: canon == resultSet2
Expanded: { "of", "the" }
==
{ "I", "a", "and", "as", "be", "for", "had", "he", "her", "his", "in", "it", "not", "of", "she", "that", "the", "to", "was", "with", "you" }
```


---

This report was generated for **solee2** using **64608e2963b3dfc3f7ddd4fcd82b6fa69599357a** (from **November 28th 2018, 12:15:00 am**)
