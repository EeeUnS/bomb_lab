#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
int num_input_strings;
char buffer[7][100];
extern FILE* infile;

char* read_line()
{
	if (infile != (FILE*)stdin )
	{
		if (feof(infile))
		{
			fclose(infile);
			infile = stdin;
		}
	}

	fgets(buffer[num_input_strings], 100, infile);
	int i = 0;
	while (buffer[num_input_strings][i] != '\0')
	{
		if (buffer[num_input_strings][i] == '\n') {
			buffer[num_input_strings][i] = '\0';
			break;
		}
		i++;
	}
	return buffer[num_input_strings++];
}

//for phase_5
int array_3597[] = { 0xa,0x2,0xe, 0x7,
0x8, 0xc, 0xf, 0xb,
0x0, 0x4,0x1,0xd,
0x3, 0x9,0x6,0x5 };
//const long long fs0x28 = 0xd854c83f01b41200;

//for phase_6

typedef struct node {
	int num;
	int n;
	struct node* next_node;
}Node;

Node node[] = {
	{0x00000079	,1, &node[1]},
	{0x00000193	,2, &node[2]},
	{0x00000096	,3,&node[3]},
	{0x00000088	,4,&node[4]},
	{0x000000d7	,5,&node[5]},
	{0x000003a9	,6, NULL}
};

void explode_bomb()
{
	puts("\nBOOM!!!");
	puts("The bomb has blown up.");
	exit(8);
}

int string_length(const char* a1)
{
	int size = 0;
	while (*a1 != '\0') {
		a1++;
		size++;
	}
	return size;
}


long long read_six_numbers(char* a1, int a2[])
{
	long long rax; // eax
	rax = sscanf(a1, "%d %d %d %d %d %d", a2, a2 + 1, a2 + 2, a2 + 3, a2 + 4, a2 + 5);
	if ((int)rax <= 5)
	{
		explode_bomb();
	}
	return rax;

}

int strings_not_equal(const char* string1, const char* string2)
{
	assert(strcmp(string1, string2) == 0);
	const char* rbx; // rbx
	const char* rbp; // esi
	int er12; // r12d
	int edx; // eax

	rbx = string1;
	rbp = string2;
	er12 = string_length(string1);
	edx = string_length(string2);
	if (er12 == edx)
	{
		if (*string1)
		{
			if (*string1 == *string2)
			{
				do
				{
					++rbx;
					++rbp;
					if (!*rbp)
					{
						return 0;
					}
				} while (*rbx == *rbp);
				edx = 1;
			}
			else
			{
				edx = 1;
			}
		}
		else
		{
			edx = 0;
		}
	}
	return edx;
}

long long phase_1(char* input)
{
	long long rax = strings_not_equal(input, "When a problem comes along, you must zip it!");
	if (rax)
	{
		explode_bomb();
	}
	return rax;
}

long long phase_2(char* input)
{
	int* rbp; // esi
	int ebx; // ebx
	int rsp[6]; // [rsp_plus0x20+0h] [esi-38h]

	//eax = fs0x28;
	read_six_numbers(input, rsp);
	if (rsp < 0)
	{
		explode_bomb();
	}

	rbp = rsp;
	for (ebx = 1; ebx != 6; ++ebx)
	{
		if (*(rbp + 1) != *rbp + ebx)
		{
			explode_bomb();
		}
		++rbp;
	}
	return 0;
}

long long phase_3(char* input)
{
	int eax = 0; // eax
	unsigned int rsp; // [rsp_plus0x20+0h] [esi-18h]
	int rsp2; // [rsp_plus0x20+4h] [esi-14h]

	if (sscanf(input, "%d %d", &rsp, &rsp2) <= 1)
	{
		explode_bomb();
	}

	switch ((unsigned long long)rsp)
	{
	case 0uLL:
		eax = 770;
		break;
	case 1uLL:
		eax = 860;
		break;
	case 2uLL:
		eax = 421;
		break;
	case 3uLL:
		eax = 855;
		break;
	case 4uLL:
		eax = 421;
		break;
	case 5uLL:
		eax = 421;
		break;
	case 6uLL:
		eax = 957;
		break;
	case 7uLL:
		eax = 945;
		break;
	default:
		explode_bomb();
		return eax = 0;
	}
	if (eax != rsp2)
		explode_bomb();
	return 0;
}


long long func4(int edi, unsigned int esi)
{
	long long rax = esi; // eax
	if (edi <= 0)
	{
		return 0LL;
	}

	if (edi != 1)
	{
		rax = esi + func4((edi - 1), esi) + func4((edi - 2), esi);
	}
	return rax;
}

