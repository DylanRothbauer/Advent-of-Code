# 🎄 Advent of Code — Day 1: Secret Entrance  
*Decorating the North Pole, One Puzzle at a Time*

This contains my solution for **Advent of Code – Day 1**, where the Elves need help navigating a dial-based safe lock using a series of rotational instructions.  
The challenge revolves around interpreting the dial rotations and tracking how often the pointer lands on **0**, using two different password methods.

---

## 🧩 Problem Summary

The Elves have embraced project management — but discovered none of them have time left to decorate the North Pole.  
To assist, you must open the *secret entrance safe* by analyzing a sequence of dial instructions.

You’re given:

- A dial numbered **0–99**
- A starting position at **50**
- A list of rotations in the form:  
  - `L<number>` → Rotate left (toward lower numbers)  
  - `R<number>` → Rotate right (toward higher numbers)
- The dial wraps around (left from 0 goes to 99, etc.)

You must count the number of times the dial points at **0**.

Two puzzles are provided:

---

## ⭐ Part One — Final Position Checking  
Count the number of times the dial ends on **0** at the **end of a rotation**.

### Example Behavior  
Given rotations like:
L68  
L30  
R48  
You trace the dial’s position after each rotation.  
If the pointer lands exactly on **0**, increment the counter.

## ⭐ Part Two — Counting Every Click  
A new security protocol activates: **password method `0x434C49434B`** (“CLICK”).  
Now you must count:

- Every time the dial points at **0**
- **Both during rotations and at the end of rotations**

Even a single large rotation like `R1000` may pass over 0 multiple times — in fact, exactly `floor(amount / 100)` times.

Using the expanded rule set, the total number of 0-clicks increases significantly.

```plaintext
📦 Advent-Of-Code/Day1
├── input.txt              # Puzzle input
├── main.py                # My implementation
└── README.md              # You're reading it!
