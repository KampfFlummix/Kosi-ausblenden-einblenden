// Arat :

#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

// Altına Ekle :

#ifdef ENABLE_HIDE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_HIDE_COSTUME_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_HIDE_COSTUME_SYSTEM", 0);
#endif