#pragma once
#include <string>
#include <list>

namespace penguine
{
	class XMLNode
	{
	public:
		XMLNode();

		XMLNode* parent;
		std::vector<XMLNode*>* Children;

		std::string* name;
		std::map<std::string, std::string>* Attributes;
		std::map<std::string, std::string>* GetNodeAttributes(rapidxml::xml_node<>* node);
	};
}