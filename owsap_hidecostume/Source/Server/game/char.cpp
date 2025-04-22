// Arat :

m_iSyncHackCount = 0;

// Altına Ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
	m_bHideBodyCostume = false;
	m_bHideHairCostume = false;
	m_bHideAcceCostume = false;
	m_bHideWeaponCostume = false;
#endif

// Arat :

WORD CHARACTER::GetPart(BYTE bPartPos) const
{
	assert(bPartPos < PART_MAX_NUM);
	return m_pointsInstant.parts[bPartPos];
}
--
OU
--
{
	assert(bPartPos < PART_MAX_NUM);
	return m_pointsInstant.parts[bPartPos];
}

// Kod bloğunun içine ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
	if (bPartPos == PART_MAIN && GetWear(WEAR_COSTUME_BODY) && IsBodyCostumeHidden() == true)
	{
		if (const LPITEM pArmor = GetWear(WEAR_BODY))
#ifdef __CHANGE_LOOK_SYSTEM__
			return pArmor->GetTransmutation() != 0 ? pArmor->GetTransmutation() : pArmor->GetVnum();
#else
			return pArmor->GetVnum();
#endif
		else
			return 0;
	}
	else if (bPartPos == PART_HAIR && GetWear(WEAR_COSTUME_HAIR) && IsHairCostumeHidden() == true)
		return 0;
	else if (bPartPos == PART_ACCE && GetWear(WEAR_COSTUME_ACCE) && IsAcceCostumeHidden() == true)
		return 0;
	else if (bPartPos == PART_WEAPON && GetWear(WEAR_COSTUME_WEAPON) && IsWeaponCostumeHidden() == true)
	{
		if (const LPITEM pWeapon = GetWear(WEAR_WEAPON))
#ifdef __CHANGE_LOOK_SYSTEM__
			return pWeapon->GetTransmutation() != 0 ? pWeapon->GetTransmutation() : pWeapon->GetVnum();
#else
			return pWeapon->GetVnum();
#endif
		else
			return 0;
	}
#endif

// Örnek :

WORD CHARACTER::GetPart(BYTE bPartPos) const
{
	assert(bPartPos < PART_MAX_NUM);
#ifdef __HIDE_COSTUME_SYSTEM__
	if (bPartPos == PART_MAIN && GetWear(WEAR_COSTUME_BODY) && IsBodyCostumeHidden() == true)
	{
		if (const LPITEM pArmor = GetWear(WEAR_BODY))
#ifdef __CHANGE_LOOK_SYSTEM__
			return pArmor->GetTransmutation() != 0 ? pArmor->GetTransmutation() : pArmor->GetVnum();
#else
			return pArmor->GetVnum();
#endif
		else
			return 0;
	}
	else if (bPartPos == PART_HAIR && GetWear(WEAR_COSTUME_HAIR) && IsHairCostumeHidden() == true)
		return 0;
	else if (bPartPos == PART_ACCE && GetWear(WEAR_COSTUME_ACCE) && IsAcceCostumeHidden() == true)
		return 0;
	else if (bPartPos == PART_WEAPON && GetWear(WEAR_COSTUME_WEAPON) && IsWeaponCostumeHidden() == true)
	{
		if (const LPITEM pWeapon = GetWear(WEAR_WEAPON))
#ifdef __CHANGE_LOOK_SYSTEM__
			return pWeapon->GetTransmutation() != 0 ? pWeapon->GetTransmutation() : pWeapon->GetVnum();
#else
			return pWeapon->GetVnum();
#endif
		else
			return 0;
	}
#endif
	return m_pointsInstant.parts[bPartPos];
}

// Arat :

WORD CHARACTER::GetOriginalPart(BYTE bPartPos) const

// Komple Değiştir :

// Kendi Sourcenize Uyumlu olsun

WORD CHARACTER::GetOriginalPart(BYTE bPartPos) const
{
	switch (bPartPos)
	{
	case PART_MAIN:
#ifdef __HIDE_COSTUME_SYSTEM__
		if (GetWear(WEAR_COSTUME_BODY) && IsBodyCostumeHidden() == true)
			if (const LPITEM pArmor = GetWear(WEAR_BODY))
				return pArmor->GetVnum();
#endif
		if (!IsPC()) 
			return GetPart(PART_MAIN);
		else
			return m_pointsInstant.bBasePart;

	case PART_HAIR:
#ifdef __HIDE_COSTUME_SYSTEM__
		if (GetWear(WEAR_COSTUME_HAIR) && IsHairCostumeHidden() == true)
			return 0;
#endif
		return GetPart(PART_HAIR);

#ifdef __ACCE_COSTUME_SYSTEM__
	case PART_ACCE:
#ifdef __HIDE_COSTUME_SYSTEM__
		if (GetWear(WEAR_COSTUME_ACCE) && IsAcceCostumeHidden() == true)
			return 0;
#endif
		return GetPart(PART_ACCE);
#endif

#ifdef __WEAPON_COSTUME_SYSTEM__
	case PART_WEAPON:
#ifdef __HIDE_COSTUME_SYSTEM__
		if (GetWear(WEAR_COSTUME_WEAPON) && IsWeaponCostumeHidden() == true)
			if (const LPITEM pWeapon = GetWear(WEAR_WEAPON))
				return pWeapon->GetVnum();
#endif
		return GetPart(PART_WEAPON);
#endif

	default:
		return 0;
	}
}

// Dosyanın sonuna ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
void CHARACTER::SetBodyCostumeHidden(bool hidden)
{
	m_bHideBodyCostume = hidden;
	ChatPacket(CHAT_TYPE_COMMAND, "SetBodyCostumeHidden %d", m_bHideBodyCostume ? 1 : 0);
	SetQuestFlag("costume_option.hide_body", m_bHideBodyCostume ? 1 : 0);
}

void CHARACTER::SetHairCostumeHidden(bool hidden)
{
	m_bHideHairCostume = hidden;
	ChatPacket(CHAT_TYPE_COMMAND, "SetHairCostumeHidden %d", m_bHideHairCostume ? 1 : 0);
	SetQuestFlag("costume_option.hide_hair", m_bHideHairCostume ? 1 : 0);
}

#ifdef __ACCE_COSTUME_SYSTEM__
void CHARACTER::SetAcceCostumeHidden(bool hidden)
{
	m_bHideAcceCostume = hidden;
	ChatPacket(CHAT_TYPE_COMMAND, "SetAcceCostumeHidden %d", m_bHideAcceCostume ? 1 : 0);
	SetQuestFlag("costume_option.hide_acce", m_bHideAcceCostume ? 1 : 0);
}
#endif

#ifdef __WEAPON_COSTUME_SYSTEM__
void CHARACTER::SetWeaponCostumeHidden(bool hidden)
{
	m_bHideWeaponCostume = hidden;
	ChatPacket(CHAT_TYPE_COMMAND, "SetWeaponCostumeHidden %d", m_bHideWeaponCostume ? 1 : 0);
	SetQuestFlag("costume_option.hide_weapon", m_bHideWeaponCostume ? 1 : 0);
}
#endif
#endif
