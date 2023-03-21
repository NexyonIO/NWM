#include "core/Application.hpp"
#include "core/Core.hpp"

#include <memory>

std::shared_ptr<NexyonIO::NWM::Application> __app;

namespace NexyonIO::NWM
{
    std::shared_ptr<Application> GetApplication()
    {
        return __app;
    }
}

int main(int argc, char **argv)
{
    __app = std::make_shared<NexyonIO::NWM::Application>();

    return __app->Main(argc, argv);
}

