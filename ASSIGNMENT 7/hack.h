
typedef struct studentClub {
    int PRN ;
    char name[50];
    struct studentClub *next;
}studentClub;

typedef studentClub* hackathonClub;

void initList(hackathonClub*);
void addMembers(hackathonClub*,int,char[]);
int count(hackathonClub);
int deleteMembers(hackathonClub*,int);
void display(hackathonClub); 
