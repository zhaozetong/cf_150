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

### 小记录
* for循环会先判断条件再进行
* tuple访问，`get<index>(t)`
* cpp中，mode得到的结果符号和原来数字一致


