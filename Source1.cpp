#include<iostream>
#include<ctype.h>	
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]); // ���������� ������ ������
void to_upper(char str[]);	//��������� ������ � ������� �������
void to_lower(char str[]);	//��������� ������ � ������ �������
void capitalize(char str[]);	//������ ����� ������� ����� � ����������� ������ ���������
void shrink(char str[]);	//������� �� ������ ������ �������, ��������: ������        �����    ��   �����       �����-���
							//������ ����� �� ����� �����-���
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);	//����������, �������� �� ������ �����������
bool is_int_number(char str[]);	//����������, �������� �� ������ ����� ������, �� ����, ������� ������ �� ����
int  to_int_number(char str[]);	//���� ������ �������� ������, �� ������� ���������� �������� ����� �����
bool is_bin_number(char str[]); // ����������, �������� �� ������ �������� ������
int  bin_to_dec(char str[]);	//���� ������ �������� �������� ������, �� ������� ���������� ��� ���������� ��������

bool is_hex_number(char str[]) //  ����������, �������� �� ������ ����������������� ������
int  hex_to_dec(char str[]);	//���� ������ �������� ����������������� ������, �� ������� ���������� ��� ���������� ��������
bool is_mac_address(char str[]);	//���������, �������� �� ������ MAC-�������
bool is_ip_address(char str[]);		//���������, �������� �� ������ IP-�������

void main()
{
	setlocale(LC_ALL, "RUS");
	{
		for (int i = 0; i < 256; i++)
		{
			cout << char(i) << "-" << i << " " << endl;
		}
	}

	const int n = 256;
	char str[n];
	cout << "������� ������: ";
	InputLine(str, n);
	cout << str << endl; //CP866
	cout << "����������� ��������:  " << sizeof(str) << endl;
	cout << "����� ��������� ������: " << StrLen(str) << " ��������" << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	capitalize(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	remove_symbol(str, ' ');
	cout << str << endl;
	cout << "������" << (is_palindrome(str) ? "" : "�� ") << "�������� �����������!" << endl;
	cout << str << endl;
	cout << "������" << (is_int_number(str) ? "" : "�� ") << "�������� ������!" << endl;
	cout << str << endl;
	cout << "�������� ��������� �����" << (to_int_number(str) << endl;
	cout << str << endl;
	cout << "������" << (is_bin_number(str) ? "" : "�� ") << "�������� �������� ������!" << endl;
	cout << str << "(bin) = " << bin_to_dec(str) << "(dec)" << endl;
	
	cout << "������" << (is_hex_number(str) ? "" : "�� ") << "�������� ����������������� ������!" << endl;
	cout << str << "(hex) = " << hex_to_dec(str) << "(dec)" << endl;

	cout << "������" << (is_mac_address(str) ? "" : "�� ") << "�������� MAC-�������!" << endl;
	cout << "������" << (is_ip_address(str) ? "" : "�� ") << "�������� IPv4!" << endl;

}
void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}
int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�')
		{
			str[i] -= 32;
		}
		else if (str[i] == '�')str[i] -= 16;
	}

}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '�' && str[i] <= '�')
		{
			str[i] += 32;
		}
		else if (str[i] == '�')str[i] += 16;
	}
}

void capitalize(char str[])
{
	to_lower(str);
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= '�' && str[0] <= '�')str[0] -= 32;
	else if (str[0] == '�')str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�') && str[i - 1] == ' ')str[i] -= 32;
		else if (str[i] == '�' && str[i - 1] == ' ')str[i] -= 16;
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] = 0 || str[0] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1]; n--;
		}
	}
}

bool is_palindrome(char str[])
{
	int n = StrLen(str);
	char* buffer = new char[n + 1]{};
	strcpy_s(buffer, n + 1, str);// �������� ������ str � ������ ����� 
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}
int  to_int_number(char str[])
{
	if (!is_int_number(str))return 0;
	int number = 0; //�������� �����
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			number *= 10; //�������� ����� �� 1 ������ ����� ����� ���������� ������� ������ ��� ��������� ����� 
			number += str[i] - 48; //48 ASCII ��� ������� '0'
		}
	}
	return number;
}
bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}
int  bin_to_dec(char str[])
{
	if (!is_bin_number(str))return 0;
	int n = StrLen(str);
	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	}
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = str[0] == '0' && str[1] == 'x' ? 2 : 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			str[i] != ' '
			)
		{
			return false;
		}
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}
int  hex_to_dec(char str[])
{
	if (!is_hex_number(str))return 0;
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	strcpy(buffer, str);
	to_upper(buffer);

	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (buffer[i] == 'x' || buffer[i] == 'X')break;
		if (buffer[i] != ' ')
		{
			decimal += (buffer[i] - (is_digit(buffer[i]) ? 48 : 55)) * weight;
			weight *= 16;
		}
	}
	return decimal;
}

bool is_ip_address(char str[])
{
	int number = 0, dots = 0; //number - ����� ����� �������; dots - ���������� �����
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') i++; //���� ������, ���� � ���������� �������
		if (str[i] == '.' && str[i + 1] == 0) return false; //���� ��� ���������� ������
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.') return false; //���������� ������� � ������
		if (str[i] != '.') //������� ����� �� �����������
		{
			number *= 10;
			number += str[i] - 48;
		}
		if (number > 255) return false; //����� �� ������ ���� ������ 255
		if (str[i] == '.')
		{
			number = 0;
			dots++;
		}
	}
	if (dots != 3) return false; //�����-������������ ������ ���� ����� 3
	return true;
}

bool is_mac_address(char str[])
{
	int n = strlen(str);
	int numbers = 0, delims = 0; //numbers - ���������� hex ����� �� �����������, delims - ����������� (��������� ��� �����)
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') i++; //���� ������, ���� � ���������� �������
		if ((str[i] == ':' || str[i] == '-') && str[i + 1] == 0) return false; //���� ��� ���������� ������
		if (!(str[i] >= 'A' && str[i] <= 'F') 
			&& !(str[i] >= 'a' && str[i] <= 'f') 
			&& !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != ':' && str[i] != '-') return false; //���������� ������� � ������
		if (str[i] != ':' && str[i] != '-') numbers++; //������� ���-�� hex-����� �� �����������
		if (numbers > 2) return false; //���� ���-�� hex-����� �� ����������� ������ 2-�
		if (str[i] == ':' || str[i] == '-')
		{
			if (numbers == 1 || numbers == 0) return false; //���� ���� hex-����� �� ����������� ��� �� ���
			numbers = 0;
			delims++;
		}
	}
	if (delims != 5) return false; //������������ ������ ���� ����� 5
	return true;
}