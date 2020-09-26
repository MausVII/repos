#include "Variables.h"

void VariableList::setDDosVars() 
{
	std::cout << "\nThe Class of the Network Attack has been detected as DDoS.\n"
		<< "Answer the following questions to assert the type of DDoS attack.\n";
	// Traffic
	std::cout << "How much traffic are you experiencing?	";
	std::cin >> ddosVars.traffic;
	// TCPHandShake
	ddosVars.TCPHandShake = question("Was the TCP Hand shake finished?");
	// resourcesRequested
	std::cout << "How much Resources are being requested?	";
	std::cin >> ddosVars.resourcesRequested;
	// echoRequests
	std::cout << "How many Echo Requests did the host respond to?	";
	std::cin >> ddosVars.echoRequests;
}

void VariableList::setPhishingVars()
{
	std::cout << "\nThe Class of the Network Attack has been detected as Phishing.\n"
		<< "Answer the following questions to assert the type of Phishing attack.\n";
	// recentEmail
	phishingVars.recentEmail = question("Did you recently receive an email asking for your login credentials?");
	// targetedEmail
	phishingVars.targetedEmail = question("Was the email directed at you specifically by name or position?");
	// emailSourceRecognized
	phishingVars.emailSourceRecognized = question("Was the email source one of your superiors working in the company?");
}

void VariableList::setMalwareVars()
{
	std::cout << "\nThe Class of the Network Attack has been detected as Malware.\n"
		<< "Answer the following questions to assert the type of Malware attack.\n";
	// recentDownloadOpened
	malwareVars.recentDownloadOpened = question("Did you recently open a file downloaded from the Internet?");
	// onlyMacroAffected
	malwareVars.onlyMacroAffected = question("Are only macro languages affected?");
	// replicated
	malwareVars.replicated = question("Has it replicated itself?");
	// attachedToEXE
	malwareVars.attachedToEXE = question("Was the downloaded file an executable?");
	// selfEncrypting
	malwareVars.selfEncrypting = question("Has the virus encrypted by itself?");
	// compromiseDetection
	malwareVars.compromiseDetection = question("Have you noticed any compromise to your malware detection software?");
	// loadedAtBoot
	malwareVars.loadedAtBoot = question("Did the virus activate during booting operations?");
	// isSelfContained
	malwareVars.isSelfContained = question("Is the virus self contained?");
	// askingRansom
	malwareVars.askingRansom = question("Is the virus asking for money to provide back functionality?");
	// adPopups
	malwareVars.adPopups = question("Do you frequently find invasive advertisement popups?");
}

void VariableList::printDDosVars() const
{
	std::cout << "\nVariable List:	";
	std::cout << "TRAFFIC\n";
	std::cout << "		RESORCES REQUESTED\n";
	std::cout << "		ECHO REQUESTS\n";
}

void VariableList::printPhishingVars() const
{
	std::cout << "\nVariable List:	";
	std::cout << "RECENT EMAIL\n";
	std::cout << "		TARGET EDEMAIL\n";
	std::cout << "		EMAIL SOURCE\n";
}

void VariableList::printMalwareVars() const
{
	std::cout << "\nVariable List:	";
	std::cout << "RECENT DOWNLOAD\n";
	std::cout << "		MACRO AFFECTED\n";
	std::cout << "		REPLICATED\n";
	std::cout << "		ATTACHED TO EXE\n";
	std::cout << "		SELF ENCRYPTING\n";
	std::cout << "		DETECTION COMPROMISE\n";
	std::cout << "		LOADED AT BOOT\n";
	std::cout << "		SELF CONTAINED\n";
	std::cout << "		AD POPUPS\n";
}

int VariableList::getTraffic() const
{
	return ddosVars.traffic;
}

bool VariableList::getTCPHandShake() const
{
	return ddosVars.TCPHandShake;
}

int VariableList::getResourcesRequested() const
{
	return ddosVars.resourcesRequested;
}

int VariableList::getMaxResources() const
{
	return ddosVars.maxResources;
}

int VariableList::getEchoRequests() const
{
	return ddosVars.echoRequests;
}

bool VariableList::getPhishingVars(int index) const
{
	switch (index)
	{
	case 0:
		return phishingVars.recentEmail;
		break;
	case 1:
		return phishingVars.targetedEmail;
		break;
	case 2:
		return phishingVars.emailSourceRecognized;
		break;
	default:
		return false;
		break;
	}
}

bool VariableList::getMalwareVars(int index) const
{
	switch (index)
	{
	case 0:
		return malwareVars.recentDownloadOpened;
		break;
	case 1:
		return malwareVars.onlyMacroAffected;
		break;
	case 2:
		return malwareVars.replicated;
		break;
	case 3:
		return malwareVars.attachedToEXE;
		break;
	case 4:
		return malwareVars.selfEncrypting;
		break;
	case 5:
		return malwareVars.compromiseDetection;
		break;
	case 6:
		return malwareVars.loadedAtBoot;
		break;
	case 7:
		return malwareVars.isSelfContained;
		break;
	case 8:
		return malwareVars.askingRansom;
		break;
	case 9:
		return malwareVars.adPopups;
		break;
	default:
		break;
	}
}
