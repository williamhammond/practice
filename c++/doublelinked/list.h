struct rec
{
	char * id;
	char firstname[15];
	char lastname[15];
	struct rec* next;
	struct rec* prev;
	int answers[10];
};

int AddItem(rec r);
int DeleteItem(char* delid);
void PrintList(int order);
int ReadData(char* keyFile, char* answerFile);
int WriteData(char* keyFile, char* answerFile);
