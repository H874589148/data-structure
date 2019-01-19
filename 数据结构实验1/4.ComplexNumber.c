/****************************************************

Name:            ComplexNumber.c
Auther:            Hawkeye
Date:           2018.9.25
Function:    calculate complex number 's division
             struct complex divide( struct complex a, struct complex b)

****************************************************/

#include<stdio.h>
#include<math.h>

struct ComplexNumber{
		float Rez;
		float Imz;
}complex[3];

//struct complex divide(struct ComplexNumber complexa,struct ComplexNumber complexb);

struct ComplexNumber divide(struct ComplexNumber complexa,struct ComplexNumber complexb){
	struct ComplexNumber complexc;
	complexc.Rez=(complexa.Rez*complexb.Rez+complexa.Imz*complexb.Imz)/(complexa.Rez*complexa.Rez+complexb.Imz*complexb.Imz);
	complexc.Imz=(complexa.Imz*complexb.Rez-complexa.Rez*complexb.Imz)/(complexa.Rez*complexa.Rez+complexb.Imz*complexb.Imz);
	return complexc;
}

void main(){
	char j[4];
//	struct ComplexNumber *p=complex;
	printf("\nPlease input dividend-----(a+bi)\n");
	scanf("%f%c%f%c",&complex[0].Rez,&j[0],&complex[0].Imz,&j[2]);
	printf("\nPlease input divisor-----(a+bi)\n");
	scanf("%f%c%f%c",&complex[1].Rez,&j[1],&complex[1].Imz,&j[3]);
	if(j[2]-'i'!=0|j[3]-'i'!=0) printf("ERROR!!!");
	else printf("\nThe dividend is --- %.2f %c %.2f * i ;\nThe divisor is ---- %.2f %c %.2f * i ;\n",complex[0].Rez,j[0],complex[0].Imz,complex[1].Rez,j[1],complex[1].Imz);
	if(j[0]=='-') complex[0].Imz=-complex[0].Imz;
	if(j[1]=='-') complex[1].Imz=-complex[1].Imz;
	complex[2]=divide(complex[0],complex[1]);	
	printf("\nThe answer is ---- %.2f %c %.2f * i ;\n",complex[2].Rez,complex[2].Imz>0?'+':' ',complex[2].Imz);

}
