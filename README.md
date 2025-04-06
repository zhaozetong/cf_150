## 刷题记录文档

### 字符串
#### 总结
| 操作 | 方法 |
|------|------|
| 初始化 | `std::string s = "text";` |
| 赋值 | `s = "new";` 或 `s.assign("new")`;`s.assign(3,'a')`复制构造 |
| 连接 | `s1 + s2` 或 `s1.append(s2);` |
| 访问 | `s[i]` 或 `s.at(i)` |
| 查找 | `s.find("sub")`正向,`s.rfind()`反向 |
| 提取子串 | `s.substr(pos, len);` |
| 插入 | `s.insert(pos, "text");` |
| 删除 | `s.erase(pos, len);` |
| 替换 | `s.replace(pos, len, "new");`,类似与子串 |
| 流   | `sstream` |
| C     | `const char* cstr = s.c_str();`C风格 |
| 比较 | `s1 == s2` 或 `s1.compare(s2);` |
| 转换 | `std::to_string(num);` `stoi(s);stod()`分别int,double |


### 枚举类
`enum` 枚举中的常量默认从 0 开始递增，也就是说，Red 会对应 0，Green 会对应 1，Blue 会对应 2。如果需要，可以显式地为枚举项指定值。
用法:
```
// 定义一个枚举类型
enum Color {
    Red,    // 默认值为 0
    Green,  // 默认值为 1
    Blue    // 默认值为 2
};

int main() {
    Color color = Green;  // 使用枚举类型变量
    cout << "The value of Green is: " << color << endl;  // 输出: The value of Green is: 1
    return 0;
}

```
枚举变量默认底层为`int`

### Map `unordered_map`
#### 基本用法

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    // 声明一个unordered_map，键为int，值为string
    std::unordered_map<int, std::string> umap;
    // 插入元素
    umap[1] = "apple";
    umap[2] = "banana";
    umap[3] = "cherry";
    // 通过键访问值
    std::cout << "Key 1: " << umap[1] << std::endl;  // apple
    // 查找元素
    auto it = umap.find(2);
    if (it != umap.end()) {
        std::cout << "Key 2: " << it->second << std::endl;  // banana
    } else {
        std::cout << "Key not found!" << std::endl;
    }
    // 遍历 unordered_map
    for (const auto& pair : umap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }
    return 0;
}
```

#### 常见操作

1. **插入元素**
   - 使用 `operator[]` 可以插入或修改元素。如果键不存在，会创建一个新元素。
   - `insert()` 方法可以插入一个键值对，但如果键已经存在，它不会修改现有元素。

   ```cpp
   umap[4] = "date";  // 插入新元素
   umap.insert({5, "elderberry"});  // 另一种插入方法
   ```

2. **查找元素**
   - 使用 `find()` 方法查找元素，如果找到返回一个指向该元素的迭代器，找不到则返回 `end()`。

   ```cpp
   auto it = umap.find(3);  // 查找键为3的元素
   if (it != umap.end()) {
       std::cout << "Found: " << it->second << std::endl;
   }
   ```

3. **删除元素**
   - 使用 `erase()` 删除指定键的元素。

   ```cpp
   umap.erase(2);  // 删除键为2的元素
   ```

4. **大小与清空**
   - `size()` 返回 `unordered_map` 中元素的数量。
   - `clear()` 清空所有元素。

   ```cpp
   std::cout << "Size: " << umap.size() << std::endl;
   umap.clear();  // 清空所有元素
   ```

5. **检查键是否存在**
   - 可以通过 `count()` 方法检查某个键是否存在。`count()` 对于 `unordered_map` 会返回 0 或 1，因为键是唯一的。

   ```cpp
   if (umap.count(1) > 0) {
       std::cout << "Key 1 exists!" << std::endl;
   }
   ```
6. **得到Key**
   ```cpp
    // 遍历 map 输出所有的 key
    std::cout << "Keys in the map:" << std::endl;
    for (const auto& pair : my_map) {
        std::cout << pair.first << std::endl;  // 输出键
    }
   ```
    my_map 是一个 `std::map<int, std::string>`，键是 `int` 类型，值是 `std::string` 类型。
    使用` for (const auto& pair : my_map) `来遍历 `map `中的所有元素。每个元素是一个键值对`std::pair<const Key, T>`，`pair.first `是键，`pair.second` 是值。
    通过 `pair.first `输出所有的键。

### 数论
计算阶乘、幂的时候，可以用到快速幂去计算结果
注意，奇数的时候将结果传入,偶数的时候自己乘自己
```cpp
long long quickPow(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod;  // 防止a超出mod范围
    while (b > 0) {
        if (b % 2 == 1) {  // 如果b是奇数，乘上a
            result = (result * a) % mod;
        }
        a = (a * a) % mod;  // 将a平方
        b /= 2;  // b减半
    }
    return result;
}
```

### 数据类型
* 整数转换:
  * c语法:`int intVal = (int)f;`
  * cpp:`int intVal2 = static_cast<int>(f); `
  * 使用函数:`floor(),ceil(),round()`


### 小记录
* for循环会先判断条件再进行
* tuple访问，`get<index>(t)`
* cpp中，mode得到的结果符号和原来数字一致


