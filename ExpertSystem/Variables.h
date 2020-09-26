#pragma once
#include <string>
#include <iostream>
#include "InputManager.h"

class VariableList {
public:
	VariableList() = default;
	void setDDosVars();
	void setPhishingVars();
	void setMalwareVars();
	void printDDosVars() const;
	void printPhishingVars() const;
	void printMalwareVars() const;
	
	int getTraffic() const;
	bool getTCPHandShake() const;
	int getResourcesRequested() const;
	int getMaxResources() const;
	int getEchoRequests() const;

	bool getPhishingVars(int index) const;

	bool getMalwareVars(int index) const;
private:
	struct DDosVars {
		int traffic;
		bool TCPHandShake;
		int resourcesRequested;
		const int maxResources = 200;		
		// Echo Requests flag set to 5 in KnowledgeBase.cpp line 83
		int echoRequests;
	};

	struct PhishingVars {
		bool recentEmail;
		bool targetedEmail;
		bool emailSourceRecognized;
		
	};

	struct MalwareVars {
		bool recentDownloadOpened;
		bool onlyMacroAffected;
		bool replicated;
		bool attachedToEXE;
		bool selfEncrypting;
		bool compromiseDetection;
		bool loadedAtBoot;
		bool isSelfContained;
		bool askingRansom;
		bool adPopups;
	};

	DDosVars ddosVars;
	PhishingVars phishingVars;
	MalwareVars malwareVars;
};