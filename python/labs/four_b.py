def AND(x, y):
    """ AND is a string adaption of the AND logic gate. """
    if x == "true" and y == "true":
        return "true"

    return "false"

def OR(x, y):
    """ OR is a string adaption of the OR logic gate. """
    if x == "true" or y == "true":
        return "true"

    return "false"

def NOT(x):
    """ OR is a string adaption of the NOT logic gate. """
    if x == "false":
        return "true"

    return "false"
    

def evaluate(expression, values):
    """ Evaluate evaluates the expression down to a single true/false. """
    if isinstance(expression[0], list):
        return evaluate(expression[0], values)

    elif len(expression) > 2 and expression[1] == "AND":
        return AND(evaluate(expression[:1], values), evaluate(expression[2:], values))
    elif len(expression) > 2 and expression[1] == "OR":
        return OR(evaluate(expression[:1], values), evaluate(expression[2:], values))
    elif len(expression) > 1 and expression[0] == "NOT":
        return NOT(evaluate(expression[1:], values))
        
    elif expression[0] in values:
        return values[expression[0]]

    return expression[0] # Return the item value (true/false), it is the only thing left.

def interpret(expression, values):
    """
    Interpret takes a list of logic operations in string form
    and evaluates it to a single true/false string.
    """
    if not isinstance(expression, list):
        return evaluate([expression], values)

    return evaluate(expression, values)

if __name__ == "__main__":
    assert interpret(["door_open", "AND", "cat_gone"], 
        {"door_open": "false", "cat_gone": "true", "cat_asleep": "true"}) == "false"

    assert interpret(["cat_asleep", "OR", ["NOT", "cat_gone"]],
        {"door_open": "false", "cat_gone": "true", "cat_asleep": "true"}) == "true"

    assert interpret(["true", "OR", "true"],
        {}) == "true"

    assert interpret("cat_gone",
        {"door_open": "false", "cat_gone": "true"}) == "true"

    assert interpret(["NOT", ["NOT", ["NOT", ["cat_asleep", "OR", ["NOT", "cat_asleep"]]]]],
        {"cat_asleep": "false"}) == "false"

    assert interpret(["NOT", "AND", "true"],
        {"NOT": "true"}) == "true"
        
    assert interpret(["NOT", "AND"],
        {"AND": "false"}) == "true"

    # The tests below this are not from the exercise. They are just tests of edge cases.
        
    assert interpret("true",
        {"NOT": "false"}) == "true"

    assert interpret("NOT",
        {"NOT": "false"}) == "false"

    assert interpret(["NOT", "NOT"],
        {"NOT": "false"}) == "true"

    assert interpret([["NOT", "a"], "AND", ["b", "OR", "c"]],
        {"a": "false", "b": "false", "c": "true"}) == "true"
