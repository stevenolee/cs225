


## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from FloodFilledImage.cpp:6:
./imageTraversal/ImageTraversal.h:35:11: fatal error: unknown type name 'ImageIterator'
        Iterator(ImageIterator* trav, const PNG& png, Point startPoint, double t);
                 ^
1 error generated.
make: *** [.objs/FloodFilledImage.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -g -c Point.cpp -o .objs/Point.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -g -c FloodFilledImage.cpp -o .objs/FloodFilledImage.o

```


---

This report was generated for **solee2** using **d1d8a36a8bcce45d584d4a3fe0b44476717b3ee2** (from **October 21st 2018, 12:05:00 am**)
