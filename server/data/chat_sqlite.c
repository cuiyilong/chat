#include "chat_public.h"

sqlite3 *gpstUserdb; 


sqlite_search(sqlite3 *db)
{
    char *sql;
    char *zErrMsg = 0;  
    int nrow = 0, ncolumn = 0;  
    char **azResult; //��ά�����Ž��  
    HERE;
    //��ѯ����  
    /* 
    int sqlite3_get_table(sqlite3*, const char *sql,char***result , int *nrow , int *ncolumn ,char **errmsg ); 
    result�������������ʽ���������ѯ�����ݣ������Ǳ������������ݡ� 
    nrow ,ncolumn�ֱ�Ϊ��ѯ��䷵�صĽ������������������û�в鵽���ʱ����0 
    */  
    sql = "SELECT * FROM UserData ";  
    sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );  
    int i = 0 ;  
    printf( "row:%d column=%d \n" , nrow , ncolumn );  
    printf( "/nThe result of querying is :\n" );  
    HERE;
    for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )  
    printf( "azResult[%d] = %s\n", i , azResult[i] );  
    //�ͷŵ�  azResult ���ڴ�ռ�  
    sqlite3_free_table( azResult );  
    
}

sqlite_insert(sqlite3 *db)
{
    char *zErrMsg = 0;
    //����һ����,����ñ���ڣ��򲻴�������������ʾ��Ϣ���洢�� zErrMsg ��  
    char *sql = "CREATE TABLE UserData(    \
    ID INTEGER PRIMARY KEY,      \
    SensorID INTEGER,         \
    SiteNum INTEGER,        \
    Time VARCHAR(12),           \
    SensorParameter REAL     \
    );";  
    sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );  
    HERE;
    //��������  
    char* sql1 = "INSERT INTO \"UserData\" VALUES( NULL , 1 , 1 , '200605011206', 18.9 );" ;  
    sqlite3_exec( db , sql1 , 0 , 0 , &zErrMsg );  
    char* sql2 = "INSERT INTO \"UserData\" VALUES( NULL , 1 , 1 , '200605011306', 16.4 );" ;  
    sqlite3_exec( db , sql2 , 0 , 0 , &zErrMsg );  

    return 0;  
}



sqlite_delete()
{
    
}

sqlite_modify()
{
    
}




sqlite3 * sqlite_open(char *name)
{
	sqlite3 *db=NULL;  
	char *zErrMsg = 0;  
	int rc;  

	//��ָ�������ݿ��ļ�,��������ڽ�����һ��ͬ�������ݿ��ļ�  
	rc = sqlite3_open(name, &db);  
	if( rc )  
	{  
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));  
		sqlite3_close(db);  
		exit(1);  
		return NULL;  
	}  
	
	printf("You have opened a sqlite3 database named %s successfully!/nCongratulations! Have fun !  ^-^ \n",name);  
	
	
	return db;  
}


int sqlite_close(sqlite3 *db)
{
	sqlite3_close(db); //�ر����ݿ�  
}




int sqlite_init(void)
{
    
    gpstUserdb= sqlite_open("user.db");
    if(!gpstUserdb)
    {
        return FALSE;
    }

    sqlite_insert(gpstUserdb);
    sqlite_search(gpstUserdb);
    
    return 1;
}
