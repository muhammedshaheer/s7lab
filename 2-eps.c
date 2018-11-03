#include<stdio.h>

int main(){
	
	int t[5][3][5] = {
		{ {1,2,-1}, {-1}, {-1} },
		{ {2,-1} , { 1}, { 2} },
		{ {4,-1} , {1,3}, {4} },
		{ {4,-1}, {-1}, {4} },
		{ {-1}, {3}, {3} }
	};
	
	/* 
		S : Stack to add states
		c : Closure array
		c_ind : Index for the Closure array
		s_top : Stack top
	*/
	
	int S[5], c[5], c_ind, s_top, flag, i, j, k, l, m;
	
	for(i=0; i<5; i++){
	
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
	}
	return 0;
}
