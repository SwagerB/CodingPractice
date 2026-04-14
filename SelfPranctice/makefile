# 编译器
CC = gcc

# 编译选项（-Wall 开启警告，-g 添加调试信息）
CFLAGS = -Wall -g

# 目标可执行文件名
TARGET = Seqlist

# 依赖的源文件
SRCS = Seqlist.c fun.c

# 生成的目标文件（将 .c 替换为 .o）
OBJS = $(SRCS:.c=.o)

# 默认规则：生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# 规则：将每个 .c 文件编译成 .o 文件
%.o: %.c fun.h
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 重新编译（先清理再构建）
rebuild: clean $(TARGET)

# 声明伪目标（不对应实际文件）
.PHONY: clean rebuild