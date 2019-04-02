struct rec
{
	char * id;
	char firstname[15];
	char lastname[15];
	struct rec* next;
};

int AddItem(rec r);
int DeleteItem(char* delid);
void PrintList(int order);
