#pragma once
#include <vector>
#include "InputManager.h"
#include "Variables.h"
#include <iostream>


class KnowledgeBase {
public:
	KnowledgeBase();
	std::string getClass() const;
	void findClass();
	void findType();
	void printConclusion() const;
private:
	
	enum AttackClass {
		DDoS,
		Phishing,
		Malware,
	};

	enum DDoSType {
		SynFlood,
		HTTPFlood,
		Smurf,
		ZeroDay
	};
	enum PhishingType {
		MassMarket,
		Spear,
		BECCompromise
	};
	enum MalwareType {
		MacroVirus,
		FileInfector,
		PolymorphicVirus,
		StealthVirus,
		SystemInfector,
		Dropper,
		Worm,
		Ransomware,
		Adware
	};

	AttackClass attackClass;

	DDoSType ddosType;
	PhishingType phishingType;
	MalwareType malwareType;

	VariableList varList;
};