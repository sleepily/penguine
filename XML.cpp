#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <list>
#include <algorithm>
#include "XML.h"
#include "rapidxml.hpp"

namespace penguine
{
	rapidxml::xml_node<>* XML::FindChildNode(rapidxml::xml_node<>* parentNode, const char* nameToFind)
	{
		for (rapidxml::xml_node<>* childNode = parentNode->first_node(); childNode != NULL; childNode = childNode->next_sibling())
			if (strcmp(childNode->name(), nameToFind) == 0) return childNode;

		return NULL;
	}

	rapidxml::xml_attribute<>* XML::FindAttribute(rapidxml::xml_node<>* node, const char* attributeName)
	{
		for (rapidxml::xml_attribute<>* attribute = node->first_attribute(); attribute != NULL; attribute = attribute->next_attribute())
			if (strcmp(attribute->name(), attributeName) == 0) return attribute;

		return NULL;
	}

	XML::XML(std::string path)
	{
		m_Node = new rapidxml::xml_node<>(rapidxml::node_type::node_document);
		m_RootNode = new rapidxml::xml_node<>(rapidxml::node_type::node_document);

		ReadFile(path);
		Parse();
	}

	void XML::ReadFile(std::string path)
	{
		std::ifstream inputFile(path, std::ios::binary);
		std::streampos streampos_begin = inputFile.tellg();
		inputFile.seekg(0, std::ios::end);
		std::streampos streampos_end = inputFile.tellg();
		size_t fileSize = streampos_end - streampos_begin;
		inputFile.seekg(0, std::ios::beg);

		m_FileSize = fileSize;
		m_FileName = path;

		m_XMLContents = new char[fileSize + 1];
		memset(m_XMLContents, 0, fileSize + 1);
		inputFile.read(m_XMLContents, fileSize);

		// std::cout << m_XMLContents << std::endl;

		inputFile.close();
	}
	
	bool XML::Parse()
	{
		m_XMLDocument = new rapidxml::xml_document<>();
		m_XMLDocument->parse<0>(m_XMLContents);

		m_RootNode = m_XMLDocument->first_node();
		m_Node = m_RootNode;

		return true;
	}

	size_t XML::GetFileSize()
	{
		if (m_FileSize > 0)
			return m_FileSize;

		return 0;
	}

	rapidxml::xml_node<>* XML::GetRootNode()
	{
		return m_RootNode;
	}
	
	std::string XML::ToString()
	{
		std::string output;

		output += ToStringRecursive(m_Node, 0);
			
		return output;
	}

	std::string XML::ToStringRecursive(rapidxml::xml_node<>* node, unsigned int level)
	{
		std::string output;

		std::string tab = "";

		for (unsigned int i = 0; i < level; i++)
			tab += "  ";

		std::string nodeName = std::string(node->name());
		std::string nodeValue = std::string(node->value());
		std::string nodeAttributes = "";

		const rapidxml::node_type nodeType = node->type();

		switch (nodeType)
		{
		case rapidxml::node_element:
			output += tab + "Name: " + nodeName + "\n";

			for (rapidxml::xml_attribute<>* attribute = node->first_attribute(); attribute; attribute = attribute->next_attribute())
				nodeAttributes += std::string(attribute->name()) + " = \"" + std::string(attribute->value()) + "\", ";

			for (rapidxml::xml_node<>* childNode = node->first_node(); childNode; childNode = childNode->next_sibling())
				output += ToStringRecursive(childNode, level + 1) + "\n";

			break;
		case rapidxml::node_data:
			output += tab + nodeValue + "\n";
			break;
		default:
			break;
		}

		return output;
	}
}
