import queue

priorities = {
    "^": 2,
    "*": 1,
    "/": 1,
    "+": 0,
    "-": 0,
}

rightAssociated = {
    "^": True,
    "*": False,
    "/": False,
    "+": False,
    "-": False,
}

# InfixToRPN converts a string in infix notation to reverse polish notation (RPN).
def infixToRPN(infix):
    output = queue.Queue()
    operators = queue.LifoQueue() # Same as a stack.

    for token in infix.split():
        if token == "(":
            operators.put(token)
        elif token == ")":
            foundLeftMatch = False

            # Pop items from the stack to the queue until the matching parenthesis is found.
            while not operators.empty():
                oper = operators.get()
                if oper == "(":
                    foundLeftMatch = True
                    break

                output.put(oper)

            if not foundLeftMatch:
                raise Exception("Mismatched parenthesis error")
                return

            if operators.empty():
                continue

            # If the top in the stack is not an operator, pop over the corresponding function.
            top = operators[-1]
            if top not in priorities:
                output.push(operators.pop())
            
        elif token in priorities:
            priority = priorities[token]

            while not operators.empty():
                top = operators[-1] # TODO: Something is not working here. How can this be called on an empty queue?
                if top == "(":
                    break

                if (priorities[top] > priority and rightAssociated[token]) or (priority <= priorities[top] and not rightAssociated[token]):
                    output.put(operators.get())

                break

            operators.put(token)
            
        elif token.isnumeric():
            output.put(token)
            
        else: # The token is a function.
            operators.put(token)
                
    # Pop remaining items from the stack to the queue.
    while not operators.empty():
        oper = operators.get()
        if oper == "(":
            raise Exception("Mismatched parenthesis error")
            return
        
        output.put(oper)

    return list(output.queue)
            

print(infixToRPN("3 + 4 * 2 / ( 1 − 5 ) ^ 2 ^ 3"))
