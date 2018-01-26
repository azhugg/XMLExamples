
#include <stdio.h>
#include <vector>
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

int save()
{
	TiXmlDocument xml_doc;
	xml_doc.LinkEndChild(new TiXmlDeclaration( "1.0", "GBK", "" ));

	TiXmlElement * xml_root = new TiXmlElement("root");
	xml_doc.LinkEndChild(xml_root);

	TiXmlElement* xml_NoteList = new TiXmlElement("NoteList");
	xml_root->LinkEndChild(xml_NoteList);

	// ���hostԪ��
	for(int i=0; i<notes.size(); i++)
	{
		Note& r = notes[i];

		TiXmlElement* xml_Note = new TiXmlElement("Note");
		xml_NoteList->LinkEndChild(xml_Note);

		AfTinyXml::addChild(xml_Note, "id", r.id);
		AfTinyXml::addChild(xml_Note, "when", r.when);
		AfTinyXml::addChild(xml_Note, "who", r.who);
		AfTinyXml::addChild(xml_Note, "what", r.what);
	}

	//��һ�ַ������ǽ����ݱ��浽����
	xml_doc.SaveFile("example02b.xml");

	////�ڶ��ַ������ǽ����ݱ����string
	//string txt;
	//txt << xml_doc;
	//cout << txt << endl;

	return 0;
}

void addNote(int id, const char* when, const char* who, const char* what)
{
	Note n;
	n.id = id;
	strcpy(n.when, when);
	strcpy(n.who, who);
	strcpy(n.what, what);
	notes.push_back(n);
}

int main()
{
	addNote(1, "2018-1-26 1:00", "Qi", "˯��");
	addNote(2, "2019-1-21 2:00", "Ge", "�򶹶�");
	addNote(3, "2020-2-20 5:00", "Yong", "����");

	save();
	return 0;
}


