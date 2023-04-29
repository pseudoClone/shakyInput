CC = g++

CFLAGS = -g -Werror -std=c++17 

TARGET = lcp_im

all: $(TARGET)
$(TARGET): $(TARGET).cpp
		$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
		$(RM) $(TARGET)
