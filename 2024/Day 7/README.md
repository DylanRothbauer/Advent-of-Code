# 🎄 Advent of Code - Day 7: Bridge Repair

## 📝 Problem Description

The Historians take you to a jungle where a rope bridge over a river is under repair. The engineers need help calibrating their equations after some playful elephants stole the operators from them. Your task is to determine which equations can be made true by inserting operators and calculate the total calibration result.

### Part One

**Task**:  
For each calibration equation, determine if the numbers can be combined with operators (`+` or `*`) to match the given test value. Operators are evaluated left-to-right (not based on precedence), and numbers cannot be rearranged.

#### Example Input:
190: 10 19  
3267: 81 40 27  
83: 17 5  
156: 15 6  
7290: 6 8 6 15  
161011: 16 10 13  
192: 17 8 14  
21037: 9 7 18 13  
292: 11 6 16 20  

#### Example Output:
Test values that can be made true: 190, 3267, 292 Total calibration result: **3749**  


**Your Puzzle Answer**: `2501605301465`

---

### Part Two

**Task**:  
A third operator (`||`) is introduced, allowing digit concatenation. For example, `12 || 345` becomes `12345`. Update the calculations to include this operator and determine the new total calibration result.

#### Example Output:
Test values that can be made true: 190, 3267, 292, 156, 7290, 192 New total calibration result: **11387**  


**Your Puzzle Answer**: `44841372855953`

---

## 💡 Reflection

In solving this challenge, I gained a deeper understanding of:

- **Operator Parsing**: Dynamically evaluating expressions with left-to-right precedence.
- **Recursive Backtracking**: Used to explore all possible operator placements.
- **String Concatenation**: Managing mixed operations including addition, multiplication, and concatenation (`||`).
- **Exploration**: Utilized <stdexcept> and <sstream> for exception handeling and string menipulation.

---
