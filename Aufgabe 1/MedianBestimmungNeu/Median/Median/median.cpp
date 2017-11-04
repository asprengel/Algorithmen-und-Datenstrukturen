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
    //eingabe.open("sample2_no_dups.txt");
	eingabe.open("test.txt");
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
	cout << "Laenge: " << i << endl;
}

int median::medianBerechnung()
{
	k = laenge/2;
	int n1 = 1;
	int n2 = laenge;
	int tind = (n1 + n2) / 2;
	while(true)
	{
		tind = spalteAuf(n1, n2,tind);
		tind = tind - n1 + 1;
		//cout << k << endl;
		if (tind < k)
		{
			n1 = n1 + tind;
			k = k - tind;
		}
		else if (tind == k) return (n1 - 1 + k);
		else n2 = n1 + tind - 2;
	}
	//cout << k << endl;
	return k;
}


void median::vertausche(int tauschWert1,int tauschWert2)
{
	int temp; 
	temp = tauschWert1;
	tauschWert1 = tauschWert2;
	tauschWert2 = temp;

	//temp = werte[tauschIndex1];
	//werte[tauschIndex1] = werte[tauschIndex2];
	//werte[tauschIndex2] = temp;
}

int median::spalteAuf(int n1, int n2, int tind)
{
	vertausche(werte[tind], werte[n1]);
	tind = n1;
	for (int i = n1 + 1; i < n2; i++)
	{
		if (werte[i] <= werte[tind]) 
		{
			vertausche(werte[i], werte[tind + 1]);
			vertausche(werte[tind], werte[tind + 1]);
			tind = tind + 1;
		}
	}
	return tind;
}