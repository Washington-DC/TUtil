// Qiniu_Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//#include "qiniu/include/base.h"
//#include "qiniu/include/io.h"
#include <iostream>
using namespace std;

#include "qiniu/io.h"
#include "qiniu/rs.h"
#include "qiniu/http.h"
#include "qiniu/conf.h"
#include "qiniu/base.h"
#include "qiniu/resumable_io.h"

#pragma comment(lib,"D:\\code2\\TUtil\\Qiniu_Test\\qiniu\\lib\\qiniu.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	const char* access_key = "Lbmup8txBkMQOskGvTXzFHror_s1K8WAZTL10uNW";
	const char* secret_key = "qVtgcrnMAYQg9LKG7OQTN8gpa2WixB_iFRU6kzaO";

	Qiniu_Global_Init(-1);
	Qiniu_Mac mac;
	mac.accessKey = "Lbmup8txBkMQOskGvTXzFHror_s1K8WAZTL10uNW";
	mac.secretKey = "qVtgcrnMAYQg9LKG7OQTN8gpa2WixB_iFRU6kzaO";
	char *bucket = "yszs";
	char *key = "123.jpg";
	char *localFile = "C:/Users/36240/Desktop/123.jpg";
	Qiniu_Io_PutRet putRet;
	Qiniu_Client client;
	Qiniu_RS_PutPolicy putPolicy;
	Qiniu_Io_PutExtra putExtra;
	Qiniu_Zero(putPolicy);
	Qiniu_Zero(putExtra);
	putPolicy.scope = bucket;
	char *uptoken = Qiniu_RS_PutPolicy_Token(&putPolicy, &mac);
	//设置机房域名
	//Qiniu_Use_Zone_Beimei(Qiniu_False);
	//Qiniu_Use_Zone_Huabei(Qiniu_True);
	Qiniu_Use_Zone_Huadong(Qiniu_False);
	//Qiniu_Use_Zone_Huanan(Qiniu_True);
	Qiniu_Client_InitMacAuth(&client, 1024, &mac);
	Qiniu_Error error = Qiniu_Io_PutFile(&client, &putRet, uptoken, key, localFile, &putExtra);
	if (error.code != 200) {
		printf("upload file %s:%s error.\n", bucket, key);
		//debug_log(&client, error);
	}
	else {
		/*200, 正确返回了, 你可以通过statRet变量查询一些关于这个文件的信息*/
		printf("upload file %s:%s success.\n\n", bucket, key);
		printf("key:\t%s\n", putRet.key);
		printf("hash:\t%s\n", putRet.hash);
	}
	Qiniu_Free(uptoken);
	Qiniu_Client_Cleanup(&client);

	return 0;
}

