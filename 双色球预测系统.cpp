#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define X 7
bool st(const char *p, int sun_16[],int len);
int main(void) {
	int n = 3;
	string filename;
	int sun_16[33]={ 0 };//һ���ǵó�ʼ��
	cout << "�����ļ�����";
	cin >> filename;
	if (st(filename.c_str(), sun_16,33)) {
		for (int i = 0; i < 33; i++) {
			if (sun_16[i] >= n) {
				cout << "��" << i + 1 << "������ִ�����" << sun_16[i] << "��\n";
			}
		}
	} else {//ͳ��ʧ��
		cout << "ͳ�Ƴ���\n";
	}
	system("pause");
	return 0;
}
bool st(const char *p, int sun_16[],int len) {
	int ret[X];
	ifstream file;
	int i = 0;
	if (!p) { cerr << "p��һ����ָ��" << endl; return false; }
	file.open(p);
	if(file.fail()){
		cout << "�������ļ�����" << endl;
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
				cout << "��ȡ�ļ�ʧ��!" << endl;
				break;
			}
		}
		if (i == 0) { break; }//��¼��������
		//�������󲻹�7��
		/*if (i < X) { 
			cout << "ֻ����:" << i << "������Ԥ�ڶ�ȡ��7��" << endl;
			file.close();
			return false;
		}*/
		for (i = 0; i < X; i++) {
			cout << "\t" << ret[i];
		}
		cout << endl;
		//�Զ�������ݽ���ͳ��
		for (i = 0; i < X-1; i++) {
			int index = *(ret + i) - 1;//1��->0��33����32
			if (index >= 0 && index < len){
				*(sun_16 + index)+=1;
			}
		}
	}
	file.close();
	return true;
}