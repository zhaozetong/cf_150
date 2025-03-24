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


### 小记录
* for循环会先判断条件再进行
* tuple访问，`get<index>(t)`
