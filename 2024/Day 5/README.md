# 🎄 Day 5: Print Queue 🎄

## 🌟 Puzzle Overview
In **Day 5: Print Queue**, the task involved helping the North Pole printing department ensure that pages for the sleigh launch safety manual updates were printed in the correct order. The goal was to identify which updates followed specific ordering rules and to sum the middle page numbers of these correctly-ordered updates.

---

### 📝 Part One: Correctly Ordered Updates
Given a set of ordering rules in the format `X|Y` (meaning page `X` must be printed before page `Y`), and a series of page updates, the challenge was to determine which updates followed these rules.

#### Example Input:
47|53  
97|13  
97|61  
97|47  
75|29  
61|13  
75|53  
29|13  
97|29  
53|29  
61|53  
97|53  
61|29  
47|13  
75|47  
97|75  
47|61  
75|61  
47|29  
75|13  
53|13  
  
75,47,61,53,29  
97,61,53,29,13  
75,29,13  
75,97,47,61,53  
61,13,29  
97,13,75,29,47  


#### Correctly Ordered Updates:
1. `75,47,61,53,29` (middle page: 61)
2. `97,61,53,29,13` (middle page: 53)
3. `75,29,13` (middle page: 29)

**Sum of Middle Pages:** 61 + 53 + 29 = **143**

#### Result:
The actual sum of the middle pages for the correctly ordered updates was **6384**.

---

### 📝 Part Two: Fixing Incorrectly Ordered Updates
For the updates that didn't follow the rules, the task was to reorder them according to the rules and then sum the middle page numbers of these fixed updates.

#### Example Reordering:
1. `75,97,47,61,53` becomes `97,75,47,61,53` (middle page: 47)
2. `61,13,29` becomes `61,29,13` (middle page: 29)
3. `97,13,75,29,47` becomes `97,75,47,29,13` (middle page: 47)

**Sum of Middle Pages:** 47 + 29 + 47 = **123**

#### Result:
The actual sum of the middle pages for the fixed updates was **5353**.

---

## 📊 Results Summary
- **Part One Answer:** 6384
- **Part Two Answer:** 5353
- Both parts are complete! ⭐⭐

---

## 🌟 Reflection
Day 5's challenge provided an opportunity to strengthen my understanding of several fundamental C++ concepts:

- **`stringstream`**: Used for efficiently parsing input strings and handling tokenization, which was essential for processing page updates.
- **`map` and `set`**: Leveraged for storing and efficiently accessing ordering rules and unique pages, ensuring quick lookups and avoiding duplicate entries.
- **`std::sort()`**: Utilized to sort the updates according to the ordering rules, reinforcing the importance of sorting functions and custom comparator logic.
- **`<functional>` and `std::bind`**: Applied for the first time to create flexible, reusable functions, which made handling complex operations more modular and readable.

This problem highlighted the power of C++'s standard library for managing data structures and sorting, while also offering a chance to experiment with new tools like `std::bind`. It was a great exercise in combining parsing, sorting, and functional programming concepts to achieve a clear and efficient solution.

