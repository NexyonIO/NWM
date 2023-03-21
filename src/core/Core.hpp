#pragma once

#include "core/Application.hpp"
#include "service/Service.hpp"

#include <memory>


namespace NexyonIO::NWM
{    
    void ServiceHandler(NP_Service_Event event);
    
    std::shared_ptr<Application> GetApplication();
}

