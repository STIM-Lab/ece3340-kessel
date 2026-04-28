#include "kessel.h"

// This variable stores the OpenGL ID for the texture used to display the output image on the screen
GLuint output_image_tex = 0;


void PlotPaths(std::vector<float>& gx, std::vector<float>& gy,
    std::vector< std::vector<float> >& x, std::vector< std::vector<float> >& y) {

    ImGui::Begin("Plotted Courses");
    if (ImPlot::BeginPlot("My Plot")) {

        ImPlot::PlotScatter("kessel_run", &gx[0], &gy[0], static_cast<int>(gx.size()),
        {
                    ImPlotProp_Marker, ImPlotMarker_Square,
                    ImPlotProp_MarkerSize, 10,
                    ImPlotProp_LineColor, ImPlot::GetColormapColor(3),
                    ImPlotProp_FillColor, ImPlot::GetColormapColor(3),
                    ImPlotProp_FillAlpha, 0.25f
                }

            );

        for (int p = 0; p < x.size(); p++) {
            ImPlot::PlotLine("kessel_run", &x[p][0], &y[p][0], static_cast<int>(x[p].size()),
        {
                    ImPlotProp_Marker, ImPlotMarker_Circle,
                    ImPlotProp_MarkerSize, 3,
                    ImPlotProp_LineColor, ImPlot::GetColormapColor(p),
                    ImPlotProp_FillColor, ImPlot::GetColormapColor(p),
                    ImPlotProp_FillAlpha, 0.25f
                }

            );
        }
    }
    ImPlot::EndPlot();

    ImGui::End();

}