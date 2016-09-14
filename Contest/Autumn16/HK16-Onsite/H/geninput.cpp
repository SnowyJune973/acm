#include <fstream>
#include <algorithm>
using namespace std;
int main(){
	ofstream fout;
	fout.open("input");
	fout << 20 << ' ' << 20 << endl;
	for(int i = 0; i < 20; i++){
			fout << i << ' ' << (i+1)%20 << endl;
	}
	fout << 0 << ' ' << 2 << endl;
	fout.close();
	return 0;
}
