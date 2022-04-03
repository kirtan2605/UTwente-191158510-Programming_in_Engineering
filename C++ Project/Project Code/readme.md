# System of Linear Equations Solver using LU Decomposition


# Table of contents
1. [Introduction]
2. [Requirements](#requirements)
3. [Installation](#installation)
4. [Usage](#usage)
    1. [Input](#input)
    1. [Compile](#compile)
    1. [Run](#run)

<br/>

## Introduction <a name="introduction"></a>
The project is a simple C++ Solver for a System of Linear Equations, using LU Decomposition. This method includes decomposing a square matrix into  the product of a lower-triangular and an upper-triangular matrix. After carrying out this decomposition, we can obtain a the solution array by simple forward-substitution followed by a backward substitution. This is one of the simplest ways to obtain the result for a system of linear equations.

## Requirements <a name="requirements"></a>
The project has been compiled using the  _g++_  compiler during its development, and hence it is neede to run the files. 

Furthermore, the project has been developed on a *Linux Kernel* (OS: Fedora 35), hence it might need some supervision when running on other kernels.

<br/>

## Installation <a name="installation"></a>
The project can be installed by downloading the code files in the required destination. It can be cloned from github as well.

The project consists of **3 code files** : 

* main.cpp
* LUDecomp.h
* solve.h

and **1 input file** :

* input.txt

To succesfully run the project, all these need to be in the same directory.

<br/>

## Usage <a name="usage"></a>
### Input <a name="input"></a>
The first step of usage is customizing the input according to the desired system of linear equations. The Augmented Matrix is to be entered in ***input.txt***. The values can be seperated by spaces/tabs but **NOT** commas.

The below ***4 variable*** system of equations :

> 2a + b + 5c + 3d = 17 	<br/>
> 5a + 4b + 2c    = 11		<br/>
> -2b + 3c + 7d = -3		<br/>
> -3a + c + 5d = 3 			<br/>

can be written as :

> 2.a + 1.b + 5.c + 3.d = 17		<br/>
> 5.a + 4.b + 2.c + 0.d   = 11		<br/>
> 0.a + -2.b + 3.c + 7.d = -3		<br/>
> -3.a + 0.b + 1.c + 5.d = 3 		<br/>

and thus the Augmented Matrix, which the input file must contain is : 
```
2 1 5 3 17
5 4 2 0 11
0 -2 3 7 -3
-3 0 1 5 3
```
<br/>
***NOTE :*** 
* The Cursor must be after the last numerical value and **NOT** on the next line.
* The input file must be saved before running the code files

<br/>

### Compile <a name="compile"></a>

<br/>

### Run <a name="run"></a>



