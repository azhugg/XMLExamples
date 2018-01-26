
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


#include "../tinyxml/AfTinyXml.h"

struct Note
{
	int id;
	char when[32];
	char who[32];
	char what[128];
};

vector<Note> notes;

int main()
{
	// ����xml
	TiXmlDocument xml_doc;
	if(!xml_doc.LoadFile("example02b.xml"))
	{
		return -1;
	}

	// ���ڵ�
	TiXmlElement* xml_root = xml_doc.RootElement();
	if (NULL == xml_root)
	{
		return -1;
	}

	// ��ȡԪ�ص��ı�������

	TiXmlElement* xml_NoteList = xml_root->FirstChildElement("NoteList");
	if(xml_NoteList)
	{
		TiXmlElement* xml_Note = xml_NoteList->FirstChildElement("Note");
		while(xml_Note)
		{
			// ȡ����Ԫ�ص��ı�
			int id = AfTinyXml::childAsInt(xml_Note, "id");
			string when = AfTinyXml::childAsText(xml_Note, "when");
			string who = AfTinyXml::childAsText(xml_Note, "who");			
			string what = AfTinyXml::childAsText(xml_Note, "what");
			
			// ���浽�б�
			Note r;
			r.id = id;
			strcpy(r.when, when.c_str());
			strcpy(r.who, who.c_str());
			strcpy(r.what, what.c_str());
			notes.push_back(r);

			// ��һ���ֵ�Ԫ��
			xml_Note = xml_Note->NextSiblingElement("Note");
		}
	}


	return 0;
}

