CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra
SRCS = src/main.cpp src/student.cpp src/studentManager.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = manage_student

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)