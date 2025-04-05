def main():
    # 输入 n
    n = int(input())
    
    # 处理小于等于3的特殊情况
    if n == 1:
        print(1)
        return
    if n == 2:
        print(2)
        return
    
    # 初始化dp数组，vec[i]表示填满长度为i的矩形的不同方式
    vec = [0] * (n + 1)
    vec[0] = 1  # 0 长度有 1 种填充方式（什么都不填）
    vec[1] = 1  # 长度 1 只能填一个 1×1
    vec[2] = 2  # 长度 2 可以用两个 1×1 或者一个 1×2
    
    # 从3到n，根据递推公式计算填充方式
    for i in range(3, n + 1):
        vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3]
    
    # 输出结果
    print(vec[n])

# 调用主函数
if __name__ == "__main__":
    main()
