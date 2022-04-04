# Kutta Condition Verification by solving System of Linear Equations Solver using LU Decomposition


# Table of contents
1. [Introduction](#introduction)
2. [Requirements](#requirements)
3. [Installation](#installation)
4. [Usage](#usage)
    1. [Input](#input)
    2. [Compile](#compile)
    3. [Run](#run)
    3. [Output](#output)
5. [Author](#author)
6. [Sources](#sources)

<br/>
<br/>

## Introduction
The project is a simple C++ Solver for a System of Linear Equations, using LU Decomposition. Using the Solution Variables obtained, it checks if the corresponding vortex strengths for vortex panel method satisfy the Kutta Condition. LU Decomposition includes decomposing a square matrix into  the product of a lower-triangular and an upper-triangular matrix. After carrying out this decomposition, we can obtain a the solution array by simple forward-substitution followed by a backward substitution. This is one of the simplest ways to obtain the result for a system of linear equations.

<br/>
<br/>

## Requirements
The project has been compiled using the  _g++_  compiler during its development, and hence it is neede to run the files. 

Furthermore, the project has been developed on a *Linux Kernel* (OS: Fedora 35), hence it might need some supervision when running on other kernels.

<br/>
<br/>

## Installation
The project can be installed by downloading the code files in the required destination. It can be cloned from github as well.

The project consists of **3 code files** : 

* main.cpp
* LUDecomp.h
* solve.h

and **1 input file** :

* input.txt

To succesfully run the project, all these need to be in the same directory.

<br/>
<br/>

## Usage
### Input
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
***NOTE :***	<br/>
* The Cursor must be after the last numerical value and **NOT** on the next line.	<br/>
* The input file must be saved before running the code files	<br/>
* The system of equations must have a unique solution	<br/>

<br/>
***NOTE :***	<br/>
* You can change the level of precision with which you want to check for the Kutta-Condition.	<br/>
* For precision = p, if the residual vortex strength ($\Gamma$_n - $\Gamma$_1)
) is less than p, the Kutta-Condition is said to be satisfied	<br/>

<br/>

### Compile
Before execution, the code needs to be compiled. This can be done by running the following command after opening a terminal in the same directory as the code files :
```bash
$ g++ main.cpp -lm
```

<br/>

### Run
To execute the code, we run the executable file. The executable file takes 1 input parameter : 
> n : number of variables in the system of equations

In our example, ```n = 4```, since it is a 4 variable system of linear equations

Execute the file by running the following commands in the terminal opened in the same directory :
```bash
$ ./a.out 4
```

### Output
The solution for the value of the variables is displayed in the terminal : 
```bash

Kuuta Condition Not Satisfied

Solution to the System of Equations is
	Variable : a = -2
	Variable : b = 3
	Variable : c = 4.5
	Variable : d = -1.5
```
<br/>
<br/>

## Author
*Kirtan Patel (2022)*
### University of Twente Details
Roll number : s2935848 <br/>
Email ID : k.p.patel@student.utwente.nl <br/>

<br/>
<br/>

## Sources
* Initializing a vector of objects <br/> (https://stackoverflow.com/questions/7558280/initializing-an-array-of-objects)

*  The Project Topic was inspired by the LU Decomposition carried out in a previous code which I had written for Cubic Spline Interpolation in C Language. <br/> (https://github.com/kirtan2605/IITM_EE1103)
