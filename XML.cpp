#include <iostream>
#include <string>
#include <stdio.h>
#include "XML.h"
#include "rapidxml.hpp"

namespace penguine
{
	void XML::ReadFile(std::string path)
	{
		std::ifstream inputFile(path, std::ios::binary);
		std::streampos streampos_begin = inputFile.tellg();
		inputFile.seekg(0, std::ios::end);
		std::streampos streampos_end = inputFile.tellg();
		size_t fileSize = streampos_end - streampos_begin;
		inputFile.seekg(0, std::ios::beg);

		m_FileSize = fileSize;

		m_XMLContents = new char[fileSize + 1];
		memset(m_XMLContents, 0, fileSize + 1);
		inputFile.read(m_XMLContents, fileSize);
		std::cout << m_XMLContents << std::endl;
		inputFile.close();
	}
	
	bool XML::Parse()
	{
		m_XMLDocument.parse<0>(m_XMLContents);

		m_RootNode = m_XMLDocument.first_node();
		m_Node = m_RootNode;

		return true;
	}

	XML::XML(std::string path)
	{
		ReadFile(path);
		Parse();
	}

	int XML::GetFileSize()
	{
		if (m_FileSize >= 0)
			return m_FileSize;

		return 0;
	}
	
	std::string XML::ToString()
	{
#ifdef PENGUINE_DEBUG
#endif // PENGUINE_DEBUG

		


		return std::string();
	}
}
