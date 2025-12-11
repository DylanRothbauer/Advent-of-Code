def move_and_count(current_index, direction, steps, max_range):
    global zero_counter

    N = max_range

    if direction == "R":
        zero_during = (current_index + steps - 1) // N
        new_index = (current_index + steps) % N

    elif direction == "L":
        new_index = (current_index - steps) % N

        if steps <= current_index:
            zero_during = 0
        else:
            # count the first crossing at step=current_index, plus additional wraps
            zero_during = 1 + ((steps - current_index - 1) // N)
            # if we land on 0, that last crossing is the end-of-rotation event, not a "during"
            if current_index == 0:
                zero_during -= 1

    else:
        print(f"Invalid direction: {direction}")
        return current_index, zero_counter

    zero_counter += zero_during
    if new_index == 0:
        zero_counter += 1

    print(f"Moved {direction}{steps}: during={zero_during}, end_zero={int(new_index==0)}, at={new_index}, total={zero_counter}")
    return new_index, zero_counter

file_path = "Input.txt"
max_range = 100
dial_index = 50
zero_counter = 0

file = open(file_path, "r")

# Testing/debugging calls
# start=50
# start, zero_counter = move_and_count(start, "L", 68, max_range)
# start, zero_counter = move_and_count(start, "L", 30, max_range)
# start, zero_counter = move_and_count(start, "R", 48, max_range)
# start, zero_counter = move_and_count(start, "L", 5, max_range)
# start, zero_counter = move_and_count(start, "R", 60, max_range)
# start, zero_counter = move_and_count(start, "L", 55, max_range)
# start, zero_counter = move_and_count(start, "L", 1, max_range)
# start, zero_counter = move_and_count(start, "L", 99, max_range)
# start, zero_counter = move_and_count(start, "R", 14, max_range)
# start, zero_counter = move_and_count(start, "L", 82, max_range)

# move_and_count(50, "R", 1000, max_range)


for line in file.readlines():
    line = line.strip()
    print(f"Processing line: {line}")
    line_comma = ''.join((line[:1],',',line[1:]))
    direction, steps = line_comma.split(',')

    steps = int(steps)
    dial_index, zero_counter = move_and_count(dial_index, direction, steps, max_range)

print(f"Total times dial reached or passed zero: {zero_counter}")

file.close()
