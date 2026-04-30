#include <stdio.h>
#include <windows.h>

void main(void)
{
	typedef enum _COMPUTER_NAME_FORMAT
	{
		ComputerNameNetBIOS,
		ComputerNameDnsHostname,
		ComputerNameDnsDomain,
		ComputerNameDnsFullyQualified,
		ComputerNamePhysicalNetBIOS,
		ComputerNamePhysicalDnsHostname,
		ComputerNamePhysicalDnsDomain,
		ComputerNamePhysicalDnsFullyQualified,
		ComputerNameMax
	} COMPUTER_NAME_FORMAT;

	COMPUTER_NAME_FORMAT CF = ComputerNameDnsDomain;

	char szDomainName[MAX_COMPUTERNAME_LENGTH];

	DWORD dwSize = sizeof(szDomainName);

	//GetComputerName(szDomainName, &dwSize);
	GetComputerNameEx(CF, szDomainName, &dwSize);
}