CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

build:
	g++ $(CFLAGS) src/main.cpp -o bin/VulkanTest $(LDFLAGS)
.PHONY: test clean

run:
	g++ $(CFLAGS) src/*.cpp -o bin/VulkanTest $(LDFLAGS)
	./bin/VulkanTest
test:
	./bin/VulkanTest
clean:
	rm -f bin/VulkanTest