wod_mutant_rancor_boss = Creature:new {
	customName = "Mutant Rancor Boss",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "townsperson",
	faction = "townsperson",
	level = 300,
	chanceHit = 65.00,
	damageMin = 1250,
	damageMax = 2800,
	baseXp = 2500000,
	baseHAM = 3400000,
	baseHAMmax = 3600000,
	armor = 3,
	resists = {95,95,95,95,95,95,95,95,95},
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
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/wod_mutant_rancor_boss.iff"},

	lootGroups = {
		{
			groups = {
				{group = "junk", chance = 5000000},
				{group = "armor_all", chance = 2500000},
				{group = "weapons_all", chance = 2500000}
			},
			lootChance = 10000000
		},
		{
			groups = {
				{group = "wearables_all", chance = 5000000},
				{group = "loot_kit_parts", chance = 2500000},
				{group = "tailor_components", chance = 2500000}
			},
			lootChance = 10000000
		},
		},
	weapons = {"creature_spit_heavy_flame"},
	conversationTemplate = "",
	attacks = {
		{"creatureareacombo","StateAccuracyBonus=100"},
		{"creatureareaknockdown","StateAccuracyBonus=100"},
		{"knockdownattack","KnockdownChance=100"},
		{"creatureareaknockdown","KnockdownChance=100"},
		{"dizzyattack","DizzyChance=100"},
		{"stunattack","StunChance=100"},
		{"mildpoison","PoisonChance=100"},
		{"intimidationattack","IntimidationChance=100"},
		{"mediumpoison","PoisonChance=100"},
		{"creatureareapoison","PoisonChance=100"},
		{"strongpoison","PoisonChance=100"},
		{"creatureareaattack","StateAccuracyBonus=100"}
	}
}
CreatureTemplates:addCreatureTemplate(wod_mutant_rancor_boss, "wod_mutant_rancor_boss")
