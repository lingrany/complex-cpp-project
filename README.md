# C++ 字符串处理项目

这是一个演示测试驱动开发（TDD）的C++项目，包含更复杂的字符串处理功能。

## 项目功能

1. **元音字母计数** - 计算字符串中元音字母的数量（a, e, i, o, u）
2. **单词反转** - 反转字符串中的单词顺序
3. **回文检查** - 检查字符串是否为回文（忽略大小写和非字母字符）

## 项目结构

```
complex-cpp-project/
├── Dockerfile              # Docker配置文件
├── CMakeLists.txt          # CMake构建配置
├── string_processor.h/cpp  # 字符串处理实现（包含一个故意的bug）
├── main.cpp                # 测试用例
├── code.patch              # 修复bug的补丁
├── test.patch              # 添加测试用例的补丁
├── run_verification.py     # 自动化验证脚本
├── setup_env.sh            # 环境设置脚本
├── setup_repo.sh           # 仓库设置脚本
└── README.md               # 项目说明文档
```

## 如何运行

### 使用Docker（推荐）

```bash
# 构建Docker镜像
docker build -t complex-cpp-project .

# 运行验证
docker run --rm complex-cpp-project
```

### 本地运行

```bash
# 应用测试补丁
patch main.cpp test.patch

# 构建项目
mkdir build
cmake -S . -B build
cmake --build build

# 运行测试（应该会失败，因为存在bug）
./build/run_tests

# 应用代码修复补丁
patch string_processor.cpp code.patch

# 重新构建并运行测试（现在应该会通过）
cmake --build build
./build/run_tests
```

## 工作原理

1. 项目首先应用测试补丁，添加回文检查的测试用例
2. 构建并运行测试，验证测试确实失败（证明bug存在）
3. 应用代码修复补丁，修正回文检查方法中的bug
4. 再次构建并运行测试，验证测试通过（证明bug已修复）