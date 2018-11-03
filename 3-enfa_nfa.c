#include<stdio.h>

int main(){
	
	int t[3][3][3] = {
		{ {2,-1}, {1,-1}, {0,-1} },
		{ {-1} , { 2,-1}, { -1} },
		{ {0,-1} , {2,-1}, {-1} }
	};
	
	/* 
		S : Stack to add states
		c : Closure array
		c_ind : Index for the Closure array
		s_top : Stack top
	*/
	
	int S[3], c[3], c_ind, s_top, flag, flaga, flagb, i, j, k, l, m, n;
	int a_ind,b_ind,a[3],b[3];
	
	for(i=0; i<3; i++){
	
		c_ind = 0;
		s_top = 0;
	
		S[s_top] = i;
		s_top = s_top + 1;
		
		c[c_ind] = i;
		c_ind = c_ind + 1;
		
		
		while(s_top != 0){
			s_top = s_top - 1;
			j = S[s_top];
			
			for(k=0; t[j][0][k]!=-1; k++){
				flag=1;
				for(m=0; m<c_ind; m++){
					if(c[m] == t[j][0][k]){
						flag=0;
						break;
					}
				}
				if(flag){
					S[s_top] = t[j][0][k];
					s_top += 1;
				
					c[c_ind] = t[j][0][k];
					c_ind += 1;
				}
			}
		}
		
		printf("\n The e closure of State %d is : { ", i);
		for(k=0; k<c_ind; k++){
			if(k == c_ind - 1) printf("%d ", c[k]);	
			else printf("%d, ", c[k]);		
		}
		printf("}\n");
		
		a_ind=0;
		b_ind=0;
		
		for(m=0;m<c_ind;m++){
			int s;
			s=c[m];
			for(j=1;j<3;j++){
				for(k=0;k<3;k++){
					if(t[s][j][k]==-1){
						break;
					}else{
						if(j==1){
							flaga=1;
							for(n=0; n<a_ind; n++){
								if(a[n] == t[s][j][k]){
									flaga=0;
									break;
								}
							}
							if(flaga){
								a[a_ind]=t[s][j][k];
								a_ind++;
							}
							
						}else if(j==2){
							flagb=1;
							for(n=0; n<b_ind; n++){
								if(b[n] == t[s][j][k]){
									flagb=0;
									break;
								}
							}
							if(flagb){
								b[b_ind]=t[s][j][k];
								b_ind++;
							}
							
						}
					}
				}
			}
		}

		printf(" %d->0  :  ",i);
		for(m=0;m<a_ind;m++){
			printf("%d  ",a[m]);
		}
		printf("\t\t");
		printf(" %d->1  :  ",i);
		for(m=0;m<b_ind;m++){
			printf("%d  ",b[m]);
		}
		printf("\n");

	}

	return 0;
}
