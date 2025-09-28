#include "hzpch.h"
#include "MacosWindow.h"

namespace Hazel {
	
	static bool s_GLFWInitialized = false;

#if defined(HZ_PLATFORM_MACOS)
    Window* Window::Create(const WindowProps& props)
	{
		return new MacOSWindow(props);
	}
#endif

	MacOSWindow::MacOSWindow(const WindowProps& props)
	{
		Init(props);
	}

	MacOSWindow::~MacOSWindow()
	{
		Shutdown();
	}

	void MacOSWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			HZ_CORE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void MacOSWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void MacOSWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void MacOSWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool MacOSWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}
