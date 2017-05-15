# Billiard #

## What's that ##

This is a mathematics puzzle based on billiard balls. Imagine the triangle of all billiard balls like this here

| Level |       |       |       |       |       |       |       |       |       |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|     4 |    11 |       |    12 |       |    13 |       |    14 |       |    15 |
|     3 |       |     7 |       |     8 |       |     9 |       |    10 |       |
|     2 |       |       |     4 |       |     5 |       |     6 |       |       |
|     1 |       |       |       |     2 |       |     3 |       |       |       |
|     0 |       |       |       |       |     1 |       |       |       |       |

On level 0, there is one ball with index 1 called `bottom ball`. On level 1, there are two balls above the `bottom ball`, one with index 2 (called `ball upper left`) and the second with index 3 (called `ball upper right`). The absolute difference (or the distance) between `ball upper left` and `ball upper right` must result in the `bottom ball`. See this example to understand:

| Level |       |       |       |
| :---: | :---: | :---: | :---: |
|     1 |     5 |       |     8 |
|     0 |       |     3 |       |

```
bottom ball = abs(ball upper left - ball upper right)

      3     =           |  5       -         8 |
```

This `group` of `two balls above one` is available at least 10 times for 15 balls. For each group this rule must be valid. An extended example looks like this one

| Level |       |       |       |       |       |
| :---: | :---: | :---: | :---: | :---: | :---: |
|     2 |     4 |       |    12 |       |     7 |
|     1 |       |     8 |       |     5 |       |
|     0 |       |       |     3 |       |       |

## Source ##

The C++ program in the folder `src` will solve this puzzle. There are currently two solvers present. 

The first one, `BilliardBruteForce` will perform a brute force method to solve this puzzle. There is a huge amount of permutations for all 15 balls - you need patience and a fast computer.

The second one, `BilliardStrategy` will follow a strategy to solve this puzzle. There are much less permutations required.

Additional solvers are planned for the various frameworks as mentioned in the `ToDo`-[section](#ToDo) on this page.

## Complete ruleset ##

Assume a function `CheckGroup` where you have as parameter the index of the lower ball, the upper left and the upper right. If the rule is applicable, the function returns true, otherwise false. Based on this the complete ruleset looks like this one:

```

Level1 = CheckGroup(0, 1, 2)
Level2 = Level1 & CheckGroup(2, 4, 5) &
         CheckGroup(3, 5, 6)
Level3 = Level2 & CheckGroup(4, 7, 8) &
         CheckGroup(5, 8, 9) &
         CheckGroup(6, 9, 10)
Level4 = Level3 & CheckGroup(7, 11, 12) &
         CheckGroup(8, 12, 13) &
         CheckGroup(9, 13, 14) &
         CheckGroup(10, 13, 15)
```

## License ##

[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](http://www.gnu.org/licenses/lgpl-3.0 "LGPL-3.0")

**Billiard** is distributed under the terms of the **GNU LESSER GENERAL PUBLIC LICENSE**, version 3.0. The text of the license is included in the file **LICENSE.TXT** in the project root.

## <a name="ToDo"></a>ToDo ##

Speed up the brute force. Evaluate these frameworks and apply a solution to the puzzle solver source.

* [Cuda](https://developer.nvidia.com/about-cuda)
* [OpenCL](https://www.khronos.org/opencl/)
* [OpenMP](http://www.openmp.org/)
