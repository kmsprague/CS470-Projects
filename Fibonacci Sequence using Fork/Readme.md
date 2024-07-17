# Fibonacci Sequence using Fork

## Overview 
This program prints out a requested amount of numbers in the fibonacci sequence by creating a child process that calculates and prints the numbers. The user inputs how many numbers are required, the program then calls fork() to create a child process that calculates and prints the requested amount of numbers. Once the child process is finished, the parent process outputs that it is finished. 

## How to Run
This program is written in C, meaning it will need to be copiled before it can be executed. If you have the GNU Compiler Collection installed, you can use the following command in terminal: 
> gcc main.c -o executable

In this example, the program can be run using the following command in terminal: 
> ./executable
