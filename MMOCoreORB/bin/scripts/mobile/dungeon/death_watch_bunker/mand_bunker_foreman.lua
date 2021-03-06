mand_bunker_foreman = Creature:new {
	objectName = "",
	customName = "Japer Witter (a mine Foreman)",
	socialGroup = "death_watch",
	faction = "",
	level = 100,
	chanceHit = 1,
	damageMin = 645,
	damageMax = 1000,
	baseXp = 9336,
	baseHAM = 24000,
	baseHAMmax = 30000,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = NONE,
	optionsBitmask = INVULNERABLE + CONVERSABLE,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_mand_bunker_foreman.iff"},
	lootGroups = {
		{
			groups = {
				{group = "wearables_uncommon", chance = 10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "wearables_common", chance = 10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "jetpack_base", chance = 10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "bounty_hunter_armor", chance = 10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "carbines", chance = 10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "pistols", chance = 10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "junk", chance = 10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "rifles", chance = 10000000}
			},
			lootChance = 5000000
		}
	},
	weapons = {},
	conversationTemplate = "deathWatchForemanConvoTemplate",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(mand_bunker_foreman, "mand_bunker_foreman")
