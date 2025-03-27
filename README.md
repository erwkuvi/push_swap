# Push Swap

---

### Introduction

This project is part of the common core curriculum of the 42 Wolfsburg programming school. 
In this project I had a nice introduction to sorting algorithms. The first encounter with the concept of complexity.

The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

---
### Goal:
Write a C program that calculates and displays the **shortest** sequence of instructions needed to sort the given integers.

---
### The rules:

*The goal is to sort the numbers in stack 'A' in ascending order.* 

1. At the beginning we have 2 stacks 'A' & 'B'.
2. 2 Stacks: 
	- Stack 'A' contains a random number of unique negative and/or positive integers.
	- Stack 'B' is empty.
3. A set of instructions to manipulate both stacks. 
	1. **sa** (swap a): Swap the first 2 elements at the top of a stack a. Do nothing if there is only one element or none.
	2. **sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
	3. **ss**: sa and sb at the same time.
	4. **pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	5. **pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
	6. **ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
	7. **rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
	8. **rr** : ra and rb at the same time.
	9. **rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
	10. **rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
	11. **rrr** : rra and rrb at the same time.

---

### My approach

To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

There are a few available algorithms to solve this problem.

I decided to hardcode the solution for small numbers such as 2, 3, or 5
**Example:** Sorting 3 numbers:

- `2 1 3` → `sa` ✅
    
- `3 1 2` → `ra` → `sa` ✅
    
- `3 2 1` → `sa` → `rra` ✅

**Complexity:** O(1) (constant time for small n).

For bigger amount of numbers I went for the greedy algorithm optimized for 'push swap'

- **Calculate the move cost for each number in Stack B** to determine how many operations are required to place it correctly in Stack A. 
- **Choose the lowest-cost move** and execute it.
- **Repeat until Stack B is empty**, and Stack A is sorted.
- The cost is calculated as:

> cost = max⁡(moves in A, moves in B) 

where:
- **Moves in A**: Rotations needed to bring the correct insert position to the top.
- **Moves in B**: Rotations needed to bring the number to the top.

### **Implementation Example**

#### Step 1: Calculate Move Costs

Consider **Stack A** and **Stack B**:

> Stack A: [2, 4, 7, 10, 15]
> Stack B: [3, 8, 1]

- We want to move `3` from B into its correct position in A.
- `3` belongs between `2` and `4` in A.
- Determine how many **ra/rra** and **rb/rrb** moves are needed.

#### Step 2️: Find the Best Move

If:
- Moving `3` requires `ra 1` and `rb 2` (cost: `2`).
- Moving `8` requires `rra 1` and `rb 3` (cost: `3`).

**We select the move with the lowest cost** (moving `3` first).

---

### Visualization: 

#### 500 values | Count 4404

![500 Values](https://github.com/erwkuvi/push_swap/tree/main/assets/push_swap_500.gif)

#### 100 values | Count 572

![100 Values](https://github.com/erwkuvi/push_swap/tree/main/assets/push_swap_100.gif)

#### 50 values | Count 241

![50 Values](https://github.com/erwkuvi/push_swap/tree/main/assets/push_swap_50.gif)

#### 1000 values | Count 11246

![1000 Values](https://github.com/erwkuvi/push_swap/tree/main/assets/push_swap_1000.gif)
