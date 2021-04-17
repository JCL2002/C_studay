#include<stdio.h>
int main(){
	int list[9]={1,2,3,4,5,6,7,8,9},a[9];
	//int *pla=list_a,*plb=list_b,*plc=list_c;
	int i,j,h,l,m,n,o,p,q;//i j h用于循环a b c 用于保存提取的位数 
	for(i=0;i<9;i++){
		a[0]=list[i];//得到(1,1)
		for(j=0;j<9;j++){
			if(j!=i){
				a[1]=list[j];//得到(1,2)
				for(h=0;h<9;h++){
					if(h!=i&&h!=j){
						a[2]=list[h];//得到(1,3)
						for(l=0;l<9;l++){
							if(l!=i&&l!=j&&l!=h){
								a[3]=list[l];//得到(2,1)
								for(m=0;m<9;m++){
									if(m!=i&&m!=j&&m!=h&&m!=l){
										a[4]=list[m];//得到(2,2)
										for(n=0;n<9;n++){
											if(n!=i&&n!=j&&n!=h&&n!=l&&n!=m){
												a[5]=list[n];//得到(2,3)
												for(o=0;o<9;o++){
													if(o!=i&&o!=j&&o!=h&&o!=l&&o!=m&&o!=n){
														a[6]=list[o];//得到(3,1)
														for(p=0;p<9;p++){
															if(p!=i&&p!=j&&p!=h&&p!=l&&p!=m&&p!=n&&p!=o){
																a[7]=list[p];//得到(3,2)
																for(q=0;q<9;q++){
																	if(q!=i&&q!=j&&q!=h&&q!=l&&q!=m&&q!=n&&q!=o&&q!=p){
																		a[8]=list[q];//得到(3,3)
																		if((a[0]*100+a[1]*10+a[2])*2==(a[3]*100+a[4]*10+a[5])){
																			if((a[0]*100+a[1]*10+a[2])*3==(a[6]*100+a[7]*10+a[8])){
																				printf("%d %d %d\n",a[0]*100+a[1]*10+a[2],a[3]*100+a[4]*10+a[5],a[6]*100+a[7]*10+a[8]);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d %d %d %d %d %d %d %d %d",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
	return 0; 
}
