/*
 * File: main.cpp.
 * Created by: Alex.Braidwood.
 * Date: Feb 20, 2019.
 * Notice: Copyright (c) 2019 The Bat Forge. All Rights Reserved.
 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <util/diag.h>

static bool running;
static GLFWwindow* window;

static bool key_state[GLFW_KEY_LAST];

void key_callback(GLFWwindow* window, int keyCode, int scanCode, int action, int modifiers) {

    if (action == GLFW_PRESS) {
        key_state[keyCode] = true;
    }
    if (action == GLFW_RELEASE) {
        key_state[keyCode] = false;
    }
}

void cleanup() {
    glfwTerminate();
}

void set_gl_attributes() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void create_window() {
    window = glfwCreateWindow(800, 600, "Minesweeper", nullptr, nullptr);
}

void create_gl_context() {
    glfwMakeContextCurrent(window);
}

int main(int argc, char* argv[]) {
    glfwInit();
    glfwSetErrorCallback([](int errorCode, const char* errorText) -> void {
        printf("Error: %d - %s\n", errorCode, errorText);
        glfwTerminate();
    });

    set_gl_attributes();
    create_window();

    ALIB_ASSERT(window, "Failed to initialize GLFW.");

    create_gl_context();

    ALIB_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize GLAD.");

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, [](auto window, auto width, auto height) -> auto {
        glViewport(0, 0, width, height);
    });

    glfwSetKeyCallback(window, &key_callback);

    running = true;

    while (!glfwWindowShouldClose(window)) {
        if (key_state[GLFW_KEY_ESCAPE]) {
            glfwSetWindowShouldClose(window, true);
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    cleanup();
    return 0;
}

