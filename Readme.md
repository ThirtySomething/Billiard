# Billiard #

## What's that ##

Imagine the triangle of all billiard balls like this here

| Level |       |       |       |       |       |       |       |       |       |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|     4 |    11 |       |    12 |       |    13 |       |    14 |       |    15 |
|     3 |       |     7 |       |     8 |       |     9 |       |    10 |       |
|     2 |       |       |     4 |       |     5 |       |     6 |       |       |
|     1 |       |       |       |     2 |       |     3 |       |       |       |
|     0 |       |       |       |       |     1 |       |       |       |       |

On level 0, there is one ball with index 1. On level 1, there are two balls above the ball of level 0, one with index 2 and the second with index 3. The absolute difference between the numbers of the two balls on level 1 will result in the number of the ball on level 0. Simple example to understand:

| Level |       |       |       |
| :---: | :---: | :---: | :---: |
|     1 |     5 |       |     8 |
|     0 |       |     3 |       |

```
Ball on level 0 = abs(ball upper left - ball upper right)

              3 =             5       -       8
```

This *group* of *two balls above one* is available at least 10 times. For each group the rule has to be valid. An extended example looks like this one

| Level |       |       |       |       |       |
| :---: | :---: | :---: | :---: | :---: | :---: |
|     2 |     4 |       |    12 |       |     7 |
|     1 |       |     8 |       |     5 |       |
|     0 |       |       |     3 |       |       |

## Complete ruleset ##

Assume a function `CheckTriple` where you have as parameter the index of the lower ball, the upper left and the upper right. If the rule is applicable, the function returns true, otherwise false. Based on this the complete ruleset looks like this one:

```

Level1 = CheckTriple(0, 1, 2)
Level2 = CheckTriple(2, 4, 5) &
         CheckTriple(3, 5, 6)
Level3 = CheckTriple(4, 7, 8) &
         CheckTriple(5, 8, 9) &
         CheckTriple(6, 9, 10)
Level4 = CheckTriple(7, 11, 12) &
         CheckTriple(8, 12, 13) &
         CheckTriple(9, 13, 14) &
         CheckTriple(10, 13, 15)
```

And a valid solution for the puzzle will be

```

ValidSolution = Level1 & Level2 & Level3 & Level4
```

## Source ##

The C++ programm int the folder `src` will run through all possible combinations of these virtual billard balls and will apply the rules. The goal is to figure out all possible solutions for this task.

## License ##

[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](http://www.gnu.org/licenses/lgpl-3.0 "LGPL-3.0")

**Billiard** is distributed under the terms of the **GNU LESSER GENERAL PUBLIC LICENSE**, version 3.0. The text of the license is included in the file [<code>LICENSE.TXT</code>](https://github.com/ThirtySomething/YAIP/blob/master/LICENSE.TXT "LGPL-3.0") in the project root.

## ToDo ##

Speed up the brute force. Evaluate these frameworks and apply a solution to the puzzle solver source.

* [Cuda](https://developer.nvidia.com/about-cuda)
* [OpenCL](https://www.khronos.org/opencl/)
* [OpenMP](http://www.openmp.org/)

Additional task

* Implement some clever permutation instead brute force
