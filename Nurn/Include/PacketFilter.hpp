#pragma once

#include "NetworkDefines.hpp"

#include "PacketQueueInterface.hpp"
#include "PacketQueue.hpp"
#include "PacketEnums.hpp"
#include "Packets/AIStatePacket.hpp"
#include "Packets/TransformPacket.hpp"
#include "Packets/AnimationPacket.hpp"
#include "Packets/MetaDataPacket.hpp"
#include "Packets/SpellPacket.hpp"
#include "Packets/ChargingPacket.hpp"
#include "Packets/QuickBlendPacket.hpp"
#include "Packets/DamagePacket.hpp"
#include "Packets/ChangeSpellsPacket.hpp"
#include "Packets/EventPacket.hpp"
#include "Packets/HealthPacket.hpp"
#include "Packets/DashPacket.hpp"

#ifdef DEBUGGING_NETWORK
#include "Packets/PingPacket.hpp"
#include "Packets/DebugNetwork.hpp"
#endif

#include <vector>
#include <memory>

class PacketFilter
{
public:
#ifdef DEBUGGING_NETWORK
	PacketFilter(DebugNetwork *debugNetowrk_ptr);
#else
	PacketFilter();
#endif

	virtual ~PacketFilter();
	void shutdown();

	void openNetPacket(const unsigned char * const memoryPointer);
	
	std::shared_ptr<PacketQueueInterface> getQueue(const uint8_t& packetEnum);

	template<class packetType>
	void addNewQueue(const int& size);
	
private:
	std::vector<std::shared_ptr<PacketQueueInterface>> queueList;

#ifdef DEBUGGING_NETWORK
	DebugNetwork * debugNetwork_ptr;
#endif
};