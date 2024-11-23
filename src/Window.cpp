#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Window.h"
#include "util/std.hpp"
#include <stdexcept>

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

class TriangleApp {
    public:
        void run() {
            initWindow();
            initVulkan();
            glLoop();
            cleanup();
        }
    
    private:
        GLFWwindow* window;
        VkInstance vkInstance;

        void initWindow() {
            std::cout << "Starting VLG" << std::endl;
            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Vulkan window", NULL, NULL);
        }
        void createInstance() {
            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = "Hello Triangle";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "No Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;

            uint32_t glfwExtensionCount = 0;
            const char** glfwExtensions;

            glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

            createInfo.enabledExtensionCount = glfwExtensionCount;
            createInfo.ppEnabledExtensionNames = glfwExtensions;
            createInfo.enabledLayerCount = 0;

            if (vkCreateInstance(&createInfo, NULL, &vkInstance) != VK_SUCCESS) {
                throw std::runtime_error("Vulkan instance creation failed!");
            }
        }
        void initVulkan() {
            createInstance();
        }
        void glLoop() {
            while(!glfwWindowShouldClose(window)) {
                glfwPollEvents();
            }
        }
        void cleanup() {
            vkDestroyInstance(vkInstance, NULL);

            glfwDestroyWindow(window);
            glfwTerminate();
        }
};

int runApp() {
    TriangleApp a;

    try {
        a.run();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    };
    return EXIT_SUCCESS;
}