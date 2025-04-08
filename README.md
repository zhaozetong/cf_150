## 刷题记录文档

### 重要函数
#### 1.sort()
**简介**
`std::sort` 是 C++ 标准库中用于排序的算法，位于 `<algorithm>` 头文件中。它通过快速排序算法实现，对容器（如数组、`vector`）中的元素进行排序。

- **基本用法：** 通过传入容器的开始和结束迭代器来排序。
- **自定义排序规则：** 通过传递比较函数或 lambda 表达式实现不同的排序规则。

1. **排序数组**

```cpp
std::sort(arr, arr + n);
```

2. **排序 `vector`**

```cpp
std::sort(vec.begin(), vec.end());
```

3. **降序排序（使用自定义比较函数）**

```cpp
std::sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
```

4. **排序复杂数据类型（如结构体）**

```cpp
std::sort(people.begin(), people.end(), comparePerson);
```

**示例代码**

```cpp
std::vector<int> vec = {5, 3, 8, 1, 2};

// 默认升序排序
std::sort(vec.begin(), vec.end());

// 自定义降序排序
std::sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
```

**总结**
- `std::sort` 是排序容器中元素的利器。
- 通过迭代器定义排序范围。
- 支持自定义排序规则（升序、降序等）。

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

### 无序Map `unordered_map`
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

### Map (`Map`)
`std::map` 是一个有序的键值对容器，基于**红黑树**实现。它存储唯一的键值对，并自动按照键进行排序。

特点：
* 有序：元素按键升序排列（默认），可以自定义排序方式。
* 唯一键：每个键只能出现一次。
* 查找、插入、删除操作：时间复杂度为 O(log n)。
* 自动排序：按键的升序（可以自定义）。

#### 常用操作：

1. **插入元素**：

   - 使用 `insert` 或通过 `[]` 运算符。

   ```cpp
   std::map<int, std::string> m;
   m[1] = "One"; // 插入或更新
   m.insert({2, "Two"}); // 插入新元素
   ```

2. **查找元素**：

   - 使用 `find`，返回一个迭代器。

   ```cpp
   auto it = m.find(1); // 查找键为 1 的元素
   if (it != m.end()) {
       std::cout << it->second; // 输出 "One"
   }
   ```

3. **访问元素**：

   - 使用 `[]` 运算符可以访问和修改元素。

   ```cpp
   m[3] = "Three"; // 插入键值对
   std::cout << m[3]; // 输出 "Three"
   ```

4. **删除元素**：

   - 使用 `erase` 按键删除元素。

   ```cpp
   m.erase(1); // 删除键为 1 的元素
   ```

5. **遍历 `map`**：

   - 使用迭代器遍历。

   ```cpp
   for (auto it = m.begin(); it != m.end(); ++it) {
       std::cout << it->first << ": " << it->second << std::endl;
   }
   ```
6. **查找最大最小值**：
   * 最小键：`map` 的 `begin()` 返回指向第一个元素的迭代器，该元素即为最小的键值对`auto p = map.begin()`,`p->first`得到key，`p->second`得到value。
   * 最大键：`map` 的 `rbegin()` 返回指向最后一个元素的逆向迭代器，该元素即为最大的键值对。


#### 自定义排序：

- 使用自定义比较器进行降序或其他排序方式(默认排序为**升序**)。

  ```cpp
  std::map<int, std::string, std::greater<int>> m; // 按降序排列
  m[3] = "Three";
  m[1] = "One";
  m[2] = "Two";
  ```

### Multi_Map
`std::multimap` 是 C++ STL 中的一个容器，它类似于 `std::map`，但是允许**多个元素具有相同的键**。它是一个有序关联容器，每个键可以对应多个值。

#### 特点：

- **有序**：元素按键的顺序排列，默认升序（可自定义排序规则）。
- **允许重复键**：同一键可以插入多个值。
- **自动排序**：插入时自动根据键排序。
- **查找、插入、删除操作**：时间复杂度为 O(log n)。

#### 常用操作：

1. **插入元素**：

   ```cpp
   std::multimap<int, std::string> m;
   m.insert({1, "One"});
   m.insert({1, "First One"});
   m.insert({2, "Two"});
   ```

2. **遍历 `multimap`**：

   ```cpp
   for (const auto& pair : m) {
       std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
   }
   ```

3. **查找某个键的所有值**：
   使用 `equal_range()` 查找所有具有相同键的元素。

   ```cpp
   auto range = m.equal_range(1);  // 查找键为 1 的所有元素
   for (auto it = range.first; it != range.second; ++it) {
       std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
   }
   ```

4. **删除元素**：
   使用 `erase()` 删除特定键或迭代器指向的元素。

   ```cpp
   m.erase(1);  // 删除所有键为 1 的元素
   ```

### 双端队列 deque
`std::deque`（双端队列）是 C++ STL 中的一个容器，它允许在队列的两端进行高效的插入和删除操作。与 `std::vector` 类似，`std::deque` 支持随机访问，但它的元素存储在多个块中，使得它可以在两端都进行高效的操作。

#### 特点：
- **双端访问**：支持从容器的两端进行插入、删除、访问等操作。
- **高效的两端插入和删除**：在两端插入和删除元素的时间复杂度是 O(1)。
- **支持随机访问**：可以通过索引直接访问任何元素，时间复杂度为 O(1)。
- **动态大小**：自动扩展，不需要预先定义大小。

#### 常用操作：
1. **定义和初始化**：
   ```cpp
   std::deque<int> dq;  // 创建一个空的 deque
   std::deque<int> dq2 = {1, 2, 3, 4};  // 用初始值初始化 deque
   ```

2. **添加元素**：
   - 在尾部添加元素：`push_back()`。
   - 在头部添加元素：`push_front()`。
   ```cpp
   dq.push_back(5);    // 在队列尾部添加元素 5
   dq.push_front(0);   // 在队列头部添加元素 0
   ```

3. **删除元素**：
   - 从尾部删除元素：`pop_back()`。
   - 从头部删除元素：`pop_front()`。
   ```cpp
   dq.pop_back();  // 删除队列尾部元素
   dq.pop_front(); // 删除队列头部元素
   ```

4. **访问元素**：
   - 使用索引访问元素：`operator[]` 或 `at()`。
   - `at()` 会进行边界检查，`operator[]` 不会。
   ```cpp
   std::cout << dq[0];  // 访问第一个元素
   std::cout << dq.at(1);  // 访问第二个元素，带边界检查
   ```

5. **查询容器信息**：
   - `size()` 获取容器的元素个数。
   - `empty()` 判断容器是否为空。
   ```cpp
   std::cout << dq.size();  // 获取队列的大小
   std::cout << dq.empty(); // 判断队列是否为空
   ```

6. **遍历 deque**：
   - 使用基于范围的 for 循环遍历。
   ```cpp
   for (const auto& val : dq) {
       std::cout << val << " ";
   }
   ```

7. **修改元素**：
   - 使用索引或迭代器修改元素。
   ```cpp
   dq[1] = 10;  // 修改第二个元素
   ```

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
* 删除元素  `vec.erase(std::remove_if(vec.begin(), vec.end(), [m](int x) { return x > m; }), vec.end());` 利用erase+remove_if
* `remove_if`是使用*双指针*去移动元素,效率还是蛮高的
* python 中使用`a = [0]*n`可以,但是`a=[[0]*n]*m`->(m,n)不太行,因为这样会直接引用数组而不是创建新的


