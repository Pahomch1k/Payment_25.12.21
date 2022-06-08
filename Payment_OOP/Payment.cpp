#include "Payment.h"

void Payment::Add_in_database()
{
	cout << "Name ?";
	cin >> name.name;

	cout << "Surname ?";
	cin >> name.surname;

	cout << "Start working" << endl;
	cout << "day ?";
	cin >> start_job.day;

	cout << "mounth ?";
	cin >> start_job.mounth;

	cout << "year ?";
	cin >> start_job.year;  

	cout << "Oklad za smeny ?";
	cin >> oklad;

	Proschet_staja();
	Proschet_prozenta();
}

void Payment::Proschet_zp()
{
	for (size_t i = 0; i < 100; i++)
	{
		cout << "Kolvo otrabotanix smen?";
		int x = 0;
		cin >> x; 
		if (x < 0 || x > 31) cout << "No" << endl;
		else
		{
			kolvo_otrabotano = x;
			break;
		} 
	} 

	double zpx = oklad * kolvo_otrabotano;
	zp.uderjano = (zpx / 100 * nalog_pensiya) + (zpx / 100 * nalog);
	zp.nachisleno = zpx + (procent_nadbavka * kolvo_otrabotano) - zp.uderjano;

	cout << "Nachisleno " << zp.nachisleno << endl;
	cout << "Uderjano " << zp.uderjano << endl;

}

void Payment::Proschet_staja()
{
	int d = 20;
	int y = 2022;
	int x; 
	x = start_job.mounth * 30 + start_job.day;  
	y -= start_job.year;
	if (x - d >= 250) y++;
	year_staj = y;
	cout << "Your staj" << year_staj << endl;
}

void Payment::Proschet_prozenta()
{  
	procent_nadbavka = ((oklad / 10) * year_staj); 
}
