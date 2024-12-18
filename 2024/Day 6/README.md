# 🎄 Advent of Code - Day 6: Guard Gallivant

## 📝 Problem Description

In Day 6, the Historians take you to the North Pole prototype suit manufacturing lab in the year 1518! You encounter a guard patrolling the lab who follows a strict set of rules. Your task is to predict the guard's patrol path to ensure the Historians can safely search the lab.

### Part One

**Task**:  
Given a map of the lab with obstructions (`#`) and the guard's starting position (denoted by `^`, `v`, `<`, or `>`), predict the guard's movement based on the following rules:

1. If there is an obstacle directly in front, the guard turns right 90 degrees.
2. Otherwise, the guard steps forward.

You need to determine how many **distinct positions** the guard will visit before leaving the mapped area.

#### Example Input
....#.....  
.........#  
..........  
..#.......  
.......#..  
..........  
.#..^.....  
........#.  
#.........  
......#...  

#### Example Output
41


**My Puzzle Answer**: `5242`

### Part Two

**Task**:  
Now, The Historians want to place a single new obstruction to trap the guard in a loop. You need to determine how many different positions you could place the obstruction to achieve this, avoiding the guard's starting position.

#### Example Output
6


**My Puzzle Answer**: `1424`

---

## 💡 Reflection

In solving this challenge, I revisited concepts like:

- **Pathfinding and Movement Simulation**: Predicting a character's movement based on simple rules.
- **Grid Navigation**: Tracking positions on a 2D grid and ensuring all visited positions are accounted for.
- **Loops and Conditions**: Implementing rules for direction changes and obstacles.

---

