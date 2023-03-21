#pragma once

#include <napi/services.h>

#include <cstdint>

namespace NexyonIO::NWM
{
    typedef NP_Service_Event ServiceEvent;

    class Service
    {
    public:
        Service();
        ~Service();

        void RegisterService();
        void DestroyService();
        
        int32_t SendEvent(uint64_t service, ServiceEvent *event);
        
        uint64_t GetServiceId() const { return this->m_ServiceId; }

    private:
        uint64_t m_ServiceId;

    };

}

