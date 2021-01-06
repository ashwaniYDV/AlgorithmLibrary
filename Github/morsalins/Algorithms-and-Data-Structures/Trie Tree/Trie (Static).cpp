#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

class Trie{
public :
	int next[26];
	bool endMark;

	void init(){
		memset( next, 0, sizeof next );
		endMark = false;
	}
} T[MAX+7];

void Insert (char *);
bool Found (char *);

int ptr;

int main()
{
	char s[20];
	int n;
	ptr = 1;
	T[0].init();

	printf("How many Strings? : ");
	scanf("%d", &n); getchar();

	for(int i=1; i<=n; i++){
		gets( s );
		Insert( s );
	}

	printf("Enter strings to find (Press ctrl+z to stop Query) : \n");
	
	while( gets(s) ){

		if( Found( s ) )
			printf("%s found.\n", s);
		else 
			printf("%s not found.\n", s);
	}

	return 0;
}

void Insert (char *s){

	int cur = 0;
	
	for(int i=0; s[i]; i++){
		int k = s[i] - 97; // 97 for small case. 65 for capital case. 48 for numeric.
		if( T[cur].next[k] == 0 ){
			T[cur].next[k] = ptr;
			T[ptr].init();
			ptr++;
		}
		cur = T[cur].next[k];
	}

	T[cur].endMark= true;

	return;
}

bool Found (char *s){

	int cur = 0;

	for(int i=0; s[i]; i++){
		int k = s[i] - 97; //97 for small case. 65 for capital case. 48 for numeric.
		if( T[cur].next[k] == 0 ) return false;
		cur = T[cur].next[k];
	}

	return T[cur].endMark;
}