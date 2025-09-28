#ifndef APPLICATION_H   
#define APPLICATION_H

#include "Core.h"
#include "Events/Event.h"

namespace Hazel {

    class HAZEL_API  Application {
    public:
        Application();
        virtual ~Application();
        
        void Run();

    private:
        std::unique_ptr<class Window> m_Window;

        bool m_Running = true;
    };

    // To be defined in CLIENT
    Application* CreateApplication();  


}


#endif // APPLICATION_H