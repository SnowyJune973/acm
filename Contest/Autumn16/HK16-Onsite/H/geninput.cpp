#include <fstream>
#include <algorithm>
using namespace std;
int main(){
	ofstream fout;
	fout.open("input");
	fout << 20 << ' ' << 190 << endl;
	for(int i = 0; i < 20; i++){
		for(int j = i+1; j < 20; j++){
			fout << i << ' ' << j << endl;
		}
	}
	fout << 0 << ' ' << 19 << endl;
	fout.close();
	return 0;
}
