


## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from tests/basic.cpp:19:
In file included from tests/../util.h:3:
In file included from tests/../binarytree.h:14:
In file included from tests/../TreeTraversals/InorderTraversal.h:6:
tests/../TreeTraversals/TreeTraversal.h:21:76: fatal error: expected a qualified name after 'typename'
        class Iterator : std::iterator<std::forward_iterator_tag, typename BinaryTree<T>::Node*> {
                                                                           ^
1 error generated.
make: *** [basic.o] Error 1

```
```
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -c  tests/basic.cpp

```


---

This report was generated for **solee2** using **6a1f75212fa84e454379bbdafabca8ed04d5a18a** (from **October 8th 2018, 12:15:00 am**)
