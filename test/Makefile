
PRJ_ROOT     := $(shell pwd)
PRJ_NAME     := SerializeTest
PRG_NAME  := $(PRJ_NAME)
OUT_DIR   := ../bin_linux
IMD_DIR   := .

# ����Դ�ļ��б���ע��˴���������ͷ�ļ����˴γ����������Ŀ�е��ļ���Ӧ�������ļ���
CPP_SRCS := $(shell find ./ -name "*.cpp")

INC_DIRS := -I. -I/usr/local/Qt-5.5.1/include -I../src 
LIBS_DIRS :=  -L/usr/local/Qt-5.5.1/lib -L$(OUT_DIR) -Wl,-rpath,./ 
LIBS      :=  -lQt5Core -lQt5Gui -lQt5Widgets -lBaseSerialize 
CXXFLAGS := -Wall -fmessage-length=0 -fPIC 
LDFLAGS  := 

ifeq ($(CONFIG),debug)
CXXFLAGS += -O0 -g3 -D_DEBUG 
else
CXXFLAGS += -O2 -DNDEBUG 
endif

###############################################################################
# Section 3. ����
###############################################################################

# �������tagert
all: dumy $(OUT_DIR)/$(PRG_NAME)
dumy:
	@echo "Build status    : $(CXX) $(CONFIG)----------------------------"
# ����ÿһ��Դ�ļ���ΪĿ���ļ�����ͬʱ����Դ�ļ���������ϵ�ļ�
$(IMD_DIR)/%.o: ./%.cpp
	@echo "Building file    : $<"
	@echo "$(CXX) $(CXXFLAGS) -o $@ -c $<"
	@$(CXX) $(CXXFLAGS) $(INC_DIRS) -o $@ -c $< && \
	echo -n $(@:%.o=%.d) $(dir $@) > $(@:%.o=%.d) && \
	$(CXX) $(INC_DIRS) -MM -MG -P -w -c $< >> $(@:%.o=%.d)
	@echo "Finished building: $<"
	@echo " "

# ����ģ�����ʱ��Ŀ���ļ��б�
OBJS += $(CPP_SRCS:./%.cpp=$(IMD_DIR)/%.o)

# ����ģ������Դ�ļ���������ϵ�б�
DEPS := $(OBJS:%.o=%.d)

# �������е������ļ�*.d�����ڸ������е�������ϵ���������ֻ���޸���ͷ�ļ������ܱ��������
-include $(DEPS)

# �������յĳ����ļ�
$(OUT_DIR)/$(PRG_NAME): $(OBJS)
	@echo 'Building Target  : $@'
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS_DIRS) $(LIBS)
	@echo 'Finished building: $@'
	@echo ' '

# ����������
clean:
	-$(RM) $(OBJS) $(DEPS) $(OUT_DIR)/$(PRG_NAME)

.PHONY: all clean 