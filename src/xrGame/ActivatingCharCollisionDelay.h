﻿#pragma once

class CCharacterPhysicsSupport;
class activating_character_delay
{
	CCharacterPhysicsSupport &char_support;
	u32 activate_time;
	static const u32 delay = 3000;
public:
	activating_character_delay(CCharacterPhysicsSupport *char_support_);
	//non copyable
	activating_character_delay(const activating_character_delay&) = delete;
	activating_character_delay& operator=(const activating_character_delay&) = delete;

	void update();
	bool active();
private:
	bool do_position_correct();
};
