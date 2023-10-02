def silhouette(rectangles):
    if len(rectangles) == 1:
        s, h, e = rectangles[0]
        return [(s, h), (e, 0)]

    mid = len(rectangles) // 2
    left_silhouette = silhouette(rectangles[:mid])
    right_silhouette = silhouette(rectangles[mid:])

    return merge_silhouettes(left_silhouette, right_silhouette)


def merge_silhouettes(left, right):
    result = []
    i, j = 0, 0
    current_height_left, current_height_right = 0, 0

    while i < len(left) and j < len(right):
        x_left, y_left = left[i]
        x_right, y_right = right[j]

        if x_left < x_right:
            max_h = max(y_left, current_height_right)
            if not result or max_h != result[-1][1]:
                result.append((x_left, max_h))
            current_height_left = y_left
            i += 1
        elif x_right < x_left:
            max_h = max(current_height_left, y_right)
            if not result or max_h != result[-1][1]:
                result.append((x_right, max_h))
            current_height_right = y_right
            j += 1
        else:  # x_left == x_right
            max_h = max(y_left, y_right)
            if not result or max_h != result[-1][1]:
                result.append((x_left, max_h))
            current_height_left = y_left
            current_height_right = y_right
            i += 1
            j += 1

    # Append the remaining points from both sides
    while i < len(left):
        x_left, y_left = left[i]
        if not result or y_left != result[-1][1]:
            result.append((x_left, y_left))
        i += 1

    while j < len(right):
        x_right, y_right = right[j]
        if not result or y_right != result[-1][1]:
            result.append((x_right, y_right))
        j += 1

    return result


rectangles = [(1, 3, 5), (3, 4, 6), (9, 1, 13), (10, 3, 14)]
print(silhouette(rectangles))  # It should print: [(1, 3), (3, 4), (6, 0), (9, 1), (10, 3), (14, 0)]
