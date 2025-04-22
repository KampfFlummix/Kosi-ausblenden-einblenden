// Arat :

	void RegisterPCFunctionTable()

// Üstüne Ekle :

#ifdef __HIDE_COSTUME_SYSTEM__ // MartySama code source
	ALUA(pc_hide_costume()
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

		if (!lua_isnumber(L, 1))
		{
			sys_err("pc_hide_costume::wrong part value (1-4)");
			return 0;
		}

		if (!lua_isboolean(L, 2))
		{
			sys_err("Invalid argument: arg2 must be boolean.");
			return 0;
		}

		/*
		* 1 : WEAR_COSTUME_BODY
		* 2 : WEAR_COSTUME_HAIR
		* 3 : WEAR_COSTUME_ACCE
		* 4 : WEAR_COSTUME_WEAPON
		*/
		BYTE bPartPos = (BYTE)lua_tonumber(L, 1);
		bool hidePart = lua_toboolean(L, 2);

		if (bPartPos == 1)
			ch->SetBodyCostumeHidden(hidePart);
		else if (bPartPos == 2)
			ch->SetHairCostumeHidden(hidePart);
		else if (bPartPos == 3)
			ch->SetAcceCostumeHidden(hidePart);
		else if (bPartPos == 4)
			ch->SetWeaponCostumeHidden(hidePart);
		else
		{
			sys_err("Invalid part");
			return 0;
		}

		ch->UpdatePacket();
		return 0;
	}
#endif

/////////////////////////////////////////////////////////////////////////////

#ifdef __HIDE_COSTUME_SYSTEM__ // Other code source
	int pc_hide_costume(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

		if (!lua_isnumber(L, 1))
		{
			sys_err("pc_hide_costume::wrong part value (1-4)");
			return 0;
		}

		if (!lua_isboolean(L, 2))
		{
			sys_err("Invalid argument: arg2 must be boolean.");
			return 0;
		}

		/*
		* 1 : WEAR_COSTUME_BODY
		* 2 : WEAR_COSTUME_HAIR
		* 3 : WEAR_COSTUME_ACCE
		* 4 : WEAR_COSTUME_WEAPON
		*/
		BYTE bPartPos = (BYTE)lua_tonumber(L, 1);
		bool hidePart = lua_toboolean(L, 2);

		if (bPartPos == 1)
			ch->SetBodyCostumeHidden(hidePart);
		else if (bPartPos == 2)
			ch->SetHairCostumeHidden(hidePart);
		else if (bPartPos == 3)
			ch->SetAcceCostumeHidden(hidePart);
		else if (bPartPos == 4)
			ch->SetWeaponCostumeHidden(hidePart);
		else
		{
			sys_err("Invalid part");
			return 0;
		}

		ch->UpdatePacket();
		return 0;
	}
#endif

// Arat :

			{ NULL, NULL }

// Üstüne Ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
			{ "hide_costume", pc_hide_costume },
#endif
