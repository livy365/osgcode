#include<iostream>
#include<string>
#include<fstream>
#include<vector>


int readtext()
{

	using namespace std;
	ifstream text;
	text.open("read.txt", ios::in);
	vector<double> strVec;
	ofstream readx, readz, readr;
	readx.open("readx.txt", ios_base::out);
	readz.open("readz.txt", ios_base::out);
	readr.open("readr.txt", ios_base::out);
	string g, x, z,f,t;
	x = "300";
	z = "1";
	while (!text.eof())
	{
		string inbuf;
		getline(text, inbuf, '\n');
		if (inbuf.size() != 0) {
			//cout << inbuf << endl;
		}
		auto pd = inbuf.begin();




		for (pd; pd != inbuf.end(); pd++)
		{
			//cout << *pd << endl;

			if (*pd == 'T')
			{
				t.clear();
				pd++;
				while (!(*pd >= 'A' && *pd <= 'Z'))
				{
					//pd++;
					t.push_back(*pd);
					pd++;
					if (pd == inbuf.end())
					{
						//cout << "end"<< endl;
						pd--;
						break;
					}

				}
				try
				{
					double res = stoi(t);
					//cout << "t" << t << endl;
				}
				catch (const std::invalid_argument& e)	// ���� std::invalid_argument �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl; // �����ʲô�쳣
					// some code response to this exception����������
				}
				catch (const std::out_of_range& e)	// ���� std::out_of_range �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl;
					// some code response to this exception����������
				}

			}

			if (*pd == 'G')
			{
				g.clear();
				pd++;
				while (!(*pd >= 'A' && *pd <= 'Z'))
				{
					//pd++;
					g.push_back(*pd);
					pd++;
					if (pd == inbuf.end())
					{
						//cout << "end"<< endl;
						pd--;
						break;
					}

				}
				try
				{
					double res = stoi(g);
					//cout << "g" << g << endl;
				}
				catch (const std::invalid_argument& e)	// ���� std::invalid_argument �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl; // �����ʲô�쳣
					// some code response to this exception����������
				}
				catch (const std::out_of_range& e)	// ���� std::out_of_range �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl;
					// some code response to this exception����������
				}

			}

			if (*pd == 'X')
			{
				x.clear();
				pd++;
				while (!(*pd >= 'A' && *pd <= 'Z'))
				{
					//pd++;
					x.push_back(*pd);
					pd++;
					if (pd == inbuf.end())
					{
						//cout << "end"<< endl;
						pd--;
						break;
					}

				}
				try
				{
					double res = stoi(x);
					//cout << "x" << x << endl;
				}
				catch (const std::invalid_argument& e)	// ���� std::invalid_argument �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl; // �����ʲô�쳣
					// some code response to this exception����������
				}
				catch (const std::out_of_range& e)	// ���� std::out_of_range �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl;
					// some code response to this exception����������
				}

			}



			if (*pd == 'Z')
			{
				z.clear();
				pd++;
				while (!(*pd >= 'A' && *pd <= 'Z'))
				{
					//pd++;
					z.push_back(*pd);
					pd++;
					if (pd == inbuf.end())
					{
						//cout << "end"<< endl;
						pd--;
						break;
					}

				}
				try
				{
					double res = stoi(z);
					//cout << "z" << z << endl;
				}
				catch (const std::invalid_argument& e)	// ���� std::invalid_argument �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl; // �����ʲô�쳣
					// some code response to this exception����������
				}
				catch (const std::out_of_range& e)	// ���� std::out_of_range �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl;
					// some code response to this exception����������
				}

			}

		
			if (*pd == 'F')
			{
				f.clear();
				pd++;
				while (!(*pd >= 'A' && *pd <= 'Z'))
				{
					//pd++;
					f.push_back(*pd);
					pd++;
					if (pd == inbuf.end())
					{
						//cout << "end"<< endl;
						pd--;
						break;
					}

				}
				try
				{
					double res = stoi(f);
					//cout << "f" << f << endl;
				}
				catch (const std::invalid_argument& e)	// ���� std::invalid_argument �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl; // �����ʲô�쳣
					// some code response to this exception����������
				}
				catch (const std::out_of_range& e)	// ���� std::out_of_range �쳣
				{								// ��ʱ�ڶ��쳣���д���
					std::cerr << e.what() << endl;
					// some code response to this exception����������
				}

			}

		}

		if (!text.eof())
		{
			readx << x << endl;
			readz << z << endl;
			readr << t << endl;
		}
		else
		{
			readx << x;
			readz << z;
			readr << t;
		}


	}


	readx.close();
	readz.close();
	readr.close();

	return 0;
}