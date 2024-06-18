/* usesharedlib.c */
void sharedfirst(void);
void sharedsecond(void);

int main(int argc,char *argv[])
{
	sharedfirst();
	sharedsecond();
	return 0;
}
