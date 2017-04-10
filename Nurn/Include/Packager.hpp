#pragma once

#include "NetworkDefines.hpp"

#include "PacketEnums.hpp"
#include "PacketQueueInterface.hpp"
#include "PacketQueue.hpp"
#include "Packets/AIStatePacket.hpp"
#include "Packets/AnimationPacket.hpp"
#include "Packets/TransformPacket.hpp"
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

#define packetSize 1400

class Packager
{
public:
#ifdef DEBUGGING_NETWORK
	Packager(DebugNetwork * debugNetwork_ptr);
#else
	Packager();
#endif
	virtual ~Packager();
	void shutdown();

	unsigned char * getPacketPointer();
	uint16_t getCurrentNetPacketSize() const;

	void buildNetPacket(); 
	std::shared_ptr<PacketQueueInterface> getQueue(const uint8_t& packetEnum);

	template<class packetType>
	void addNewQueue(const int& size);

private:
	unsigned char * memory;

	std::vector<std::shared_ptr<PacketQueueInterface>> queueList;

	uint16_t currentNetPacketSize;

#ifdef DEBUGGING_NETWORK
	DebugNetwork *debugNetwork_ptr;
#endif

	void addNewPackets(uint16_t &netPacketSize, bool& fullPackage, const uint8_t& packetEnum);
	void addMetaDataPacket(const uint16_t& type, uint16_t& netPacketSize, const uint16_t& sizeInBytes); // After a group of packets have been added the MetaData is added.

#ifdef DEBUGGING_NETWORK
	void addPingPacket(uint16_t& netPacketSize, bool& fullPackage); // Only added when debugging
#endif
};