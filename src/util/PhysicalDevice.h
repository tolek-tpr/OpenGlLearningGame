#ifndef PHYSICAL_DEVICE_H
#define PHYSICAL_DEVICE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

VkPhysicalDevice pickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface);

#endif