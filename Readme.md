# Billiard #

## What's that ##

Imagine the triangle of all billiard balls like this here

| Level |       |       |       |       |       |       |       |       |       |       | 
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | 
|     4 |       |    11 |       |    12 |       |    13 |       |    14 |       |    15 | 
|     3 |       |       |     7 |       |     8 |       |     9 |       |    10 |       | 
|     2 |       |       |       |     4 |       |     5 |       |     6 |       |       | 
|     1 |       |       |       |       |     2 |       |     3 |       |       |       | 
|     0 |       |       |       |       |       |     1 |       |       |       |       | 

On level 0, there is one ball with index 1. On level 1, there are two balls above the ball of level 0, one with index 2 and the second with index 3. The absolute difference between the numbers of the two balls on level 1 will result in the number of the ball on level 0. Simple example to understand:

| Level |       |       |       |
| :---: | :---: | :---: | :---: |
|     1 |     8 |       |     5 |
|     0 |       |     3 |       |

```
Ball on level 0 = asb(ball upper left - ball upper right)

              3 =             8       -       5
```

This *group* of *two balls above one* is available at least 10 times. For each group the rule has to be valid. An extended example looks like this one

| Level |       |       |       |       |       | 
| :---: | :---: | :---: | :---: | :---: | :---: | 
|     2 |     4 |       |    12 |       |     7 | 
|     1 |       |     8 |       |     5 |       | 
|     0 |       |       |     3 |       |       |

This C++ programm will run through all possible combinations of these 15 values and will apply the rules. The goal is to figure out all possible solutions for this task.