#include <bits/stdc++.h>
using namespace std;
#define rd Rand
#define int long long

using ll = long long;
const string SonPath = "test/output/";
const string InputPath = "test/input/";
const string TrauPath = "test/output_trau/";
const string NAME = "restaurant";
const string IOfile = "t";
const int NTEST = 1;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MinLine = 50, MaxLine = 100;
const int MINLEN = 20, MAXLEN = 20;
const int MINSIZE = 3, MAXSIZE = 10;
const string command[6] = {"LAPSE", "HAND", "KOKUSEN", "LIMITLESS", "KEITEIKEN", "CLEAVE"};
char alphabet[52] = {'a'};

int maxsize;

ll Rand(ll l, ll h) {
	return uniform_int_distribution<ll>(l, h)(rng);
}

void Lapse(ofstream &inp) {
	int strLen = rd(MINLEN, MAXLEN);
	inp << "LAPSE ";
	for (int j = 0; j < strLen; j++) {
		int idx = rd(0, 51);
		int duplicate = rd (1, 3);
		while (duplicate--)
			inp << alphabet[idx];
	}
	inp << "\nHAND\n";
}

void gensub1(ofstream &inp) { // LAPSE AND HAND
	int Nline = rd(MinLine, MaxLine);
	for (int i = 0; i < Nline; i++) {
		Lapse(inp);
	}
}

void gensub2(ofstream &inp) {	// LAPSE, HAND, LIMITLESS, CLEAVE
	int Nline = rd(MinLine, MaxLine);
	for (int i = 0; i < Nline; i++) {
		Lapse(inp);
		if (i & 1)	inp << "LIMITLESS ";
		else 		inp << "CLEAVE ";
		inp << rd(MINSIZE, maxsize) << '\n';
	}
}

void gensub3(ofstream &inp) {
	int Nline = rd(MinLine, MaxLine);
	for (int i = 0; i < Nline; i++) {	// Include KOKUSEN and KEIKEITEN
		Lapse(inp);
		int nn = rd (1, maxsize);
		int modulo = rd (1, maxsize);
		if (i % modulo == 0) {
			if (i & 1) inp << "KOKUSEN\nLIMITLESS ";
			else inp << "KEITEIKEN " << nn << "\nCLEAVE ";
			inp << rd(MINSIZE, maxsize) << '\n';
		}
	}
}

void gensub4(ofstream &inp) {	// ALL subtask
	int Nline = rd(MinLine, MaxLine);
	Nline += 10;
	for (int i = 0; i < Nline; i++) {
		int nn = rd (MINSIZE, maxsize);
		while (nn--)
			Lapse(inp);
		int avg = rd(2, 5);
		inp << command[avg];
		if (avg >= 3 && avg < 6) {
			inp << " " <<  rd(MINSIZE, maxsize) << '\n';
		}
		else inp << '\n';
	}
}

void gen(ofstream &inp) {
	gensub1(inp);
}

int32_t main() {
	for (int i = 1; i < 52; i++) {
		if (i == 26)	alphabet[i] = 'A';
		else alphabet[i] = alphabet[i - 1] + 1;
	}
	freopen((IOfile + ".log").c_str(), "w", stdout);
	srand(time(NULL));
	for (int iTest = 1; iTest <= NTEST; iTest++) {
		string ii = to_string(iTest);
		//ofstream inp((InputPath + IOfile + ii + ".inp").c_str());
		ofstream inp((IOfile + ".inp").c_str());
// gen code ( inp << . . . << . . . )
		maxsize = rd (MINSIZE, MAXSIZE);
		inp << "MAXSIZE " << maxsize << '\n';
		gen(inp);
		/*if (iTest <= 50) gensub1(inp);
		else if (iTest >= 51 && iTest <= 70)	gensub2(inp);
		else if (iTest >= 71 && iTest <= 90)	gensub3(inp);
		else if (iTest >= 81 && iTest <= 100)	gensub4(inp);*/

		inp.close();
		system((NAME + ".exe").c_str()); // (”./” + NAME)
		system((NAME + "_trau.exe").c_str()); // (”./” + NAME + ”trau”
		if (system(("fc " + IOfile + ".out " + IOfile + ".ans").c_str())) { // fc −> d i f f
			cout << "Test " << iTest << ": WRONG!\n";
		}
		else cout << "Test " << iTest << ": CORRECT!\n";
	}
	return 0;
}