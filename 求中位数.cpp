#include <stdio.h>
#include <stdlib.h>


//求两个等长升序序列合并后的中位数
int M_Search(int A[], int B[], int n) {
	int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1,m2;
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (A[m1] == B[m2])
			return A[m1];
		if (A[m1] < B[m2]) {
			if ((s1 + d1) % 2 == 0) {      //若元素个数为奇数
				s1 = m1;                   //舍弃A中间点以前的部分且保留中间点
				d2 = m2;                   //舍弃B中间点以后的部分且保留中间点
			}
			else {                         //若元素个数为偶数
				s1 = m1 + 1;               //舍弃A中间点及中间点以前的部分
				d2 = m2;                   //舍弃B中间点以后部分且保留中间点
			}
		}else{
			if ((s1 + d1) % 2 == 0){       //若元素个数为奇数
				s1 = m1;				   //舍弃A中间点以后的部分且保留中间点
				d2 = m2;				   //舍弃B中间点以前的部分且保留中间点
			}
			else {                         //若元素个数为偶数
				d1 = m1 + 1;			   //舍弃A中间点以后部分且保留中间点
				s2 = m2;				   //舍弃B中间点及中间点以前的部分
			}
		}
	}
	return A[s1] < B[s2] ? A[s1] : B[s2];
}

int main(int argc ,char *argv[]) {
	int A[3] = { 1,2,3 };
	int B[3] = { 2,5,7 };
	int m = M_Search(A, B, 3);
	printf("%d", m);
}


