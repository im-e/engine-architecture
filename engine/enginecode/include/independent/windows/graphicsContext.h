/** \file graphicsContext
*	\brief Interface class for all graphics contexts. Will combine windows tech with graphics API i.e. OPENGLGLFW or WIN32DIRECTX
*	Basically provides means for initialisation and swapchain implementation.
*/

#pragma once

/**	\class GraphicsContext
*	\briefInterface class for all graphics contexts. Will combine windows tech with graphics API i.e. OPENGLGLFW or WIN32DIRECTX
*	Basically provides means for initialisation and swapchain implementation.
*/
class GraphicsContext
{
public:
	virtual void init() = 0;
	virtual void swapBuffers() = 0;
};