long long phase_4(char* input)
{
	int rsp;
	int rsp2;
	if ((unsigned int)sscanf(input, "%d %d", &rsp2, &rsp) != 2 || rsp - 2 > 2)
	{
		explode_bomb();
	}
	if (func4(6, rsp) != rsp2)
	{
		explode_bomb();
	}
	return 0;
}



long long phase_5(char* a1)
{
	int edx; // eax
	int ecx; // ecx
	int rsp; // [rsp_plus0x20+0h] [esi-18h]
	int rsp2; // [rsp_plus0x20+4h] [esi-14h]
	int eax;

	if ((int)sscanf(a1, "%d %d", &rsp, &rsp2) <= 1)
	{
		explode_bomb();
	}
	rsp = rsp & 0xF;
	eax = rsp;
	if (rsp == 15)
	{
		goto LABEL_12;
	}

	ecx = 0;
	edx = 0;
	do
	{
		++edx;
		eax = array_3597[eax];
		ecx += eax;
	} while (eax != 15);

	if (edx != 15 || ecx != rsp2)
	{
	LABEL_12:
		explode_bomb();
	}
	return 0;
}

long long phase_6(char* input)
{
	int* r12; // r12
	int r13d; // r13d
	int ebx; // ebx
	Node* edx; // eax
	long long rsi; // rsi
	int ecx; // ecx
	long long* rbx; // rbx
	int eax; // eax
	long long* rax; // eax
	long long* rcx; // rcx
	long long* rdx; // rdx
	int ebp; // ebp
	int rbp[6]; // [rsp_plus0x20+0h] [esi-88h]
	long long rsp_plus0x20[6]; // [rsp_plus0x20+20h] [esi-68h]

	read_six_numbers(input, rbp);
	r12 = rbp;
	
	for(r13d = 0; r13d != 6; ++r13d)
	{
		if ((unsigned int)(*r12 - 1) > 5)
		{
			explode_bomb();
		}

		for (ebx = r13d+1; ebx <= 5; ebx++)
		{
			if (*r12 == rbp[ebx])
			{
				explode_bomb();
			}
		}
		++r12;
	}

	for (rsi = 0LL; rsi != 6; ++rsi)
	{
		ecx = rbp[rsi];
		eax = 1;
		edx = node;
		if (ecx > 1)
		{
			do
			{
				edx = edx->next_node;
				++eax;
			} while (eax != ecx);
		}
		rsp_plus0x20[rsi] = edx->num;
	}

	rbx = rsp_plus0x20;
	rax = rsp_plus0x20;
	rcx = rsp_plus0x20;
	rsi = rsp_plus0x20[5];
	do
	{
		rdx = rax+1;
		*(rcx + 1) = *rdx;
		++rax;
		rcx = rdx;
	} while (*rax != rsi);
	

	for (ebp = 5; ebp; ebp--)
	{
		if (*(rbx) <= *(rbx + 1))
		{
			explode_bomb();
		}
		rbx++;
	}
	return 0;
}




long long __fastcall fun7(int *rdi, int rsi)
{
	long long result; // eax

	if (!rdi)
	{
		return 0xFFFFFFFFLL;
	}
	if (*rdi > rsi)
	{
		return 2 * fun7((rdi + 1), rsi);
	}
	
	result = 0LL;

	if (*rdi != rsi)
	{
		result = 2 * fun7((rdi + 1), rsi) + 1;
	}
	return result;
}



long long secret_phase();

unsigned long long phase_defused()
{
	int v1; // [rsp_plus0x20+8h] [esi-70h]
	int v2; // [rsp_plus0x20+Ch] [esi-6Ch]
	char v3[50]; // [rsp_plus0x20+10h] [esi-68h]

	if (num_input_strings == 6)
	{
		if ((unsigned int)sscanf(buffer[3], "%d %d %s", &v1, &v2, v3) == 3
			&& !(unsigned int)strings_not_equal(v3, "DrEvil"))
		{
			puts("Curses, you've found the secret phase!");
			puts("But finding it and solving it are quite different...");
			secret_phase();
		}
		puts("Congratulations! You've defused the bomb!");
	}
	return 0;
}


long long secret_phase()
{
	const char* v0; // eax
	int v1; // ebx

	v0 = (const char*)read_line();
	v1 = strtol(v0, 0LL, 10);
	if ((unsigned int)(v1 - 1) > 0x3E8)
	{
		explode_bomb();
	}
	if ((unsigned int)fun7(&v1, 0x24))
	{
		explode_bomb();
	}
	puts("Wow! You've defused the secret stage!");
	return phase_defused();
}

