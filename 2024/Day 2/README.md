# 🎄 Advent of Code - Day 2: Red-Nosed Reports

## 📜 Problem Description

### Part 1:
The Chief Historian is missing, and the Historians are searching key locations. At the Red-Nosed Reindeer reactor, engineers need help analyzing unusual data reports.

Each report is a list of levels, and your task is to determine which reports are **safe**. A report is considered safe if:
1. The levels are either **all increasing** or **all decreasing**.
2. Any two adjacent levels differ by at least **1** and at most **3**.

#### Example Reports:
```
7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9
```

**Safe Reports:**
- `7 6 4 2 1`: All levels are decreasing with differences of 1 or 2.
- `1 3 6 7 9`: All levels are increasing with differences of 1, 2, or 3.

**Unsafe Reports:**
- `1 2 7 8 9`: Contains an increase of 5 between 2 and 7.
- `8 6 4 4 1`: Contains a repeated level (4 and 4).

Your task: Determine the total number of safe reports.

**Your puzzle answer:** `510`.

---

### Part 2:
The engineers introduce the **Problem Dampener**, allowing the removal of a single bad level to make an unsafe report safe.

#### Example Reports with Problem Dampener:
- `1 3 2 4 5`: Safe by removing `3`.
- `8 6 4 4 1`: Safe by removing one `4`.

Your task: Determine the number of safe reports considering the Problem Dampener.

**Your puzzle answer:** `553`.

---

## ✨ Key Concepts:
- **Safe Report:** Levels are strictly increasing or decreasing, and adjacent differences are between 1 and 3.
- **Problem Dampener:** Allows the removal of one level to fix an otherwise unsafe report.

---

## 📊 Results:
- **Part 1:** `510` safe reports.
- **Part 2:** `553` safe reports.

Both parts of this puzzle are complete! ⭐⭐

