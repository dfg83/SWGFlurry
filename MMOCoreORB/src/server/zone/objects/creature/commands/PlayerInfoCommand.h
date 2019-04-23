/*
 * PlayerInfoCommand.h
 *
 *  Created on: 31/03/2012
 *      Author: victor
 */

#ifndef PLAYERINFOCOMMAND_H_
#define PLAYERINFOCOMMAND_H_

#include "engine/engine.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/managers/mission/MissionManager.h"
#include "server/zone/managers/player/BadgeList.h"

class PlayerInfoCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
		ManagedReference<CreatureObject*> targetObject;

		if (!arguments.isEmpty()) {
			ManagedReference<PlayerManager*> playerManager = creature->getZoneServer()->getPlayerManager();

			targetObject = playerManager->getPlayer(arguments.toString());
		} else {
			targetObject = creature->getZoneServer()->getObject(creature->getTargetID()).castTo<CreatureObject*>();
		}

		if (targetObject == NULL || !targetObject->isPlayerCreature()) {
			targetObject = creature;
		}

		Locker locker(targetObject, creature);

		PlayerObject* ghost = targetObject->getPlayerObject();

		ManagedReference<SuiMessageBox*> box = new SuiMessageBox(creature, 0);

		box->setPromptTitle("Player Info");

		Locker smodLocker(targetObject->getSkillModMutex());

		SkillModList* skillModList = targetObject->getSkillModList();

		StringBuffer promptText;
		promptText << "Name: " << targetObject->getCustomObjectName().toString()  << endl;
		promptText << "ObjectID: " << targetObject->getObjectID() << endl;

		if (ghost != NULL) {
			promptText << "Online Status: ";

			if(ghost->isOnline())
				promptText << "ONLINE" << endl;
			else {
				promptText << "OFFLINE. Last On: " << ghost->getLastLogout()->getFormattedTime() << endl;
			}
		}

		//promptText << endl << "Xp Rate:" << endl;
		//promptText << targetObject->getPersonalExpMultiplier() << endl;

		promptText << endl << "SkillMods:" << endl;
		promptText << skillModList->getPrintableSkillModList() << endl;

		smodLocker.release();

		promptText << "Skills:" << endl;
		SkillList* list = targetObject->getSkillList();

		int totalSkillPointsWasted = 0;

		for (int i = 0; i < list->size(); ++i) {
			Skill* skill = list->get(i);
			promptText << skill->getSkillName() << " point cost:" << skill->getSkillPointsRequired() << endl;

			totalSkillPointsWasted += skill->getSkillPointsRequired();
		}

		promptText << endl << "Level: " << targetObject->getLevel() << endl;

		if (ghost != NULL) {
			promptText << "totalSkillPointsWasted = " << totalSkillPointsWasted << " skillPoints var:" << ghost->getSkillPoints() << endl;

			promptText << endl << "Ability list:" << endl;

			AbilityList* abilityList = ghost->getAbilityList();

			for (int i = 0; i < abilityList->size(); ++i) {
				Ability* skill = abilityList->get(i);
				promptText << skill->getAbilityName() << endl;
			}

			if (creature->getPlayerObject()->getAdminLevel() >= 15) {
				Vector<byte>* holoProfessions = ghost->getHologrindProfessions();

				promptText << endl;
				promptText << "Hologrind professions:\n";

				BadgeList* badgeList = BadgeList::instance();
				if (badgeList != NULL) {
					for (int i = 0; i < holoProfessions->size(); ++i) {
						byte prof = holoProfessions->get(i);
						const Badge* badge = badgeList->get(prof);
						if (prof) {
							String stringKey = badge->getKey();
							promptText << "@skl_n:" + stringKey << " badgeid: " << String::valueOf(prof)<<  endl;
						} else {
							promptText << "unknown profession " << String::valueOf(prof) << endl;
						}
					}
				}

				promptText << endl << "Visibility = " << ghost->getVisibility() << endl;

				MissionManager* missionManager = creature->getZoneServer()->getMissionManager();
				Vector<uint64>* hunterList =  missionManager->getHuntersHuntingTarget(targetObject->getObjectID());

				if (hunterList != NULL) {
					for (int i = 0; i < hunterList->size(); i++) {
						promptText << "Hunter #" << i << ": " << hunterList->get(i) << endl;
					}
				}
			} else {
				promptText << "Not currently hunted" << endl;
			}

			//Jedi FRS Member Custom attributes
			//promptText << "\nPVP Rating: " << targetObject->getScreenPlayState("pvpRating") << endl;
			promptText << "\nPlayer has " << targetObject->getScreenPlayState("deathBounty") << " people who want him dead" << endl;
			int frsSkills = ghost->numSpecificSkills(targetObject, "force_rank_");
			String frsSkillName = "";
			if (frsSkills > 0) {
				switch (frsSkills) {
				case 1:
					frsSkillName = "novice";
					break;
				case 2:
					frsSkillName = "rank 01";
					break;
				case 3:
					frsSkillName = "rank 02";
					break;
				case 4:
					frsSkillName = "rank 03";
					break;
				case 5:
					frsSkillName = "rank 04";
					break;
				case 6:
					frsSkillName = "rank 05";
					break;
				case 7:
					frsSkillName = "rank 06";
					break;
				case 8:
					frsSkillName = "rank 07";
					break;
				case 9:
					frsSkillName = "rank 08";
					break;
				case 10:
					frsSkillName = "rank 09";
					break;
				case 11:
					frsSkillName = "rank 10";
					break;
				case 12:
					frsSkillName = "master";
					break;
				}
				if (ghost->getJediState() == 4) {
					//promptText << "\nFRS Rank: @skl_n:force_rank_light_" << frsSkillName << endl;
					promptText << "\nFRS Rank: Lightside " << frsSkillName << endl;
				} else if (ghost->getJediState() == 8) {
					//promptText << "\nFRS Rank: @skl_n:force_rank_dark_" << frsSkillName << endl;
					promptText << "\nFRS Rank: Darkside " << frsSkillName << endl;
				} else {
					promptText << "\nFRS Rank: Player is not currently in the FRS" << endl;
				}

				promptText << endl;
			}
		} else {
			promptText << "ERROR: PlayerObject NULL" << endl;
		}

		ManagedReference<SceneObject*> inventory = targetObject->getSlottedObject("inventory");
		ManagedReference<SceneObject*> bank = targetObject->getSlottedObject("bank");
		ManagedReference<SceneObject*> datapad = targetObject->getSlottedObject("datapad");

		promptText << "Inventory: " << (inventory == NULL ? String("NULL") : String::valueOf(inventory->getObjectID()));
		promptText << endl;

		promptText << "Bank: " << (bank == NULL ? String("NULL") : String::valueOf(bank->getObjectID()));
		promptText << endl;

		promptText << "Datapad: " << (datapad == NULL ? String("NULL") : String::valueOf(datapad->getObjectID()));
		promptText << endl;


		box->setPromptText(promptText.toString());

		creature->sendMessage(box->generateMessage());

		return 0;
	}
};


#endif /* PLAYERINFOCOMMAND_H_ */
