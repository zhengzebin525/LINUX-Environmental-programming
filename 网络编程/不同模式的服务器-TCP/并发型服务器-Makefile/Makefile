SRC = $(wildcard *.c)                     #获取当前路径下所有.c文件
ELF := $(patsubst %.c, %.elf, $(SRC))     #将获取到的.c文件替换成可执行文件.elf文件
ELF := $(filter-out wrap.elf, $(ELF))     #filter-out 是反过滤函数，过滤掉.elf中的wrap.elf,因为wrap.存放的是封装函数,不需要变成可执行文件

CPPFLAGS +=                     #指定头文件的路径

LDFLAGS  += -lpthread           #指定要链接的库的路径，那为什么我这里却写了要链接的库而不是库路径呢，原因在下面解释了：

LIBS += 						#指定要链接的库，不过链接阶段LDFLAGS和LIBS这两个都会被加入，所以两者参数互换也没有问题

all:$(ELF)

$(ELF):%.elf:%.c wrap.c         # %.elf 是生成$(ELF)的依赖文件;%.c wrap.c 是生成%.elf的依赖文件；后者的生成离不开前者的任何一个
	gcc -o $@ $^ $(CPPFLAGS) $(LDFLAGS)   
	
clean:             
	-@$(RM) $(ELF)             #删除.elf文件，就算遇到错误也要删，并且删除命令不要显示出来
	-@echo "Done."

.PHONY:all clean               # 这个一般用不到
