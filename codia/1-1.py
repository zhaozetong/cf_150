def spiral_value(n, m, i, j):
    # 计算 (i, j) 所在的“层”
    layer = min(i - 1, j - 1, n - i, m - j)

    # 当前层左上角坐标
    r, c = 1 + layer, 1 + layer

    # 当前层的高和宽
    rows = n - 2 * layer
    cols = m - 2 * layer

    # 计算该层之前的所有数的数量
    start = 1
    for k in range(layer):
        h = n - 2 * k
        w = m - 2 * k
        if h == 1:
            start += w
        elif w == 1:
            start += h
        else:
            start += 2 * (h + w) - 4

    # 判断当前位置在第几条边上
    if i == r:  # 顶边
        ans = start + (j - c)
    elif j == c + cols - 1:  # 右边
        ans = start + (cols - 1) + (i - r)
    elif i == r + rows - 1:  # 底边
        ans = start + (cols - 1) + (rows - 1) + (c + cols - 1 - j)
    else:  # 左边
        ans = start + (cols - 1) + (rows - 1) + (cols - 1) + (r + rows - 1 - i)

    return ans


# 输入读取
if __name__ == '__main__':
    n, m, i, j = map(int, input().split())
    print(spiral_value(n, m, i, j))
