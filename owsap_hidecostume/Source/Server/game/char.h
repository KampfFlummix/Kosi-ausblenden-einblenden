// Arat :

};

ESex GET_SEX(LPCHARACTER ch);

#endif

// Üstüne Ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
public:
	void SetBodyCostumeHidden(bool hidden);
	bool IsBodyCostumeHidden() const { return m_bHideBodyCostume; };

	void SetHairCostumeHidden(bool hidden);
	bool IsHairCostumeHidden() const { return m_bHideHairCostume; };

	#ifdef __ACCE_COSTUME_SYSTEM__
	void SetAcceCostumeHidden(bool hidden);
	bool IsAcceCostumeHidden() const { return m_bHideAcceCostume; };
	#endif

	#ifdef __WEAPON_COSTUME_SYSTEM__
	void SetWeaponCostumeHidden(bool hidden);
	bool IsWeaponCostumeHidden() const { return m_bHideWeaponCostume; };
	#endif

private:
	bool m_bHideBodyCostume;
	bool m_bHideHairCostume;
	#ifdef __ACCE_COSTUME_SYSTEM__
	bool m_bHideAcceCostume;
	#endif
	#ifdef __WEAPON_COSTUME_SYSTEM__
	bool m_bHideWeaponCostume;
	#endif
#endif