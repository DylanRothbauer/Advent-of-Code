# 🎄 Advent of Code - Day 3: Mull It Over

## 📜 Problem Description

### Part 1:
The North Pole Toboggan Rental Shop's computer is malfunctioning due to corrupted memory. The goal of the program is to multiply numbers using valid `mul(X,Y)` instructions, where `X` and `Y` are 1-3 digit numbers.

Your task is to scan the corrupted memory for valid `mul` instructions and sum their results. **Invalid characters and malformed instructions must be ignored.**

#### Example:
```
xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
```
**Valid Instructions:**
- `mul(2,4)` → 2 * 4 = 8
- `mul(5,5)` → 5 * 5 = 25
- `mul(11,8)` → 11 * 8 = 88
- `mul(8,5)` → 8 * 5 = 40

**Total Sum:** 8 + 25 + 88 + 40 = 161

**Your puzzle answer:** `173517243`.

---

### Part 2:
Additional instructions, `do()` and `don't()`, enable or disable `mul` operations:
- **`do()`**: Enables future `mul` operations.
- **`don't()`**: Disables future `mul` operations.
- Only the most recent `do()` or `don't()` instruction applies.

At the beginning, `mul` instructions are enabled.

#### Example:
```
xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))
```
**Processing:**
- `mul(2,4)` → Enabled → 2 * 4 = 8
- `mul(5,5)` → Disabled by previous `don't()` → Ignored
- `mul(11,8)` → Disabled by previous `don't()` → Ignored
- `mul(8,5)` → Re-enabled by `do()` → 8 * 5 = 40

**Total Sum:** 8 + 40 = 48

**Your puzzle answer:** `100450138`.

---

## ✨ Key Concepts:
- **Valid Instruction:** `mul(X,Y)` where `X` and `Y` are valid 1-3 digit integers.
- **Invalid Data:** Ignored characters like `*`, `!`, and malformed `mul` calls.
- **Enable/Disable Logic:** Use `do()` and `don't()` to toggle processing of `mul` instructions.

---

## 📊 Results:
- **Part 1:** `173517243`
- **Part 2:** `100450138`

Both parts of this puzzle are complete! ⭐⭐

