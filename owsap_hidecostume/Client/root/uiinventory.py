## Arat :

class CostumeWindow(ui.ScriptWindow):

## Classın içinde bul

self.__LoadWindow()

## Üstüne Ekle :

		if app.ENABLE_HIDE_COSTUME_SYSTEM:
			self.visibleButtonList = []

## Yine CostumeWindow'da Arat :

self.GetChild("TitleBar").SetCloseEvent(ui.__mem_func__(self.Close))

## Üstüne :

			if app.ENABLE_HIDE_COSTUME_SYSTEM:
				self.visibleButtonList.append(self.GetChild("BodyToolTipButton"))
				self.visibleButtonList.append(self.GetChild("HairToolTipButton"))
				self.visibleButtonList.append(self.GetChild("AcceToolTipButton"))
				self.visibleButtonList.append(self.GetChild("WeaponToolTipButton"))

## Arat :

	def RefreshCostumeSlot(self):

## Üstüne Ekle :

		if app.ENABLE_HIDE_COSTUME_SYSTEM:
			self.visibleButtonList[0].SetToggleUpEvent(ui.__mem_func__(self.VisibleCostume), 1, 0)
			self.visibleButtonList[1].SetToggleUpEvent(ui.__mem_func__(self.VisibleCostume), 2, 0)
			if app.ENABLE_ACCE_COSTUME_SYSTEM:
				self.visibleButtonList[2].SetToggleUpEvent(ui.__mem_func__(self.VisibleCostume), 3, 0)
			if app.ENABLE_WEAPON_COSTUME_SYSTEM:
				self.visibleButtonList[3].SetToggleUpEvent(ui.__mem_func__(self.VisibleCostume), 4, 0)

			self.visibleButtonList[0].SetToggleDownEvent(ui.__mem_func__(self.VisibleCostume), 1, 1)
			self.visibleButtonList[1].SetToggleDownEvent(ui.__mem_func__(self.VisibleCostume), 2, 1)
			if app.ENABLE_ACCE_COSTUME_SYSTEM:
				self.visibleButtonList[2].SetToggleDownEvent(ui.__mem_func__(self.VisibleCostume), 3, 1)
			if app.ENABLE_WEAPON_COSTUME_SYSTEM:
				self.visibleButtonList[3].SetToggleDownEvent(ui.__mem_func__(self.VisibleCostume), 4, 1)

## def RefreshCostumeSlot(self): Altına Ekle :

	if app.ENABLE_HIDE_COSTUME_SYSTEM:
		def RefreshVisibleCostume(self):
			body = constInfo.HIDDEN_BODY_COSTUME
			hair = constInfo.HIDDEN_HAIR_COSTUME
			if app.ENABLE_ACCE_COSTUME_SYSTEM:
				acce = constInfo.HIDDEN_ACCE_COSTUME
			if app.ENABLE_WEAPON_COSTUME_SYSTEM:
				weapon = constInfo.HIDDEN_WEAPON_COSTUME

			if body == 1:
				self.visibleButtonList[0].SetToolTipText(localeInfo.SHOW_COSTUME)
				self.visibleButtonList[0].Down()
			else:
				self.visibleButtonList[0].SetToolTipText(localeInfo.HIDE_COSTUME)
				self.visibleButtonList[0].SetUp()

			if hair == 1:
				self.visibleButtonList[1].SetToolTipText(localeInfo.SHOW_COSTUME)
				self.visibleButtonList[1].Down()
			else:
				self.visibleButtonList[1].SetToolTipText(localeInfo.HIDE_COSTUME)
				self.visibleButtonList[1].SetUp()

			if app.ENABLE_ACCE_COSTUME_SYSTEM:
				if acce == 1:
					self.visibleButtonList[2].SetToolTipText(localeInfo.SHOW_COSTUME)
					self.visibleButtonList[2].Down()
				else:
					self.visibleButtonList[2].SetToolTipText(localeInfo.HIDE_COSTUME)
					self.visibleButtonList[2].SetUp()

			if app.ENABLE_WEAPON_COSTUME_SYSTEM:
				if weapon == 1:
					self.visibleButtonList[3].SetToolTipText(localeInfo.SHOW_COSTUME)
					self.visibleButtonList[3].Down()
				else:
					self.visibleButtonList[3].SetToolTipText(localeInfo.HIDE_COSTUME)
					self.visibleButtonList[3].SetUp()

		def VisibleCostume(self, part, hidden):
			net.SendChatPacket("/hide_costume %d %d" % (part, hidden))

## Arat :

def OnMoveWindow(self, x, y):

## Üstüne Ekle :

	if app.ENABLE_HIDE_COSTUME_SYSTEM:
		def RefreshVisibleCostume(self):
			if self.wndCostume:
				self.wndCostume.RefreshVisibleCostume()
			else:
				self.wndCostume = CostumeWindow(self)
				self.wndCostume.RefreshVisibleCostume()
