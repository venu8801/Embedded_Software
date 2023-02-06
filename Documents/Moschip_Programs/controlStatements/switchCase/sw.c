void main(){
		unsigned int unum, utemp;
		int i,j;
			printf("Enter the number in hex:");
			scanf("%x",&unum);
			utemp = unum;

			for(i = 0, j = 31; i < j; i++,j--){
				utemp =( (utemp & ~((0x1<<i)|(0x1<<j)) )|( (utemp & (0x1 << i))<<(j-i) )|( (utemp & (0x1<<j))>>(j-i) ) );
			}
			printf("%x\n",utemp);
}
