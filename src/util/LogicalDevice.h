#ifndef LOGICAL_DEVICE_H
#define LOGICAL_DEVICE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

VkDevice createLogicalDevice(VkPhysicalDevice physicalDevice, VkQueue *graphicsQueue, VkQueue *presentQueue, VkSurfaceKHR surface);

#endif