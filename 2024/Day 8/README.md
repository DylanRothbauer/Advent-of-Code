# 🎄 Advent of Code - Day 8: Resonant Collinearity

## 📝 Problem Description

While investigating a rooftop Easter Bunny installation, you notice huge antennas configured to emit a signal with nefarious effects. Your task is to analyze their arrangement and determine the total number of **unique antinodes** caused by their resonance.

### Part One

**Task**:  
Identify all **unique antinodes** within the grid. An antinode occurs:
1. Between two antennas of the same frequency, perfectly in line.
2. When one antenna is exactly twice as far away as the other.

#### Example Input:
```plaintext
............  
........0...  
.....0......  
.......0....  
....0.......  
......A.....  
............  
............  
........A...  
.........A..  
............  
............  
```
#### Example Output:
Unique antinode count: 14  
Your Puzzle Answer: 254  

### Part Two
**Task**:  
Expand the calculation to include resonant harmonics, where:
1. Any grid position exactly in line with two or more antennas of the same frequency becomes an antinode, regardless of distance.
2. Antennas themselves are antinodes if they share their frequency with at least one other antenna.

#### Example Output:
Unique antinode count (with harmonics): 951  
Your Puzzle Answer: 951  

## 💡 Reflection

In solving this challenge, I learned:

- **Efficient Data Structures**:  
  Using `map<char, vector<pair<int, int>>>` to organize antenna positions by frequency and `set<pair<int, int>>` to track unique antinode positions ensured efficient processing.
  
- **Geometric Calculations**:  
  Midpoints, extensions, and collinearity checks deepened my understanding of 2D grid operations and spatial relationships.

- **Expanding Complexity**:  
  Adding harmonics introduced new logic layers, combining simple pairwise checks with global antenna interactions.

- **AI Assistance**:  
  Collaborating with AI helped refine edge case handling and improve algorithm performance, along with adding comments to help the learning experience.

