#include "kessel.h"


/*
 * This function is a starting point for creating your own user interface. I just create a UI window and
 * add a timer. Other elements can be added by putting them between ImGui::Begin() and ImGui::End()
 */
void DrawInterfaceWindow() {
	// Create a new ImGui window to show the image - call it whatever you want
	ImGui::Begin("Your Interface");

	// Display the render time for a single pass through the main loop
	ImGui::Text("Render Time: %fms", frame_seconds * 1000);

	// This is the only thing displayed in the window
	ImGui::End();
}

/*
* This function renders the user interface. I'm actually cheating a little bit here: the only user
* interface window that's rendered is a "demo" that comes with the ImGui library. It basically has a
* bunch of widgets that show what ImGui is capable of, so you have some interesting stuff to play with
* and I didn't actually have to program any of it.
* 
* In any case, you can add your own user interface elements here.
*/
void ImGuiRender() {

	// These functions initialize the UI rendering process with both OpenGL and GLFW
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();

	// This function creates a new "Frame", which is the basic foundation of an ImGui UI
	ImGui::NewFrame(); {

		// Plot the gravity wells as points as well as any paths through the field
		PlotPaths(gx, gy, px, py);
	}
	
	// This function makes the graphics API calls (in this case OpenGL) to render the user interface
	ImGui::Render();

	// This actually copies the GUI to the OpenGL frame buffer (in this case probably the GLFW back buffer)
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}