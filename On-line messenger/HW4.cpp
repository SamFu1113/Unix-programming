#include <utmp.h>
#include <stdio.h>
#include <sys/types.h> //lseek.stat
#include <sys/stat.h>//stat
#include <sys/uio.h>
#include <unistd.h> //close.read.write.lseek.stat
#include <fcntl.h> //open
#include <pwd.h>

struct userlist{
	int order;
	char user[32];
	char tty[8];
	userlist(){order=0;}
	void setuser(char *a){ for(int i=0;i<32;i++)user[i]=a[i]; }
	void settty(char *a){ for(int i=0;i<10;i++)tty[i]=a[i]; }
};
	
int main(){
	int choice;
	int list_length=0;
	char tmpdir[12],say[300];	
	FILE *fp;
	userlist *list=new userlist[100];
	struct utmp user_rec;
	struct passwd *self;
	self=getpwuid(getuid());	
	setuid(0);
	fp = fopen ("/var/run/utmp", "r");
	for(int i=0;fread(&user_rec, sizeof(struct utmp), 1, fp)>0;i++){
		if(i>1){		
			list[i-1].order = i-1;
			list[i-1].setuser( user_rec.ut_user );
			list[i-1].settty( user_rec.ut_line );
			list_length++;
		}	
	}
	for(int i=1;i<=list_length;i++)
		printf("%02d %-10s %-5s\n",list[i].order,list[i].user,list[i].tty);
	printf("\nWhom to send message?\n");
	scanf("%d",&choice);
	sprintf(tmpdir,"%s/%s",(char *)"/dev",list[choice].tty);
	fclose(fp);
	fp=fopen(tmpdir,"w");
	printf("What do you want to say?\n");
	scanf(" %[^\n]",say);	
	fprintf(fp,"%s :%s\n",self->pw_name,say);
	fclose(fp);
	return 0;
}
