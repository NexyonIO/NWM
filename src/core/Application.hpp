#pragma once

#include "service/Service.hpp"

#include <memory>

namespace NexyonIO::NWM
{
    class Application
    {
    public:
        Application();
        ~Application();

        void HandleMessage(uint64_t service_source, const char *message);
        void NapidConnect(int32_t argc, char **argv);

        int32_t Main(int32_t argc, char **argv);

    private:
        std::shared_ptr<NexyonIO::NWM::Service> m_Service;
        
    };

};

