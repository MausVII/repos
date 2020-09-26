#include "KnowledgeBase.h"


KnowledgeBase::KnowledgeBase()
{
	//	First Questions In The Tree Decide Wheter The Attack is a DDoD, Phishing or Malware
	findClass();
	// Go Down The Decision Tree
	// DDoS
	if (attackClass == 0) {
		varList.setDDosVars();
		varList.printDDosVars();
	}
	// Pishing
	else if (attackClass == 1) {
		varList.setPhishingVars();
		varList.printPhishingVars();
	}
	// Malware
	else if (attackClass == 2) {
		varList.setMalwareVars();
		varList.printMalwareVars();
	}
	
	// Second Set of Questions Expands all branches down one of the three first nodes
	findType();
}

std::string KnowledgeBase::getClass() const
{
	switch (attackClass)
	{
	case KnowledgeBase::DDoS:
		return "DDoS";
		break;
	case KnowledgeBase::Phishing:
		return "Phishing";
		break;
	case KnowledgeBase::Malware:
		return "Malware";
		break;
	default:
		return 0;
		break;
	}
}

void KnowledgeBase::findClass()
{
	int traffic;
	std::string buffer = "";
	bool recentEmail;
	bool recentDownloadOpened;

	std::cout << "How much trafficking are you experiencing?	";
	std::cin >> traffic;
	recentEmail = question("Did you receive a recent Email asking for your Login Information?");
	recentDownloadOpened = question("Did you open an executable recently downloaded?");

	if (traffic >= 200) {
		attackClass = AttackClass::DDoS;
	}
	else if (recentEmail) {
		attackClass = AttackClass::Phishing;
	}
	else if (recentDownloadOpened) {
		attackClass = AttackClass::Malware;
	}
	else {
		std::cout << "\n\nCould not identify Attack Class, likely crash incoming.\n\n";
	}
}

void KnowledgeBase::findType()
{
	switch (attackClass)
	{
	case KnowledgeBase::DDoS:
		if (varList.getTCPHandShake()) {
			ddosType = DDoSType::SynFlood;
		}
		else if (!varList.getTCPHandShake()) {
			ddosType = DDoSType::HTTPFlood;
		}
		else if (!varList.getTCPHandShake() && varList.getResourcesRequested() >= varList.getMaxResources()) {
			ddosType = DDoSType::Smurf;
		}
		else if (!varList.getTCPHandShake() && varList.getEchoRequests() >= 5) {
			ddosType = DDoSType::ZeroDay;
		}
		break;
	case KnowledgeBase::Phishing:
		if (!varList.getPhishingVars(1)) {
			phishingType = PhishingType::MassMarket;
		}
		else if (varList.getPhishingVars(1)) {
			phishingType = PhishingType::Spear;
		}
		else if (varList.getPhishingVars(2)) {
			phishingType = PhishingType::BECCompromise;
		}
		break;
	case KnowledgeBase::Malware:
		if (varList.getMalwareVars(1)) {
			malwareType = MalwareType::MacroVirus;
		} else if (varList.getMalwareVars(2) || varList.getMalwareVars(3)) {
			malwareType = MalwareType::FileInfector;
		}
		else if (varList.getMalwareVars(4)) {
			malwareType = MalwareType::PolymorphicVirus;
		}
		else if (varList.getMalwareVars(5)) {
			malwareType = MalwareType::StealthVirus;
		}
		else if (varList.getMalwareVars(6)) {
			malwareType = MalwareType::SystemInfector;
		}
		else if (varList.getMalwareVars(7)) {
			malwareType = MalwareType::Worm;
		}
		else if (!varList.getMalwareVars(7) ) {
			malwareType = MalwareType::Dropper;
		}
		else if (!varList.getMalwareVars(8)) {
			malwareType = MalwareType::Ransomware;
		}
		else if (!varList.getMalwareVars(9)) {
			malwareType = MalwareType::Adware;
		}
		break;
	default:
		break;
	}

}

void KnowledgeBase::printConclusion() const
{
	switch (attackClass)
	{
	case KnowledgeBase::DDoS:
		switch (ddosType)
		{
		case KnowledgeBase::SynFlood:
			std::cout << "\nThe Attack is a SYN Flood DDoS.\n";
			break;
		case KnowledgeBase::HTTPFlood:
			std::cout << "\nThe Attack is a HTTP Flood DDoS.\n";
			break;
		case KnowledgeBase::Smurf:
			std::cout << "\nThe Attack is a Smurf Attack.\n";
			break;
		case KnowledgeBase::ZeroDay:
			std::cout << "\nThe Attack is a Zero Day Attack.\n";
			break;
		default:
			break;
		}
		break;
	case KnowledgeBase::Phishing:
		switch (phishingType)
		{
		case KnowledgeBase::MassMarket:
			std::cout << "\nThe Attack is Mass Market Phishing Attack.\n";
			break;
		case KnowledgeBase::Spear:
			std::cout << "\nThe Attack is Spear Phishing Attack.\n";
			break;
		case KnowledgeBase::BECCompromise:
			std::cout << "\nThe Attack is Business Email Compromise.\n";
			break;
		default:
			break;
		}
		break;
	case KnowledgeBase::Malware:
		switch (malwareType)
		{
		case KnowledgeBase::MacroVirus:
			std::cout << "\nThe Attack is a Macro Virus.\n";
			break;
		case KnowledgeBase::FileInfector:
			std::cout << "\nThe Attack is a File Infector.\n";
			break;
		case KnowledgeBase::PolymorphicVirus:
			std::cout << "\nThe Attack is a Polymorphic Virus.\n";
			break;
		case KnowledgeBase::StealthVirus:
			std::cout << "\nThe Attack is a Stealth Virus.\n";
			break;
		case KnowledgeBase::SystemInfector:
			std::cout << "\nThe Attack is a System Infector.\n";
			break;
		case KnowledgeBase::Dropper:
			std::cout << "\nThe Attack is a Dropper Virus.\n";
			break;
		case KnowledgeBase::Worm:
			std::cout << "\nThe Attack is a Worm Infection.\n";
			break;
		case KnowledgeBase::Ransomware:
			std::cout << "\nThe Attack is a Ransomware Virus.\n";
			break;
		case KnowledgeBase::Adware:
			std::cout << "\nThe Attack is an Adware Virus.\n";
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
}

