#include<iostream>
#include<fstream>
#include<cstring>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
using namespace std;

#define maxlen 100

void openfile(string root,int layer);
int checkline(string name);

int main()
{	
	char rootname[] = "hw03";
	openfile(rootname,0);
	
	return 0;
}

void openfile(string root,int layer)
{
	DIR *dp;
	struct dirent *buf;
	struct stat st;
	char cwd[maxlen],pathname[maxlen],rootpath[maxlen];
	int is_file,is_dir,i;
	
	getcwd(cwd, maxlen);
	for(i=0;i<maxlen;i++)
		rootpath[i] = root[i];
	
	dp = opendir(rootpath);
	while((buf = readdir(dp))!=NULL)
	{
		if(strcmp(buf->d_name, ".") == 0 || strcmp(buf->d_name, "..") == 0)
      		continue;
		
		sprintf(pathname, "%s/%s", rootpath, buf->d_name);
		
		stat(pathname,&st);
		is_file = S_ISREG(st.st_mode);
		is_dir = S_ISDIR(st.st_mode);
		
		for(i=0;i<layer;i++)
			cout << "	";
		
		if(is_file)
		{
			cout << buf->d_name << " (" << checkline(pathname) << " lines)" << endl;
		}
		else if(is_dir)
		{
			cout <<  buf->d_name << ":" << endl;
			openfile(pathname,i+1);
		}
	}
		
    closedir(dp);
}

int checkline(string path)
{
	ifstream ifile;
	string temp;
	char filepath[maxlen];
	int lines=0;
	
	strcpy(filepath, path.c_str());
	ifile.open(filepath);
	
	while(getline(ifile,temp))
		lines++;
		
	ifile.close();
		
	return lines;
}
