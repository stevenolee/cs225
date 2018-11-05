


## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from maptiles.cpp:8:
In file included from ./maptiles.h:16:
In file included from ./kdtree.h:274:
./kdtree.hpp:108:1: fatal error: unknown type name 'KDTreeNode'
KDTreeNode* KDTree<Dim>::insert(KDTreeNode* rootNode, KDTreeNode* newNode, int dimension){
^
1 error generated.
make: *** [.objs/maptiles.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c maptiles.cpp -o .objs/maptiles.o

```


---

This report was generated for **solee2** using **de49c12ead41eeb3e721c831d3f34f0f7e6efcf9** (from **November 5th 2018, 12:05:00 am**)
