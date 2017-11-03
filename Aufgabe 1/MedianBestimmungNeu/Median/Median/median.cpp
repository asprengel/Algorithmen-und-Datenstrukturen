#include "median.h"



median::median()
{
}


median::~median()
{
}

void median::einlesen()
{
	double zahl;
	int i = 0;
	fstream eingabe;
    eingabe.open("sample2_no_dups.txt");
	if (!eingabe)
	{
		cout << "Datei konnte nicht geoeffnet werden!" << endl;
	}
	else {
		while (!eingabe.eof())
		{
			eingabe >> zahl;
			werte[i] = zahl;
			i++;
		}
	}
	laenge = i;
	cout << "Laenge: " << i;
}

int median::medianBerechnung()
{
	k=laenge/2;
	int n1 = 1;
	int n2 = laenge;
	int tind=0;
	while(true)
	{
		tind = spalteAuf(n1, n2,tind);
		tind = tind - n1 + 1;
		cout << k << endl;
		if (tind < k)
		{
			n1 = n1 + tind;
			k = k - tind;
		}
		else if (tind == k) return n1 - 1 + k;
		else n2 = n1 + tind - 2;
	}
	cout << k << endl;
	return k;
}


void median::vertausche(int tauschIndex1,int tauschIndex2)
{
	int temp; 
	int temp2;
	temp = werte[tauschIndex1];
	temp2 = werte[tauschIndex2];
	werte[tauschIndex1] = temp2;
	werte[tauschIndex2] = temp;
}

int median::spalteAuf(int n1, int n2, int tind)
{
	tind = (n1 + n2) / 2;
	vertausche(tind,n1);
	tind = n1;
	for (int i = n1 + 1; i < n2; i++)
	{
		if (werte[i] <= werte[tind]) 
		{
			vertausche(i, tind + 1);
			vertausche(tind, tind + 1);
			tind = tind + 1;
		}
	}
	return tind;
}