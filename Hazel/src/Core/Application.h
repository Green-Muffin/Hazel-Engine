#ifndef APPLICATION_H   
#define APPLICATION_H

#include "Core.h"

namespace Hazel {

    class HAZEL_API  Application {
    public:
        Application();
        virtual ~Application();
        
        void Run();
    };

    // To be defined in CLIENT
    Application* CreateApplication();  

}


#endif // APPLICATION_H