
PRJ_ROOT     := $(shell pwd)
PRJ_NAME     := BaseSerialize
PRG_NAME  := lib$(PRJ_NAME).so
OUT_DIR   := ../bin_linux
IMD_DIR   := .

# 定义源文件列表，注意此处并不包含头文件，此次出必须根据项目中的文件对应的添加文件名
CPP_SRCS := $(shell find ./ -name "*.cpp")

INC_DIRS 	:= -I. -I/usr/include
LIBS_DIRS := -L/user/lib 
LIBS      := 
CXXFLAGS 	:= -fPIC -Wall -fmessage-length=0 
LDFLAGS  	:= -shared

ifeq ($(CONFIG),)
CONFIG=debug
endif

ifeq ($(CONFIG),debug)
CXXFLAGS += -O0 -g3 -D_DEBUG 
else
CXXFLAGS += -O2 -DNDEBUG 
endif

###############################################################################
# Section 3. 编译
###############################################################################

# 定义编译tagert
all: dumy $(OUT_DIR)/$(PRG_NAME)
dumy:
	@echo "Build status    : $(CXX) $(CONFIG)----------------------------"
# 编译每一个源文件成为目标文件，并同时生成源文件的依赖关系文件
$(IMD_DIR)/%.o: ./%.cpp
	@echo "Building file    : $<"
	@echo "$(CXX) $(CXXFLAGS) -o $@ -c $<"
	@$(CXX) $(CXXFLAGS) $(INC_DIRS) -o $@ -c $< && \
	echo -n $(@:%.o=%.d) $(dir $@) > $(@:%.o=%.d) && \
	$(CXX) $(INC_DIRS) -MM -MG -P -w -c $< >> $(@:%.o=%.d)
	@echo "Finished building: $<"
	@echo " "

# 定义模块编译时的目标文件列表
OBJS += $(CPP_SRCS:./%.cpp=$(IMD_DIR)/%.o)

# 定义模块所有源文件的依赖关系列表
DEPS := $(OBJS:%.o=%.d)

# 包含所有的依赖文件*.d，用于更新所有的依赖关系，避免仅仅只是修改了头文件而不能编译的问题
-include $(DEPS)

# 编译最终的程序文件
$(OUT_DIR)/$(PRG_NAME): $(OBJS)
	@echo 'Building Target  : $@'
	$(AR) cr $@ $(OBJS)
	@echo 'Finished building: $@'
	@echo ' '

# 清理编译结果
clean:
	-$(RM) $(OBJS) $(DEPS) $(OUT_DIR)/$(PRG_NAME)

.PHONY: all clean 
