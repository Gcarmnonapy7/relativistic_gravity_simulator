#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "physics.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class Renderer
{

private : 
    GLFWwindow* window;
    GLuint shader_program;
    GLuint vao, vbo; // Vertex Array Object and Vertex Buffer Object for rendering particles

    int window_width , window_height;
    float camera_distance;
    float angle_x, angle_y; // Camera angles for rotation
    Vec3 camera_target; // Point the camera is looking at

    bool init_glfw();
    bool init_opengl();

    GLuint compile_shader(const char* vertex_src, const char* fragment_src); // Compile vertex and fragment shaders

public:

    Renderer(int width, int height);
    ~Renderer();

    bool init();
    void input_void(float delta_time); // Handle user input for camera control
    void render(const std::vector<Particle>& particles, const Vec3& position); // Render particles and the position of the object
    bool should_close() const; // Check if the window should close
    void swap_buffers(); // Swap the front and back buffers
    void poll_events(); // Poll for and process events

};

#endif // RENDERER_HPP