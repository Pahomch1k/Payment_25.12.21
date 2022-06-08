#pragma once
#include "Header.h"

struct FIO
{
	string name;
	string surname; 
};

struct DataStart
{
	int day;
	int mounth;
	int year;
};

struct ZP
{
	double nachisleno;
	double uderjano;
};

class Payment
{
	const double nalog_pensiya = 1;
	const double nalog = 13;
	const int kolvo_smen = 15;

	double oklad;
	double procent_nadbavka;
	int year_staj;
	
	int kolvo_otrabotano; 

	ZP zp;
	DataStart start_job;
	FIO name;

public:
	Payment()
	{
		oklad = 0;
		procent_nadbavka = 0; 
		kolvo_otrabotano = 0;
		zp.nachisleno = 0;
		zp.uderjano = 0;
		start_job.day = 0;
		start_job.mounth = 0;
		start_job.year = 0; 
		year_staj = 0;
		name.name = "";
		name.surname = "";
	}

	void Add_in_database();
	void Proschet_zp();
	void Proschet_staja();
	void Proschet_prozenta();
};

