# 🎄 Advent of Code 2024 - Day 1: Historian Hysteria

## 📝 Problem Description

### --- Day 1: Historian Hysteria ---
The Chief Historian is missing, and it's your job to help the Elvish Senior Historians find him by reconciling two lists of location IDs. These lists need to be compared and reconciled in two parts.

### Part 1: Total Distance Calculation
Given two lists of location IDs, the task is to calculate the total distance between corresponding pairs of numbers. 

**Process:**
1. Sort both lists.
2. Pair the smallest element in the left list with the smallest in the right list, the second smallest with the second smallest, and so on.
3. Calculate the distance for each pair and sum all distances.

**Example:**  
**Input:**  
3 4  
4 3  
2 5  
1 3  
3 9  
3 3  

**Steps:**  
Pair and calculate distances: 
(1, 3) -> Distance = 2  
(2, 3) -> Distance = 1  
(3, 3) -> Distance = 0  
(3, 4) -> Distance = 1  
(3, 5) -> Distance = 2  
(4, 9) -> Distance = 5  
Total Distance: 2 + 1 + 0 + 1 + 2 + 5 = 11  

### Part 2: Similarity Score Calculation
Calculate a similarity score by checking how many times each number in the left list appears in the right list. 

**Process:**
1. For each number in the left list, count its occurrences in the right list.
2. Multiply the number by its occurrence count and sum the results.

**Example:**  
**Input:**  
3 4  
4 3  
2 5  
1 3  
3 9  
3 3  

**Steps:**  
3 appears 3 times in the right list: 3 * 3 = 9  
4 appears 1 time: 4 * 1 = 4  
2 appears 0 times: 2 * 0 = 0  
1 appears 0 times: 1 * 0 = 0  
3 (again) appears 3 times: 3 * 3 = 9  
3 (again) appears 3 times: 3 * 3 = 9  
Similarity Score: 9 + 4 + 0 + 0 + 9 + 9 = 31  


## ⭐ Solutions Summary
- **Part 1 Output:** The total distance between the left and right lists.
- **Part 2 Output:** The total similarity score calculated from the occurrences of numbers.

## ✅ Final Answers:
- **Part 1 Solution:** `1889772`
- **Part 2 Solution:** `23228917`

## 💡 Notes:
- Ensure input lists are sorted before calculating distances.
- Use efficient counting methods for large datasets to avoid performance bottlenecks.

## 🔗 Resources:
- [Advent of Code 2024](https://adventofcode.com/)
- [Day 1 Challenge](https://adventofcode.com/2024/day/1)

---
Happy Coding! 🚀

