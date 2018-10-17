


## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from FloodFilledImage.cpp:6:
./imageTraversal/ImageTraversal.h:35:25: fatal error: expected ')'
        Iterator(ImageTraversal<T> & traversal, Point startPoint, double t) 
                               ^
./imageTraversal/ImageTraversal.h:35:10: note: to match this '('
        Iterator(ImageTraversal<T> & traversal, Point startPoint, double t) 
                ^
1 error generated.
make: *** [.objs/FloodFilledImage.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -g -c Point.cpp -o .objs/Point.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -MMD -MP -g -c FloodFilledImage.cpp -o .objs/FloodFilledImage.o

```


---

This report was generated for **solee2** using **055b607034579a985ca8def9cba70b033deec9d5** (from **October 17th 2018, 12:05:00 am**)
