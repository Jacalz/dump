# This my solution to a TDDE24 exam question from 2021-01-12.
# The code is not perfect, but it is a cool example of creating
# a pseudo-assembly language in Python.


def eval_pyassm(prog: list[list]):
    """ Emulates the running of a PyAssm program. """

    # Create 26 zeroed registers for A to Z.
    memory = [0 for _ in range(26)]

    # ord('A') is 65. Convert the register name to slice index.
    reg_to_index = lambda reg: ord(reg) - ord("A")

    # Keep a stack of return adresses for jump instructions.
    return_addresses = []

    index = 0
    while index < len(prog):
        current = prog[index]

        name = current[0]
        if name == "JSR":
            # Save the state where we left off.
            return_addresses.append(index + 1)

            # Jump to the position.
            number = current[1]
            index = number
            continue
        elif name == "RET" and len(return_addresses) > 0:
            index = return_addresses.pop()
            continue
        elif name == "NOP":
            index += 1
            continue

        register = current[1]
        reg_ptr = reg_to_index(register)

        # Jump instructions.
        if name == "JEQ": # Jump if Equal!
            reg2_ptr, number = reg_to_index(current[2]), current[3]
            if memory[reg_ptr] == memory[reg2_ptr]:
                index += number
                continue
        elif name == "JNQ": # Jump if Not Equal!
            reg2_ptr, number = reg_to_index(current[2]), current[3]
            if memory[reg_ptr] != memory[reg2_ptr]:
                index += number
                continue

        # Linear instructions.
        elif name == "LOG":
            print(f"[{register}={memory[reg_ptr]}]")
        elif name == "SET":
            number = current[2]
            memory[reg_ptr] = number
        elif name == "CPY":
            from_ptr = reg_to_index(current[2])
            memory[reg_ptr] = memory[from_ptr]
        elif name == "ADD":
            number = current[2]
            memory[reg_ptr] += number
        elif name == "MUL":
            number = current[2]
            memory[reg_ptr] *= number

        index += 1


if __name__ == "__main__":
    eval_pyassm([["LOG", "A"]])

    eval_pyassm([["SET", "A", 10], ["MUL", "A", 5], ["ADD", "A", 5.25], ["LOG", "A"], ["CPY", "B", "A"], ["LOG", "A"], ["LOG", "B"]])

    eval_pyassm([
        ["ADD", "A", 1],
        ["MUL", "A", 10],
        ["ADD", "B", 1], # 3 steps before the last JEQ
        ["JEQ", "B", "A", 100],
        ["LOG", "B"],
        ["JEQ", "B", "B", -3] # Always equal, so jump!
    ])

    eval_pyassm([
        ["ADD", "A", 1],
        ["JSR", 5], # Jump from 1 to 5
        ["NOP"],
        ["NOP"],
        ["JEQ", "B", "B", 10000],
        ["LOG", "A"],
        ["RET"] # Return to 2
    ])

    eval_pyassm([
        ["ADD", "A", 1], # Index 0
        ["JSR", 5],
        ["LOG", "D"],
        ["NOP"],
        ["JEQ", "B", "B", 10000],
        ["LOG", "A"], # Index 5
        ["JSR", 10],
        ["LOG", "C"],
        ["RET"],
        ["NOP"],
        ["LOG", "B"], # Index 10
        ["RET"],
    ])
