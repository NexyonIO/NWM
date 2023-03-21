#include "core/Application.hpp"
#include "service/Service.hpp"

#include <napi/core.h>

#include <memory>
#include <stdio.h>

namespace NexyonIO::NWM
{
    Application::Application()
    {
        this->m_Service = std::make_shared<NexyonIO::NWM::Service>();
    }

    Application::~Application()
    {
        np_log(NP_DEBUG, "~Application: closing connection with napid");
        np_destroy();
    }

    void Application::NapidConnect(int32_t argc, char **argv)
    {
        if (np_alive())
        {
            return;
        }

        np_log(NP_DEBUG, "NapidConnect: attempting to connect to napid");
        
        do
        {
            np_main(argc, argv);
        } while (!np_alive());

        np_log(NP_DEBUG, "NapidConnect: connected");
    }

    int32_t Application::Main(int32_t argc, char **argv)
    {
        np_log(NP_DEBUG, "Main: initializing NWM");
        this->NapidConnect(argc, argv);

        np_log(NP_INFO, "Main: registering NWM Service");
        this->m_Service->RegisterService();

        getchar();

        return 0;
    }

    void Application::HandleMessage(uint64_t service_source, const char *message)
    {
        printf("Message[%ld]: %s\n", service_source, message);
    }

}

