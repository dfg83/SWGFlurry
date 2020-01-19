--Automatically generated by SWGEmu Spawn Tool v0.12 loot editor. 

nge90 = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/ranged/rifle/ep3/rifle_dc15.iff",
	craftingValues = {
		{"mindamage",7,13,0},
		{"maxdamage",130,240,0},
		{"attackspeed",6,4.1,1},
		{"woundchance",8,16,0},
		{"roundsused",30,65,0},
		{"hitpoints",750,1500,0},
		{"zerorangemod",-45,-45,0},
		{"maxrangemod",-40,-40,0},
		{"midrange",50,50,0},
		{"midrangemod",0,10,0},
		{"attackhealthcost",33,18,0},
		{"attackactioncost",52,28,0},
		{"attackmindcost",26,14,0},
	},
	customizationStringNames = {},
	customizationValues = {},
	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 750,
	junkDealerTypeNeeded = JUNKARMS,
	junkMinValue = 30,
	junkMaxValue = 55

}
addLootItemTemplate("nge90", nge90)
