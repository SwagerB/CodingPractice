#!/usr/bin/env zsh
# create_problem.sh NAME [c|cpp|both]
# Example: ./create_problem.sh 0001_two_sum both

set -e
NAME="$1"
LANG="${2:-both}"

if [ -z "$NAME" ]; then
  echo "Usage: $0 NAME [c|cpp|both]"
  exit 1
fi

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"

if [ "$LANG" = "c" ] || [ "$LANG" = "both" ]; then
  C_DIR="$ROOT_DIR/leetcode-c/$NAME"
  mkdir -p "$C_DIR"
  cat > "$C_DIR/main.c" <<'C_MAIN'
#include <stdio.h>
#include <stdlib.h>

// 题目: 0001_two_sum - 示例模板

int main(void) {
    // 在这里实现并测试你的解法
    printf("Hello from %s\n", "0001_two_sum (C)");
    return 0;
}
C_MAIN
  cat > "$C_DIR/Makefile" <<'C_MAKE'
CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra

.PHONY: run clean

run:
	$(CC) $(CFLAGS) main.c -o main
	./main

clean:
	rm -f main
C_MAKE
  cat > "$C_DIR/README.md" <<C_README
# $NAME (C)

把你的 C 源文件放在此目录下，主文件名为 `main.c`。
使用 `make run` 编译并运行，`make clean` 清理可执行文件。

你可以把 `main.c` 重命名或改成题号前缀，如 `0001_two_sum.c`，并在 Makefile 中相应修改。
C_README
fi

if [ "$LANG" = "cpp" ] || [ "$LANG" = "both" ]; then
  CPP_DIR="$ROOT_DIR/leetcode-cpp/$NAME"
  mkdir -p "$CPP_DIR"
  cat > "$CPP_DIR/main.cpp" <<'CPP_MAIN'
#include <iostream>
#include <vector>
using namespace std;

// 题目: 0001_two_sum - 示例模板 (C++)
int main() {
    cout << "Hello from " << "0001_two_sum (C++)" << endl;
    return 0;
}
CPP_MAIN
  cat > "$CPP_DIR/Makefile" <<'CPP_MAKE'
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

.PHONY: run clean

run:
	$(CXX) $(CXXFLAGS) main.cpp -o main
	./main

clean:
	rm -f main
CPP_MAKE
  cat > "$CPP_DIR/README.md" <<CPP_README
# $NAME (C++)

把你的 C++ 源文件放在此目录下，主文件名为 `main.cpp`。
使用 `make run` 编译并运行，`make clean` 清理可执行文件。
CPP_README
fi

echo "Created problem '$NAME' for: $LANG"
chmod +x "$ROOT_DIR/scripts/create_problem.sh"
