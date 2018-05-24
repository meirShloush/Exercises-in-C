
typedef struct S 
{
        char *name;
        int (*opera)(const char *, char *);
		int (*comp)(const char *, const char *);
}S;


enum Status
{
	Cannot_remove_file = -5,
	Cannot_copy_file,
	Cannot_rename_file,
	Cannot_close_file,
	Cannot_open_file
};

int Remove(const char *path, char *aaa);
int Append(const char *path, char *input);
int Count(const char *path, char *aaa);
int AppendToBeggin(const char *src_file, char *input);
int Exit(const char *bla1, char *bla2);
int CheckIfCommand(S *arr, const char *path, char *input);
int PrintError(int error_num);
int FirsrStrcmp(const char* str1, const char* str2);

