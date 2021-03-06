#pragma once

#include <iostream>

#define TRANSFORM_PACKET 0
#define ANIMATION_PACKET 1
#define AI_STATE_PACKET 2
#define SPELL_PACKET 3
#define AI_TRANSFORM_PACKET 4
#define CHARGING_PACKET 5
#define QUICKBLEND_PACKET 6
#define DAMAGE_PACKET 7
#define CHANGESPELLS_PACKET 8
#define PLAYER_EVENT_PACKET 9
#define AI_HEALTH_PACKET 10
#define DASH_PACKET 11
#define END_EVENT_PACKET 12
#define PLAYER_HEALTH_PACKET 13
#define RESSURECTION_PACKET 14
#define AI_DAMAGE_TEXT_PACKET 15
#define BOSS_DAMAGE_TEXT_PACKET 16
#define BOSS_HEALTH_PACKET 17


// Only used when DEBUGGING_NETWORK in NetworkDefines == 1
#define PING_PACKET 20