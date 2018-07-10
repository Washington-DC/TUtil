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

	Qiniu_Client client;

	Qiniu_Global_Init(-1);
	Qiniu_Client_InitMacAuth(&client, 1024, NULL);

	Qiniu_Mac mac;
	mac.accessKey = access_key;
	mac.secretKey = secret_key;

	char* bucket = "yszs";
	Qiniu_RS_PutPolicy putPolicy;
	Qiniu_Io_PutRet putRet;
	Qiniu_Io_PutExtra putExtra;

	Qiniu_Zero(putPolicy);
	Qiniu_Zero(putRet);
	Qiniu_Zero(putExtra);

	putPolicy.scope = bucket;
	char* uptoken = Qiniu_RS_PutPolicy_Token(&putPolicy, &mac);

	cout << "token : " << uptoken << endl;

	Qiniu_Use_Zone_Huadong(Qiniu_False);

	//Qiniu_Use_Zone_Huadong(Qiniu_True);


	char* key = "1.png";
	char* localfile = "E:\\CC\\result\\object\\1.png";

	Qiniu_Error err = Qiniu_Io_PutFile(&client, &putRet, uptoken, key, localfile, &putExtra);
	if (err.code != 200) {
		printf("upload file %s:%s error.\n", bucket, key);
		printf("error : id = %d , message = %s.\n", err.code, err.message);
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
	//Qiniu_Servend_Cleanup();
	Qiniu_Global_Cleanup();

	return 0;
}

