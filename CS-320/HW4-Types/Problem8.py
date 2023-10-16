def test_associativity(op1, op2, val1, val2, val3):
    """Check if op1 and op2 have left-to-right or right-to-left associativity."""
    expression1 = f"{val1} {op1} {val2} {op2} {val3}"
    expression2 = f"({val1} {op1} {val2}) {op2} {val3}"
    expression3 = f"{val1} {op1} ({val2} {op2} {val3})"

    try:
        result1 = eval(expression1)
        result2 = eval(expression2)
        result3 = eval(expression3)
    except ZeroDivisionError:
        return "Undefined"

    if result1 == result2:
        return "Left-to-Right"
    elif result1 == result3:
        return "Right-to-Left"
    else:
        return "Undefined"


def test_precedence(operators, value1, value2, value3):
    """Determine and output the precedence of operators."""
    precedence = {}
    rank = 0

    for i, op1 in enumerate(operators):
        for j, op2 in enumerate(operators):
            if i != j:
                expr1 = f"{value1} {op1} {value2} {op2} {value3}"
                expr2 = f"({value1} {op1} {value2}) {op2} {value3}"
                if eval(expr1) == eval(expr2):
                    if op1 not in precedence:
                        rank += 1
                        precedence[op1] = rank
                    if op2 not in precedence:
                        rank += 1
                        precedence[op2] = rank

    # Sort the precedence dictionary by rank
    sorted_precedence = sorted(precedence.items(), key=lambda x: x[1])
    return [item[0] for item in sorted_precedence]


def main():
    arithmetic_operators = ["+", "-", "*", "**", "%", "/", "//"]
    boolean_operators = ["and", "or", "==", "<", ">", "<=", ">=", "!="]
    all_operators = arithmetic_operators + boolean_operators

    print("Precedence Order:")
    operators_in_precedence = test_precedence(all_operators, 2, 3, 4)
    for index, op in enumerate(operators_in_precedence, start=1):
        print(f"{index}. {op}")

    print("\nAssociativity:")
    for op1 in all_operators:
        for op2 in all_operators:
            if op1 != op2 and op1 in operators_in_precedence and op2 in operators_in_precedence:
                associativity = test_associativity(op1, op2, 2, 3, 4)
                if associativity != "Undefined":
                    print(f"For {op1} and {op2}: {associativity}")


if __name__ == "__main__":
    main()
