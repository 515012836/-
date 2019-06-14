#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define X 7
bool st(const char *p, int sun_16[],int len);
int main(void) {
	int n = 3;
	string filename;
	int sun_16[33]={ 0 };//一定记得初始化
	cout << "输入文件名：";
	cin >> filename;
	if (st(filename.c_str(), sun_16,33)) {
		for (int i = 0; i < 33; i++) {
			if (sun_16[i] >= n) {
				cout << "第" << i + 1 << "号球出现次数：" << sun_16[i] << "次\n";
			}
		}
	} else {//统计失败
		cout << "统计出错！\n";
	}
	system("pause");
	return 0;
}
bool st(const char *p, int sun_16[],int len) {
	int ret[X];
	ifstream file;
	int i = 0;
	if (!p) { cerr << "p是一个空指针" << endl; return false; }
	file.open(p);
	if(file.fail()){
		cout << "打开输入文件错误！" << endl;
		return false;
	}
	while (1) {
		i = 0;
		for (i = 0; i < X; i++) {
			file >> ret[i];
			if (file.eof()) {
				break;
			}
			if (file.fail()) {
				cout << "读取文件失败!" << endl;
				break;
			}
		}
		if (i == 0) { break; }//记录正常结束
		//如果到最后不够7个
		/*if (i < X) { 
			cout << "只读到:" << i << "个数，预期读取是7个" << endl;
			file.close();
			return false;
		}*/
		for (i = 0; i < X; i++) {
			cout << "\t" << ret[i];
		}
		cout << endl;
		//对读入的数据进行统计
		for (i = 0; i < X-1; i++) {
			int index = *(ret + i) - 1;//1号->0；33号是32
			if (index >= 0 && index < len){
				*(sun_16 + index)+=1;
			}
		}
	}
	file.close();
	return true;
}