#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#if defined(HZ_PLATFORM_WINDOWS) || defined(HZ_PLATFORM_MACOS)

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {  

    Hazel::Log::Init();
    HZ_CORE_INFO("Initialized Log!");   
    HZ_WARN(" Var = {0}", 5); 

    
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app; 
    return 0; 
}
 
#endif

#endif // ENTRY_POINT_H