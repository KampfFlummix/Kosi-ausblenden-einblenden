// Arat :

struct command_info cmd_info[] =

// Üstüne Ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
ACMD(do_hide_costume);
#endif

// Arat :

	{ "\n", NULL, 0, POS_DEAD, GM_IMPLEMENTOR }

// Üstüne Ekle :

#ifdef __HIDE_COSTUME_SYSTEM__
	{ "hide_costume", do_hide_costume, 0, POS_DEAD, GM_PLAYER },
#endif