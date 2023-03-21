#include "service/Service.hpp"
#include "core/Core.hpp"

#include <napi/services.h>
#include <napi/core.h>

namespace NexyonIO::NWM
{    
    Service::Service()
        : m_ServiceId(NP_SERVICE_NWM) { }
    Service::~Service()
    {
        np_log(NP_INFO, "~Service: destroying NWM Service");
        this->DestroyService();
    }

    void Service::RegisterService()
    {
        np_service_register(this->m_ServiceId, "NWM Service", 0x00, &ServiceHandler);
    }

    void Service::DestroyService()
    {
        np_service_unregister(this->m_ServiceId);
    }
    
    int32_t SendEvent(uint64_t service, ServiceEvent *event)
    {
        return np_service_send_event(service, event);
    }
    
    void ServiceHandler(NP_Service_Event event)
    {
        switch (event.type)
        {
        case NP_SERVICE_EVENT_MESSAGE:
            {
                GetApplication()->HandleMessage(event.source, (char*)event.value);
                break;
            }
        }
    }

}

