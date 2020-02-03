# Project Overview

Aims to incorporate interrupt handling ablility to banker's algorithm, therby creating a modified banker's algorithm that can check for and handle interrupts during normal working (for deadlock prevention).

Used pthreads.h for multi-threading for simulating the working of the algorithm with random interrupt generation(random resource need for each interrupt) at random intravels. 

More about [bankers algorithm](https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/)


## Project Architecture
<img src=images/os_flowchart.jpg>

![](images/os_flowchart.jpg width="400" height="400")

## Part 1: Random Interrupts Generation

The first thread, continuously randomly generates interrupts in random intravals which is stored in a global circular queue. Random interrupts are each if the form of an array with PID followed by its resouce requirements. This inturn in stored in the global circular queue. Each start of the thread is logged to the console.

## Part 2: Modified Banker's Algorithm

The second thread runs the modified bankers algorithm that checks for interupts in the queue and handles them if they exit. And if not they continue with the deadlock avoidance policy and safety sequence generation.

1. After every process is executed during safety sequence generation, the interrupt global queue is checked.
2. If interrupt is detected:
    1. Check if the OS has enough resouces in AVAILABLE to grant the interrupt its resources.
    2. If enough resources are available, then they are granted so that the interrupt can execute and free the ressources.
    3. If not enough resources are available, push back the interrupt to back of the queue and check for the next interrupt.
    4. If no interrupt can be executed, continue with the bankers safety sequence execution so that resouces can free up in the future.
3. if no interrupt is generated, continue with the bankers algorithm
4. If all processes in bankers table has not been executed yet, then go back and continue bankers algorithm.
5. Display final safety sequence.

## Recording the events

All the steps of the modified banker's algorithm is recorded by writing to a seperate csv file, that includes all the events and its detatils.
The starting and terminating of the threads, the success and failiure of the interrupt granting is logged to the console.

## Displaying the Events

To display the working, this simulation ends by displaying the csv file that was written on program execution as a html file with the help of a python script, a node server and a shell script.

 # Installation Steps for Mac

**Install GCC Compiler for C compilation**
```bash
brew install gcc
```

**Install python**
```bash
brew install python3
```
**Install nodejs**

Install nodeJS from this [site](https://nodejs.org/en/download/)

**Open terminal and go to the project directory to run:**
```bash
./exec.sh
```