// PrjMySQL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <mysql.h>
#pragma comment(lib,"libmysql.lib")


int lession4() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	mysql_close(pDB);
	return 0;
}

void ShowResult(MYSQL_RES* result) {
	unsigned int nFilelds = mysql_num_fields(result);
	my_ulonglong nRows = mysql_num_rows(result);
	MYSQL_FIELD* fileds = mysql_fetch_field(result);
	MYSQL_ROW row;
	do{
		row = mysql_fetch_row(result);
		if (row != NULL) {
			for (unsigned j = 0; j < nFilelds; j++) {
				std::cout << "type:" << fileds[j].type << "  " << fileds[j].name << ":" << row[j] << std::endl;
			}
		}
	} while (row != NULL);
}

int lession7() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	if (pDB) {
		std::string sql = "CREATE USER 'Hello'@'localhost' IDENTIFIED BY '521109' ";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		MYSQL_RES* result = mysql_use_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		//给与权限
		sql = "GRANT ALL ON *.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		//撤销权限
		sql = "REVOKE INSERT ON *.* FROM 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
int lession8() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		MYSQL_RES* result = mysql_use_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "USE Hello";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		//撤销权限
		sql = "DROP DATABASE Hello";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
int lession9() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		MYSQL_RES* result = mysql_use_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "USE Hello";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello`(`编号` VARCHAR(16) PRIMARY KEY )ENGINE=InnoDB DEFAULT CHARSET=utf8";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		/*sql = "DROP TABLE `hello`";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}*/
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
//插入数据
int lession10() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		MYSQL_RES* result = mysql_use_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "USE Hello";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello`(`CARD_ID` VARCHAR(16) PRIMARY KEY )ENGINE=InnoDB DEFAULT CHARSET=utf8";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello`(`CARD_ID`) VALUES (\"9527\");";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
//删除操作
int lession11() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		MYSQL_RES* result = mysql_use_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "USE Hello";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello`(`CARD_ID` VARCHAR(16) PRIMARY KEY )ENGINE=InnoDB DEFAULT CHARSET=utf8";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello`(`CARD_ID`) VALUES (\"9527\");";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello`(`CARD_ID`) VALUES (\"9528\");";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "DELETE FROM `Hello` WHERE `CARD_ID`=\"9527\";";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
int lession12() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		MYSQL_RES* result = mysql_use_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "USE Hello";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello`(`CARD_ID` VARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello`(`CARD_ID`,`Age`) VALUES (\"9527\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello`(`CARD_ID`,`Age`) VALUES (\"9528\",99);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "UPDATE `Hello` SET Age =44 WHERE `CARD_ID`=\"9528\";";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "UPDATE `Hello` SET Age =18 WHERE `Age`>35 AND `Age`!=18;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "DELETE FROM `Hello` WHERE `CARD_ID`=\"9527\";";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
int make_query(MYSQL* pDB, const std::string& sql) {
	int ret = mysql_real_query(pDB, sql.c_str(), sql.size());
	if (ret != 0) {
		std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
	}
	MYSQL_RES* result = mysql_use_result(pDB);
	if (result != NULL) {
		ShowResult(result);
		mysql_free_result(result);
	}
	return 0;
}
int lession13() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		MYSQL_RES* result = mysql_use_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "USE Hello";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_use_result(mysql);
		if (result != NULL) {
			mysql_free_result(result);
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello`(`CARD_ID` VARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello`(`CARD_ID`,`Age`) VALUES (\"9527\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello`(`CARD_ID`,`Age`) VALUES (\"9528\",99);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "SELECT * FROM `hello`";
		make_query(pDB, sql);
		std::cout << "=============================" << std::endl;
		sql = "UPDATE `Hello` SET Age =44 WHERE `CARD_ID`=\"9528\";";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "UPDATE `Hello` SET Age =18 WHERE `Age`>35 AND `Age`!=18;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "SELECT * FROM `Teacher`";
		make_query(pDB, sql);
		std::cout << "=============================" << std::endl;
		sql = "DELETE FROM `Hello` WHERE `CARD_ID`=\"9527\";";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}

int lession14() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	int res = mysql_set_character_set(mysql, "utf8");
	if (res != 0) {
		std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		return -1;
	}
	res = mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	if (res != 0) {
		std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	/*int res = mysql_set_character_set(mysql, "utf8");
	if (res != 0) {
		std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
	}*/
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "USE Hello;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		//设置编码格式
		sql = "SET NAMES UTF8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Teacher` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9527\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9526\",34);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		//创建索引
		sql = "CREATE INDEX ";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "SELECT * FROM `hello`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9528\",99);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9529\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "SELECT * FROM `teacher`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "SELECT age FROM `Hello` UNION ALL SELECT age FROM `Teacher`";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		MYSQL_RES* result = mysql_store_result(pDB);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		std::cout << "=====================================" << std::endl;
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}

int lession15() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	/*int res = mysql_set_character_set(mysql, "utf8");
	if (res != 0) {
		std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
	}*/
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "USE Hello;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		//设置编码格式
		sql = "SET NAMES UTF8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Teacher` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9527\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9526\",34);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "SELECT * FROM `hello`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9528\",99);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9529\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "SELECT * FROM `teacher`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "SELECT age FROM `Hello` UNION ALL SELECT age FROM `Teacher`";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		MYSQL_RES* result = mysql_store_result(pDB);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		std::cout << "=====================================" << std::endl;
		sql = "CREATE INDEX myindex ON `Hello`(Age)";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
int lession16() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, 0);
	std::cout << pDB << std::endl;
	/*int res = mysql_set_character_set(mysql, "utf8");
	if (res != 0) {
		std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
	}*/
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "USE Hello;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		//设置编码格式
		sql = "SET NAMES UTF8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Teacher` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		ret = mysql_autocommit(mysql, false);
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9527\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9526\",34);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		ret = mysql_rollback(mysql);
		sql = "SELECT * FROM `hello`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9528\",99);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9529\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		ret = mysql_commit(mysql);
		ret = mysql_autocommit(mysql, true);
		sql = "SELECT * FROM `teacher`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "SELECT age FROM `Hello` UNION ALL SELECT age FROM `Teacher`";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		MYSQL_RES* result = mysql_store_result(pDB);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		std::cout << "=====================================" << std::endl;
		sql = "CREATE INDEX myindex ON `Hello`(Age)";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
int lession19() {
	MYSQL* mysql = new MYSQL();
	MYSQL* pDB = mysql_init(mysql);
	if (pDB == NULL) {
		std::cout << "mysql_init failed" << std::endl;
		return -1;
	}
	pDB = mysql_real_connect(pDB, "localhost", "root", "521109#Xsq", "mysql", 3306, NULL, CLIENT_LOCAL_FILES);
	std::cout << pDB << std::endl;
	/*int res = mysql_set_character_set(mysql, "utf8");
	if (res != 0) {
		std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
	}*/
	if (pDB) {
		std::string sql = "CREATE DATABASE Hello";
		int ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
		}
		//给与权限
		sql = "GRANT ALL ON Hello.* TO 'Hello'@'localhost'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "USE Hello;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		//设置编码格式
		sql = "SET NAMES UTF8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Hello` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "CREATE TABLE IF NOT EXISTS `Teacher` (`CARD_ID` NVARCHAR(16) PRIMARY KEY,";
		sql += "`Age` INT NOT NULL DEFAULT 18";
		sql += ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		ret = mysql_autocommit(mysql, false);
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9527\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Hello` (`CARD_ID`,`Age`) VALUES (\"9526\",34);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		ret = mysql_rollback(mysql);
		sql = "SELECT * FROM `hello`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9528\",99);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "INSERT INTO `Teacher`(`CARD_ID`,`Age`) VALUES (\"9529\",35);";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		ret = mysql_commit(mysql);
		ret = mysql_autocommit(mysql, true);
		sql = "SELECT * FROM `teacher`";
		make_query(pDB, sql);
		std::cout << "=====================================" << std::endl;
		sql = "SELECT age FROM `Hello` UNION ALL SELECT age FROM `Teacher`";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		MYSQL_RES* result = mysql_store_result(pDB);
		if (result != NULL) {
			ShowResult(result);
			mysql_free_result(result);
		}
		std::cout << "=====================================" << std::endl;
		sql = "CREATE INDEX myindex ON `Hello`(Age)";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql="SELECT * FROM `Teacher` INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/Teacher.txt'\n \
			FIELDS TERMINATED BY ',' \n \
			LINES TERMINATED BY '\r\n'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		/*sql = "DELETE FROM `Teacher`;";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		sql = "LOAD DATA LOCAL INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/Teacher.txt' INTO TABLE `Teacher`\n \
			FIELDS TERMINATED BY ',' \n \
			LINES TERMINATED BY '\r\n'";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			std::string cmd = "mysqlimport.exe -u root -521109#Xsq --local Teacher ";
			cmd += "\"C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/Teacher.txt\" ";
			cmd += "--fields-terminated-by = \",\"  --lines-terminated-by=\"\\r\\n\"";
			system(cmd.c_str());
			return -1;
		}*/
		sql = "SELECT COUNT(*) FROM `Hello`";
		ret = mysql_real_query(pDB, sql.c_str(), (unsigned long)sql.size());
		if (ret != 0) {
			std::cout << "mysql error:" << mysql_error(pDB) << std::endl;
			return -1;
		}
		result = mysql_store_result(mysql);
		if (result != NULL) {
			ShowResult(result);
			std::cout << "=======================" << std::endl;
			mysql_free_result(result);
		}
		mysql_close(pDB);
	}
	delete mysql;
	return 0;
}
int main(){
	setlocale(LC_ALL, "en_GB.UTF-8");
	lession19();
	return 0;
}
