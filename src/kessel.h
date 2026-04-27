#pragma once

// OpenGL Extension Wrangler - declares functions used to find OpenGL function declarations
#include <GL/glew.h>

// GLFW - declares functions used for the GLFW window manager
#include <GLFW/glfw3.h>

// ImGui - declares functions used for the ImGui user interface
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

// ImPlot - used to generate plots in ImGui
#include <implot.h>
#include <implot_internal.h>

// used to time events (currently only the main loop is timed)
#include <chrono>

extern float* output_image_ptr;
extern int resolution;
extern float frame_seconds;
extern std::vector<float> gx;
extern std::vector<float> gy;
extern std::vector< std::vector<float> > px;
extern std::vector< std::vector<float> > py;

void ImGuiRender();
void DrawOutputImage();
void UpdateOutputTexture();
void PlotPaths(std::vector<float>& gx, std::vector<float>& gy,
    std::vector< std::vector<float> >& x, std::vector< std::vector<float> >& y);