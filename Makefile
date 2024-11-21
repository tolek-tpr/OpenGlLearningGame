CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

VulkanTest:
	g++ $(CFLAGS) src/main.cpp -o bin/VulkanTest $(LDFLAGS)
.PHONY: test clean

test:
	./bin/VulkanTest
clean:
	rm -f bin/VulkanTest