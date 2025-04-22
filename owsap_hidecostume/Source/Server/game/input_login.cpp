// Arat :

	d->SetPhase(PHASE_GAME);

// Altına Ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
	if (ch->GetQuestFlag("costume_option.hide_body") != 0)
		ch->SetBodyCostumeHidden(true);
	else
		ch->SetBodyCostumeHidden(false);

	if (ch->GetQuestFlag("costume_option.hide_hair") != 0)
		ch->SetHairCostumeHidden(true);
	else
		ch->SetHairCostumeHidden(false);

	#ifdef __ACCE_COSTUME_SYSTEM__
	if (ch->GetQuestFlag("costume_option.hide_acce") != 0)
		ch->SetAcceCostumeHidden(true);
	else
		ch->SetAcceCostumeHidden(false);
	#endif

	#ifdef __WEAPON_COSTUME_SYSTEM__
	if (ch->GetQuestFlag("costume_option.hide_weapon") != 0)
		ch->SetWeaponCostumeHidden(true);
	else
		ch->SetWeaponCostumeHidden(false);
	#endif
#endif
