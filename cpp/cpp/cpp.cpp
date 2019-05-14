#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <fstream>

using namespace std;
//usuwamy plik xml przed nastepnym uzyciem programu
int main()
{
	int R = 10;
	int r = 2, counter = 0;
	int k = 0;
	int hz = 0;
	int N = 10, i = 0;
	int tab[10][10];		//stala wartosc N
	int y, x, count = 0;
	float d, dd;
	srand(time(NULL));
	fstream file;
	file.open("C:\\Users\\dawidsokol\\Desktop\\gxl\\gxlfile.xml", ios::app); //app::ios
	file << "<?xml version='1.0' encoding='utf-8'?>" << endl;
	file << "<node>" << endl;
	while (i < N)
	{
		x = (((float)rand() / RAND_MAX) * (R * 2)) + ((R) * (-1));
		y = (((float)rand() / RAND_MAX) * (R * 2)) + ((R) * (-1));
		d = sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0));
		if (d <= R)
		{
			i++;
			tab[k][0] = x;
			tab[k][1] = y;
			tab[k][2] = hz;
			tab[k][3] = counter;
			counter++;
			//cout<<"tab[0] "<<tab[k][0]<<"     tab[1] "<<tab[k][1]<<"      tab[2] "<<tab[k][2]<<endl;
			k++;
		}
	}
	k = 0;
	//for(int s=0;s<(N*N);s++)
	while (k < N)
	{
		int tmp = 0;
		for (int i = 0; i < N; i++)
		{
			if (k <= 0)
			{
				tmp++;
				dd = sqrt((tab[k][0] - tab[tmp][0]) * (tab[k][0] - tab[tmp][0]) + (tab[k][1] - tab[tmp][1]) * (tab[k][1] - tab[tmp][1]));
				if (dd <= (2 * r) && tab[k][2] == tab[tmp][2])
				{
					if (tab[k][3] == tab[tmp][3])
					{
					}
					else
					{
						file << "<edge>" << endl;
						file << "<counter>" << count << "</counter>" << endl;
						file << "<id>" << tab[k][3] << "</id>" << endl;
						file << "<x>" << tab[k][0] << "</x>" << endl;
						file << "<y>" << tab[k][1] << "</y>" << endl;
						file << "<hz>" << tab[k][2] << "</hz>" << endl;
						file << "<connid>" << tab[tmp][3] << "</connid>" << endl;
						file << "<connx>" << tab[tmp][0] << "</connx>" << endl;
						file << "<conny>" << tab[tmp][1] << "</conny>" << endl;
						file << "<connhz>" << tab[tmp][2] << "</connhz>" << endl;
						file << "</edge>" << endl;
						cout << "<edge from=" << tab[k][3] << " to=" << tab[tmp][3] << " ></edge>" << endl;
						count++;
					}
				}
			}
			else
			{
				if (tmp < k)
				{
					dd = sqrt((tab[k][0] - tab[tmp][0]) * (tab[k][0] - tab[tmp][0]) + (tab[k][1] - tab[tmp][1]) * (tab[k][1] - tab[tmp][1]));
					tmp++;
					if (dd <= (2 * r) && tab[k][2] == tab[tmp][2])
					{
						if (tab[k][3] == tab[tmp][3])
						{
						}
						else
						{
							file << "<edge>" << endl;
							file << "<counter>" << count << "</counter>" << endl;
							file << "<id>" << tab[k][3] << "</id>" << endl;
							file << "<x>" << tab[k][0] << "</x>" << endl;
							file << "<y>" << tab[k][1] << "</y>" << endl;
							file << "<hz>" << tab[k][2] << "</hz>" << endl;
							file << "<connid>" << tab[tmp][3] << "</connid>" << endl;
							file << "<connx>" << tab[tmp][0] << "</connx>" << endl;
							file << "<conny>" << tab[tmp][1] << "</conny>" << endl;
							file << "<connhz>" << tab[tmp][2] << "</connhz>" << endl;
							file << "</edge>" << endl;
							cout << "<edge from=" << tab[k][3] << " to=" << tab[tmp][3] << " ></edge>" << endl;
							count++;
						}
					}
				}
				else if (tmp == k)
				{
					tmp++;
				}
				else if (tmp > k)
				{
					dd = sqrt((tab[k][0] - tab[tmp][0]) * (tab[k][0] - tab[tmp][0]) + (tab[k][1] - tab[tmp][1]) * (tab[k][1] - tab[tmp][1]));
					if (dd <= (2 * r) && tab[k][2] == tab[tmp][2])
					{
						if (tab[k][3] == tab[tmp][3])
						{
						}
						else
						{
							file << "<edge>" << endl;
							file << "<counter>" << count << "</counter>" << endl;
							file << "<id>" << tab[k][3] << "</id>" << endl;
							file << "<x>" << tab[k][0] << "</x>" << endl;
							file << "<y>" << tab[k][1] << "</y>" << endl;
							file << "<hz>" << tab[k][2] << "</hz>" << endl;
							file << "<connid>" << tab[tmp][3] << "</connid>" << endl;
							file << "<connx>" << tab[tmp][0] << "</connx>" << endl;
							file << "<conny>" << tab[tmp][1] << "</conny>" << endl;
							file << "<connhz>" << tab[tmp][2] << "</connhz>" << endl;
							file << "</edge>" << endl;
							cout << "<edge from=" << tab[k][3] << " to=" << tab[tmp][3] << " ></edge>" << endl;
							count++;
						}
					}
					tmp++;
				}
			}
		}
		//cout<<"X: "<< x << " Y: "<< y <<" Hz: "<<hz<< endl;
		k++;
	}

	for(int k =0 ;k < N;k++)
	{
	    cout<<"Pkt: "<<k<<"   X: "<<tab[k][0]<<"     Y: "<<tab[k][1]<<"      Hz: "<<tab[k][2]<<endl;
	}
	file << "</node>" << endl;
	file.close();
	return 0;
}