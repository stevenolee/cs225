


## Score: 70/70 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
tests/basic.cpp:114:5: warning: delete called on 'Drawable' that is abstract but has non-virtual destructor [-Wdelete-non-virtual-dtor]
    delete truck;
    ^
tests/basic.cpp:134:5: warning: delete called on 'Drawable' that is abstract but has non-virtual destructor [-Wdelete-non-virtual-dtor]
    delete flower;
    ^
2 warnings generated.

```
```
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o cs225/PNG.o cs225/PNG.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o cs225/lodepng/lodepng.o cs225/lodepng/lodepng.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o cs225/HSLAPixel.o cs225/HSLAPixel.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o vector2.o vector2.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o line.o line.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o shape.o shape.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o rectangle.o rectangle.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o triangle.o triangle.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o circle.o circle.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o truck.o truck.cpp
clang++ -std=c++1y -stdlib=libc++ -g -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-delete-non-virtual-dtor -MMD -MP -c   -c -o flower.o flower.cpp
clang++ -std=c++1y -stdlib=libc++ -lpthread tests/basic.cpp cs225/PNG.o cs225/lodepng/lodepng.o cs225/HSLAPixel.o vector2.o line.o shape.o rectangle.o triangle.o circle.o truck.o flower.o -o test

```


### ✓ - [10/10] - test_virtual_perim

- **Points**: 10 / 10





### ✓ - [10/10] - test_virtual_area

- **Points**: 10 / 10





### ✓ - [20/20] - test_constructor

- **Points**: 20 / 20





### ✓ - [10/10] - test_truck_draw

- **Points**: 10 / 10





### ✓ - [20/20] - test_slicing

- **Points**: 20 / 20





---

This report was generated for **solee2** using **04c0daac9b65ac5eb984d8316aa0ff23b6a29c77** (from **September 24th 2018, 1:00:00 am**)
