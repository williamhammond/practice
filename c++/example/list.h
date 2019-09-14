struct rec
{
	char * id;
	char firstname[15];
	char lastname[15];
	int answers[10];
	struct rec* next;
	struct rec* prev;
};
int ReadData(char* keyFile, char* answerFile);
int WriteData(char* keyFile, char* answerFile);
int AddItem(rec r);
int DeleteItem(char* delid);
void PrintList(int order);

