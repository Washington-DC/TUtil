// Qiniu_Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//#include "qiniu/include/base.h"
//#include "qiniu/include/io.h"

#include "qiniu/io.h"
#include "qiniu/rs.h"

#pragma comment(lib,"qiniu.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	Qiniu_Client client;
	QINIU_ACCESS_KEY = "Lbmup8txBkMQOskGvTXzFHror_s1K8WAZTL10uNW";
	QINIU_SECRET_KEY = "qVtgcrnMAYQg9LKG7OQTN8gpa2WixB_iFRU6kzaO";

	Qiniu_Servend_Init(-1);
	Qiniu_Client_InitMacAuth(&client, 1024, NULL);

	Qiniu_Mac mac;
	mac.accessKey = QINIU_ACCESS_KEY;
	mac.secretKey = QINIU_SECRET_KEY;

	char* bucket = "yszs";
	Qiniu_RS_PutPolicy putPolicy;
	Qiniu_Zero(putPolicy);
	putPolicy.scope = bucket;
	char* uptoken = Qiniu_RS_PutPolicy_Token(&putPolicy, &mac);


	Qiniu_Free(uptoken);

	Qiniu_Client_Cleanup(&client);
	Qiniu_Servend_Cleanup();

	return 0;
}

