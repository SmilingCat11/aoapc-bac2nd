// ex3_2uva1586.cpp -- molar mass
#include <stdio.h>
#include <string.h>
#include <ctype.h>
double atom_mass[4] = {12.01, 1.008, 16.00, 14.01};
char s[85];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int atom_num[26] = {};
		double mass = 0;
		scanf("%s", s);
		for (int i = 0; i < strlen(s); i++) {
			if (isalpha(s[i])) {
				if (s[i+1] && isdigit(s[i+1])) {
					if (s[i+2] && isdigit(s[i+2]))
						atom_num[s[i] - 'A'] += 10 * (s[i+1] - '0') + (s[i+2] - '0');
					else 
						atom_num[s[i] - 'A'] += s[i+1] - '0';
				}
				else atom_num[s[i] - 'A']++ ;
			}
		}
		mass = atom_num['C'-'A'] * atom_mass[0] + atom_num['H'-'A'] * atom_mass[1]
			+atom_num['O'-'A'] * atom_mass[2] + atom_num['N'-'A'] * atom_mass[3];
		printf("%.3f\n", mass);
	}
	return 0;
	
}

